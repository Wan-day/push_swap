*This project has been created as part of the 42 curriculum by dboldino, dgankhuy.*

# push_swap

## Description

**push_swap** is a sorting project. Given a list of unique integers, the program
must print the shortest sequence of instructions it can find that sorts them,
using only two stacks (`a` and `b`) and a fixed set of eleven operations.

The goal is not just to sort the numbers, but to sort them with as **few
operations as possible**. Since no single algorithm is best for every input,
this implementation ships four strategies and lets the user pick one, or let
the program choose by measuring how disordered the input is.

### Overview

- Stack `a` starts with all the numbers (the first argument is the top). Stack
  `b` starts empty.
- The goal is for `a` to end up sorted in ascending order, with the smallest
  number on top and `b` empty.
- The program writes one operation per line on **stdout**.
- Four strategies: `--simple` (O(n²)), `--medium` (O(n√n)), `--complex`
  (O(n log n)) and `--adaptive` (default, picks one of the three).
- `--bench` prints statistics (disorder, strategy, operation counts) on
  **stderr**, so they never pollute the list of operations.
- A **bonus** `checker` program reads the operations from stdin, applies them
  and answers `OK` or `KO`.
- `libft` and `ft_printf` are included in the repository and built
  automatically.

### Allowed operations

| Operation | Effect |
| --------- | ------ |
| `sa` / `sb` / `ss` | Swap the first two elements of `a` / `b` / both |
| `pa` | Move the top element of `b` onto the top of `a` |
| `pb` | Move the top element of `a` onto the top of `b` |
| `ra` / `rb` / `rr` | Rotate `a` / `b` / both: the top element goes to the bottom |
| `rra` / `rrb` / `rrr` | Reverse rotate `a` / `b` / both: the bottom element goes to the top |

## Instructions

### Compilation

The project is compiled with `cc -Wall -Wextra -Werror`.

```bash
make          # builds ./push_swap (and libft / ft_printf)
make bonus    # builds ./checker
make both     # builds both programs
```

| Target | Action |
| ------ | ------ |
| `make clean` / `make fclean` / `make re` | Clean, full clean, rebuild `push_swap` |
| `make b_clean` / `make b_fclean` / `make b_re` | Same, for the `checker` |
| `make clean_all` / `make fclean_all` | Same, for both programs |

### Execution

```bash
./push_swap [--simple | --medium | --complex | --adaptive] [--bench] <numbers>
```

- Numbers can be given as separate arguments (`./push_swap 3 2 1`) or inside a
  single quoted string (`./push_swap "3 2 1"`).
- At most one strategy flag is accepted. Without one, `--adaptive` is used.
- No arguments: the program does nothing. Already sorted input: nothing is
  printed.
- Non-numeric values, values outside the `int` range, duplicates or unknown
  options make the program print `Error` on stderr and exit with status 1.

**Examples**

```bash
./push_swap 2 1 3
./push_swap --complex --bench 5 4 3 2 1
ARG=$(shuf -i 1-10000 -n 100 | tr '\n' ' ')
./push_swap $ARG | wc -l           # number of operations
./push_swap $ARG | ./checker $ARG  # OK / KO
```

`--bench` output (stderr) looks like this:

```
[bench] disorder: 50.24%
[bench] strategy: Adaptive
[bench] total_ops: 1084
[bench] sa: 0 sb: 0 ss: 0 pa: 384 pb: 384
[bench] ra: 316 rb: 0 rr: 0 rra: 0 rrb: 0 rrr: 0
```

### Checker (bonus)

```bash
./checker <numbers>      # then type operations on stdin, finish with Ctrl+D
```

The checker reads one operation per line, applies them to the stack built from
its arguments, then prints `OK` if `a` is sorted and `b` is empty, `KO`
otherwise. An unknown operation or invalid arguments print `Error` on stderr.

### Project structure

```
.
├── Makefile
├── includes/push_swap.h        # types, prototypes
├── main/
│   ├── main.c                  # entry point
│   ├── operations/             # sa sb ss pa pb ra rb rr rra rrb rrr
│   ├── sorting/                # simple_sort.c, medium_sort.c, complex_sort.c
│   └── utils/                  # parsing, options, disorder, ranks, bench
├── bonus/                      # checker + get_next_line
├── libft/
└── ft_printf/
```

## Algorithms

### Data structure

Each stack is a **circular doubly linked list**. The head is the top of the
stack, `head->prev` is the bottom. This makes every operation O(1): a rotation
only moves the head pointer, a reverse rotation moves it backwards, and push /
swap only relink a few nodes. No array shifting is ever needed.

### Preprocessing

- **Validation**: each token is converted with overflow checking, so values
  outside the `int` range are rejected. Duplicates are detected before any
  sorting starts.
- **Ranks**: every number is given a rank (how many values are smaller than
  it), which maps the input onto `0 … n-1`. Only the radix sort needs this, but
  it is computed for all strategies. Cost: O(n²), negligible compared with the
  number of operations printed.
- **Disorder metric**: the fraction of pairs `(i, j)` with `i < j` and
  `a[i] > a[j]` (inversions) over all `n(n-1)/2` pairs. `0.0` is a sorted
  stack, `1.0` a reversed one, and a random permutation is around `0.5`. It is
  computed once, before sorting, and drives the adaptive strategy.

