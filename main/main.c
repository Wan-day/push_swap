#include "push_swap.h"

/*
Program entry point.
1. Read the options and the numbers and build stack a (load_stack).
   No numbers means nothing to do: exit silently.
2. Record the strategy and the initial disorder for the benchmark.
3. Sort stack a only if it is not already sorted.
4. Print the benchmark on stderr if --bench was given.
5. Free both stacks.
*/
int	main(int argc, char **argv)
{
	t_options	opts;
	t_bench		bench;
	t_stack		*a;
	t_stack		*b;
	int			count;

	if (argc < 2)
		return (0);
	ft_bzero(&opts, sizeof(opts));
	ft_bzero(&bench, sizeof(bench));
	opts.strategy = ADAPTIVE;
	a = load_stack(argc, argv, &opts, &count);
	if (a == NULL)
		return (0);
	b = NULL;
	bench.strategy = opts.strategy;
	bench.disorder = calculate_disorder(a, count);
	assign_ranks(a, count);
	if (!is_sorted(a, count))
		sort_stack(&a, &b, &bench, count);
	if (opts.bench)
		print_benchmark(&bench);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
