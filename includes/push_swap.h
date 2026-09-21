#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft.h"
# include "ft_printf.h"

/*
Every operation the program can perform. OP_COUNT is not a real
operation: it equals the total number of operations (11) and is
used to size the op_count array of t_bench.
*/
typedef enum e_op
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR,
	OP_COUNT
}	t_op;

/*
Sorting strategies selectable from the command line.
BENCH is only a marker used to identify the --bench flag.
*/
typedef enum e_strategy
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE,
	BENCH
}	t_strategy;

/*
One node of a circular doubly linked list. The head is the top of the
stack, head->prev is the bottom and bottom->next is the head again.
*/
typedef struct s_stack
{
	int				num;
	int				rank;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

/*
Command line options.
strategy:     strategy chosen by the user (ADAPTIVE by default).
strategy_set: 1 once a strategy flag was read. Basically a bool.
bench:        1 if --bench was given. Basically a bool.
*/
typedef struct s_options
{
	int	strategy;
	int	strategy_set;
	int	bench;
}	t_options;

/*
Values printed by --bench.
disorder:  initial disorder, between 0.0 (sorted) and 1.0 (reversed).
strategy:  strategy used to sort.
total_ops: number of operations printed.
op_count:  number of times each operation was used, indexed by t_op.
*/
typedef struct s_bench
{
	double	disorder;
	int		strategy;
	int		total_ops;
	int		op_count[OP_COUNT];
}	t_bench;

/* main_utils_1.c: stack construction */
t_stack	*build_stack(int *nums, int count);
t_stack	*load_stack(int argc, char **argv, t_options *opts, int *count);

/* main_utils_2.c: command line options */
char	**extract_options(int argc, char **argv, t_options *opts);

/* main_utils_3.c: parsing and validation of the numbers */
int		*parse_tokens(char **tokens, int *count);

/* main_utils_4.c: disorder computation, sorted check and sorting */
double	calculate_disorder(t_stack *a, int size);
int		is_sorted(t_stack *a, int size);
void	sort_stack(t_stack **a, t_stack **b, t_bench *bench, int size);

/* bench_utils_1.c: --bench output */
void	print_benchmark(t_bench *bench);

/* helper_utils_1.c: error handling and cleanup */
void	put_error(void);
void	free_split(char **words);
void	free_stack(t_stack **stack);

#endif
