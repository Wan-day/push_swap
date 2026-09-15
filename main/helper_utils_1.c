void	put_error()
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

void	set_strategy(t_bench *bench, t_options *opts, int strategy)
{
	if (opts->strategy_set == 0 && strategy != BENCH)
	{
		opts->strategy = strategy;
		bench->strategy = strategy;
		opts->strategy_set = 1;
	}
	else if (strategy == BENCH)
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

int is_options(char *str, t_bench *bench, t_options *opts)
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

char	**extract_options(int argc, char **argv, t_options *opts, int *remaining, t_bench *bench)
{
	int		i;
	int		j;
	char	*res[remaining];

	i = 1;
	j = 0;
	if (argc < 2)
		return (NULL);
	while (i < argc)
	{
		if (is_bench(argv[i], bench, opts) && opts->bench == 0)
		{
			argv[i] = NULL;
			remaining--;
		}
		else if ((argv[i] != NULL) && is_options(argv[i], bench, opts))
		{
			argv[i] = NULL;
			remaining--;
		}
		else
		{
			res[j] = argv[i];
			j++;
		}
		i++;
	}
	return (res);
}