### Simple: selection sort, O(n²)

**How it works.** Repeat n times: find the smallest value left in `a`, rotate
`a` until it is on top (with `ra` or `rra`, whichever direction is shorter),
and `pb` it. Since the smallest values go into `b` first, the largest ends on
top of `b`. Pushing everything back with `pa` then leaves `a` sorted ascending.

**Cost.** Scanning is O(n) per round, and each round needs at most n/2
rotations, so the total is O(n²) operations, plus a fixed 2n for the pushes.

**Why it is here.** It is the simplest to reason about and it behaves well when
the input is nearly sorted: the next smallest value is already at, or close to,
the top, so rotations are few. It is a poor choice on random data of any size
(see the benchmarks below), which is why it is only selected automatically for
low disorder.

### Medium: chunk sort, O(n√n)

**How it works.**

1. Cut the value range `[min, max]` into `⌈√n⌉` equal slices (chunks).
2. For each chunk, in ascending order, make one pass over `a`: if the top
   value belongs to the current chunk, insert it into `b` at its sorted
   position (rotating `b` the shorter way with `rb` / `rrb`, then `pb`);
   otherwise `ra` to move on.
3. When `a` is empty, rotate `b` so its maximum is on top and `pa` everything
   back. Since `b` was kept sorted, `a` ends up ascending.

**Cost.** There are √n passes over `a`, each costing at most n rotations:
O(n√n). The insertions into `b` would be O(n) each if `b` were arbitrary, but
chunks are processed from the smallest values to the largest, so the values of
the current chunk always land in the top region of `b`, within about √n
positions of the top. Each insertion therefore costs O(√n) rotations, and the
total stays O(n√n).

**Why it is here.** It fills the gap between the quadratic and the `n log n`
strategies: much cheaper than selection sort on medium disorder, without the
fixed `log n` passes of radix sort. The trade-off is that chunks are equal in
**value range**, not in number of elements, so very unevenly distributed
values give unevenly sized chunks.

### Complex: LSD binary radix sort, O(n log n)

**How it works.** Work on the ranks (`0 … n-1`), which need `⌈log₂ n⌉` bits.
For each bit, from the least significant to the most significant, go through
all n elements of `a`: if the bit is `1`, `ra` (keep it in `a`), if it is `0`,
`pb`. Then `pa` everything back from `b`. Each pass is a stable partition by
one bit, so after the last bit the stack is sorted.

**Cost.** Each pass costs n operations (one `ra` or `pb` per element) plus
about n/2 `pa`, i.e. roughly 1.5n. With `⌈log₂ n⌉` passes the total is
`≈ 1.5 · n · log₂ n`, which is O(n log n). The count depends only on `n`, not
on the input order, which makes it predictable.

**Why it is here.** Radix sort needs no comparisons between elements, only bit
tests, which fits the two-stack model very well: the only "decision" is `ra` or
`pb`. Working on ranks instead of raw values keeps the number of passes at
`log₂ n` even for huge or negative numbers.

### Adaptive: choosing by disorder

| Disorder | Strategy | Reasoning |
| -------- | -------- | --------- |
| `< 0.2` | Simple | Few inversions: the next minimum is near the top, rotations are cheap |
| `0.2 … < 0.5` | Medium | Partially ordered input: chunking pays off |
| `≥ 0.5` | Complex | Close to random or reversed: the predictable O(n log n) wins |

The thresholds are a compromise. A random permutation has a disorder of about
0.5, so random inputs sit right on the boundary between medium and complex, and
which one is picked can vary from run to run.

### Sample results

One random run per cell (numbers change with every input), operation counts
verified with the bonus checker:

| n | `--simple` | `--medium` | `--complex` |
| --- | --- | --- | --- |
| 100 | 1473 | 838 | 1084 |
| 500 | 32222 | 8496 | 6784 |

At 100 elements the chunk sort is the cheapest; at 500 the radix sort takes
over and selection sort is far behind, as the complexities predict.

## Resources

### References

- [Selection sort](https://en.wikipedia.org/wiki/Selection_sort): basis of the simple strategy
- [Radix sort](https://en.wikipedia.org/wiki/Radix_sort): LSD radix sort used by the complex strategy
- [Bucket sort](https://en.wikipedia.org/wiki/Bucket_sort) and [Insertion sort](https://en.wikipedia.org/wiki/Insertion_sort): ideas behind the chunk strategy
- [Inversion (discrete mathematics)](https://en.wikipedia.org/wiki/Inversion_(discrete_mathematics)): the disorder metric
- [Time complexity](https://en.wikipedia.org/wiki/Time_complexity) and [Sorting algorithm](https://en.wikipedia.org/wiki/Sorting_algorithm): complexity analysis and comparison
- [Doubly linked list](https://en.wikipedia.org/wiki/Doubly_linked_list) and [Stack (abstract data type)](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))
- [GNU Make manual](https://www.gnu.org/software/make/manual/make.html)
- The push_swap subject and the 42 Norm, provided by the curriculum

### AI Usage

- AI was used as a development and documentation aid for this project. The source code itself remains the responsibility of the project author. AI was not used as a substitute for understanding the implementation or for validating the behaviour of the submitted code.
