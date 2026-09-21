#include "bonus.h"

int	main(int argc, char **argv)
{
	t_stack *a;
	t_stack	*b;
	int		count;
	char	*temp;

	if (argc < 2)
		return (0);
	a = load_stack(argc, argv, &count);
	b = NULL;
	if (a == NULL)
		return (0);
	temp = get_next_line(0);
	while (temp != NULL)
	{
		do_operation(temp, &a, &b, count);
		temp = get_next_line(0);
	}
	if (is_sorted(a, count))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(&a);
	free_stack(&b);
	return (0);
}
