#ifndef BONUS_H
# define BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

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
One node of a circular doubly linked list. The head is the top of the
stack, head->prev is the bottom and bottom->next is the head again.
*/
typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_str_view
{
	char	*content;
	size_t	size;
}			t_view;

char	*get_next_line(int fd);
t_stack	*load_stack(int argc, char **argv, int *count);
t_stack	*build_stack(int *nums, int count);
void	do_operation(char *temp, t_stack *a, t_stack *b, int count);
int	*parse_tokens(char **tokens, int *count);
int	is_operation(char *temp, t_stack *a, t_stack *b, int count);
int	is_sorted(t_stack *a, int size);
void	put_error(void);
void	free_split(char **words);
void	free_stack(t_stack **stack);

/* swap operations */
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

/* rotation operations */
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

/* reverse rotation operations */
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

/* push operations */
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);

#endif
