void	set_strategy(t_bench *bench, t_options *opts, int strategy)
{
	if (opts->strategy_set == 0 && strategy >= SIMPLE && strategy <= ADAPTIVE)
	{
		opts->strategy = strategy;
		bench->strategy = strategy;
		opts->strategy_set = 1;
	}
	else if (opts->bench == 0 && strategy == BENCH)
		opts->bench = 1;
}

int is_bench(char *str, t_bench *bench, t_options *opts)
{
	if (ft_strcmp(str, "--bench") == 0)
	{
		set_strategy(bench, opts, BENCH);
		return (1);
	}
	return (0);
}

int is_strategy(char *str, t_bench *bench, t_options *opts)
{
	if (ft_strcmp(str, "--simple") == 0)
	{
		set_strategy(bench, opts, SIMPLE);
		return (1);
	}
	else if (ft_strcmp(str, "--medium") == 0)
	{
		set_strategy(bench, opts, MEDIUM);
		return (1);
	}
	else if (ft_strcmp(str, "--complex") == 0)
	{
		set_strategy(bench, opts, COMPLEX);
		return (1);
	}
	else if (ft_strcmp(str, "--adaptive") == 0)
	{
		set_strategy(bench, opts, ADAPTIVE);
		return (1);
	}

	return (0);
}

int	is_options(char	*str, t_bench *bench, t_options *opts)
{
	if (opts->bench == 0 && is_bench(str, bench, opts))
		return (1);
	else if (opts->strategy_set == 0 && is_strategy(str, bench, opts))
		return (1);
	else
		return (0);
}

char	**extract_options(int argc, char **argv, t_options *opts, int *remaining, t_bench *bench)
{
	int		i;
	int		j;
	char	res[argc];

	ft_bzero(res, sizeof(res));
	*remaining = argc;
	i = 1;
	j = 0;
	if (argc < 2)
		return (NULL);
	while (i < argc)
	{
		if (is_options(argv[i], bench, opts))
			(*remaining)--;
		else
		{
			res[j] = argv[i];
			j++;
		}
		i++;
	}
	return (&res);
}
