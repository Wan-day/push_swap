#include "push_swap.h"

/*
Returns 1 and raises the bench flag if str is "--bench".
Returns 0 if str is another string, or if the flag was already given
(a repeated flag is then handled as an invalid number by the parser).
*/
static int	is_bench(char *str, t_options *opts)
{
	if (opts->bench || ft_strncmp(str, "--bench", 8) != 0)
		return (0);
	opts->bench = 1;
	return (1);
}

/*
Returns 1 and stores the strategy if str is --simple, --medium,
--complex or --adaptive. Only one strategy flag is accepted: once
strategy_set is raised, any other strategy flag returns 0.
The length given to ft_strncmp includes the '\0', so the whole string
has to match, not just its beginning.
*/
static int	is_strategy(char *str, t_options *opts)
{
	if (opts->strategy_set)
		return (0);
	if (ft_strncmp(str, "--simple", 9) == 0)
		opts->strategy = SIMPLE;
	else if (ft_strncmp(str, "--medium", 9) == 0)
		opts->strategy = MEDIUM;
	else if (ft_strncmp(str, "--complex", 10) == 0)
		opts->strategy = COMPLEX;
	else if (ft_strncmp(str, "--adaptive", 11) == 0)
		opts->strategy = ADAPTIVE;
	else
		return (0);
	opts->strategy_set = 1;
	return (1);
}

/* Returns 1 if str is an accepted option (--bench or a strategy). */
static int	is_option(char *str, t_options *opts)
{
	if (is_bench(str, opts))
		return (1);
	return (is_strategy(str, opts));
}

/*
Splits argv into options and numbers.
The options found are recorded in opts. Every other argument is copied,
in order, into a NULL terminated array that is returned (the caller
frees the array, not the strings, which still belong to argv).
argv[0] is the program name and is skipped.
*/
char	**extract_options(int argc, char **argv, t_options *opts)
{
	char	**res;
	int		i;
	int		j;

	res = ft_calloc(argc + 1, sizeof(char *));
	if (res == NULL)
		put_error();
	i = 1;
	j = 0;
	while (i < argc)
	{
		if (!is_option(argv[i], opts))
		{
			res[j] = argv[i];
			j++;
		}
		i++;
	}
	return (res);
}
