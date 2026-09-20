/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SIMPLE.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duk <duk@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 00:29:34 by duk               #+#    #+#             */
/*   Updated: 2026/09/19 17:29:05 by duk              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	put_top(t_stack **a, int n, int k) //rotates the minimum value to the top of stack a
{
	int	count;

	count = 0;
	if (k < n - k)
	{
		while (count < k)
		{
			ra(a);
			count++;
		}
	}
	else
	{
		while (count < n - k)
		{
			rra(a);
			count++;
		}
	}
}
```
int	list_count(t_stack **a) // counts the nodes in n
{
	int		i;
	t_stack	*node;

	if (*a == NULL)
		return (0);
	i = 1;
	node = *a;
	while (node->next != *a)
	{
		node = node->next;
		i++;
	}
	return (i);
}
```
void	cpy_list(t_stack **a, int *array) // cpy's the stack a elemets to array
{
	int		i;
	t_stack	*node;

	node = *a;
	i = 1;
	array[0] = (*a)->num;
	while (node->next != *a)
	{
		node = node->next;
		array[i] = node->num;
		i++;
	}
}
```
int	scan_min(int *array, int n) //scans the array and returns the position as int k
{
	int	min;
	int	i;
	int	k;

	i = 1;
	min = array[0];
	k = 0;
	while (n > i)
	{
		if (array[i] < min)
		{
			min = array[i];
			k = i;
		}
		i++;
	}
	return (k);
}
```
int	shift_elem(int *array, int n, int k) //shifts the elements and reduces n to acount for the removed elem
{
	int	i;

	i = 0;
	while (n - 1 - k > i) //removes the value from the track and shifts the right elements to the left and re adjusts the original array
	{
		array[k + i] = array[k + i + 1];
		i++;
	}
	n = n - 1;
	return (n);
}
```
void	simple_sort(t_stack **a, t_stack **b)
{
	int	k;
	int	n;
	int	*array;

	n = list_count(a);
	array = ft_calloc (n, sizeof(int));
	if (array == NULL)
	{
		//DIMA WHAT DO I DO???
		return ;
	}
	cpy_list(a, array);
	while (n > 0)
	{
		k = scan_min(array, n);
		put_top(a, n, k);
		pb(a, b); // pushes the top node to the head of the stack b
		n = shift_elem(array, n, k);
	}
	free(array);
	while ((*b) != NULL)
	{
		pa(a, b);
	}
}
```