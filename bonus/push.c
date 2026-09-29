#include "bonus.h"

static t_stack	*rmv_top(t_stack **s1)
{
	t_stack	*x;
	t_stack	*y;
	t_stack	*tmp;
	int		check;

	if ((*s1) == NULL)
		return (NULL);
	tmp = *s1;
	check = ((*s1)->next == (*s1));
	x = (*s1)->prev;
	y = (*s1)->next;
	x->next = y;
	y->prev = x;
	if (check == 0)
		*s1 = y;
	else
		*s1 = NULL;
	return (tmp);
}

static void	ins_top(t_stack *node, t_stack **s2)
{
	t_stack	*prev_node;

	if ((*s2) == NULL)
	{
		*s2 = node;
		node->next = node;
		node->prev = node;
	}
	else
	{
		prev_node = (*s2)->prev;
		node->next = (*s2);
		node->prev = prev_node;
		(*s2)->prev = node;
		prev_node->next = node;
		(*s2) = node;
	}
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = rmv_top(b);
	if (tmp == NULL)
		return ;
	ins_top (tmp, a);
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = rmv_top(a);
	if (tmp == NULL)
		return ;
	ins_top (tmp, b);
}
