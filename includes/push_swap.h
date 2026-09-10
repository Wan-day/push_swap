#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>
# include "ft_printf.h"

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
    OP_COUNT   // not a real operation — just equals to the total number of operations (11)
}   t_op;

typedef enum s_strategy
{
    SIMPLE,
    MEDIUM,
    COMPLEX,
    ADAPTIVE
}   t_strategy;

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_options
{
    t_strategy	strategy;
    int			strategy_set;
    int			bench;
}   t_options;

typedef enum s_strategy
{
    SIMPLE,
    MEDIUM,
    COMPLEX,
    ADAPTIVE
}   t_strategy;

typedef struct s_bench
{
	double		disorder;
	t_strategy	strategy;
	int			total_ops; 
	int			op_count[OP_COUNT];
}	t_bench;

#endif
