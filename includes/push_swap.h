#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"

typedef struct	s_stack
{
	int		*num;
	struct s_stack	*next;
	struct s_stack	*prev;
}			t_stack;

#endif
