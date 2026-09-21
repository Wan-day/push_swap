#include "push_swap.h"

/*
Converts str to an int. Accepts an optional sign followed by at least
one digit and nothing else. Returns 1 and writes the value in *out on
success. Returns 0 (and leaves *out untouched) if str is not a number
or does not fit in an int. The value is accumulated in a long and
checked after every digit, so it can never overflow.
*/
static int	str_to_int(char *str, int *out)
{
	long	n;
	int		sign;

	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (*str == '\0')
		return (0);
	n = 0;
	while (ft_isdigit(*str))
	{
		n = n * 10 + (*str - '0');
		if (n * sign > INT_MAX || n * sign < INT_MIN)
			return (0);
		str++;
	}
	if (*str != '\0')
		return (0);
	*out = (int)(n * sign);
	return (1);
}

/*
Counts every number found in tokens. A token can hold several numbers
separated by spaces ("3 2 1"). A token that holds none ("" or "  ") is
an error.
*/
static int	count_numbers(char **tokens)
{
	char	**words;
	int		total;
	int		n;
	int		i;

	total = 0;
	i = 0;
	while (tokens[i])
	{
		words = ft_split(tokens[i], ' ');
		if (words == NULL)
			put_error();
		n = 0;
		while (words[n])
			n++;
		free_split(words);
		if (n == 0)
			put_error();
		total += n;
		i++;
	}
	return (total);
}

/*
Splits one token, validates every word and stores the numbers in nums,
starting at position *idx (which is advanced). On any error, frees what
this function and nums own, then exits with "Error".
*/
static void	fill_from_token(char *token, int *nums, int *idx)
{
	char	**words;
	int		i;

	words = ft_split(token, ' ');
	if (words == NULL)
	{
		free(nums);
		put_error();
	}
	i = 0;
	while (words[i])
	{
		if (!str_to_int(words[i], &nums[*idx]))
		{
			free_split(words);
			free(nums);
			put_error();
		}
		(*idx)++;
		i++;
	}
	free_split(words);
}

/* Returns 1 if a value appears more than once in nums, 0 otherwise. */
static int	has_duplicates(int *nums, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (nums[i] == nums[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/*
Turns the NULL terminated array of number tokens into an array of ints.
*count receives the amount of numbers. Every token can hold one or
several numbers. Exits with "Error" on a non numeric value, a value
outside the int range, or a duplicate. tokens must hold at least one
token. The returned array is allocated: the caller frees it.
*/
int	*parse_tokens(char **tokens, int *count)
{
	int	*nums;
	int	i;
	int	idx;

	*count = count_numbers(tokens);
	nums = ft_calloc(*count, sizeof(int));
	if (nums == NULL)
		put_error();
	i = 0;
	idx = 0;
	while (tokens[i])
	{
		fill_from_token(tokens[i], nums, &idx);
		i++;
	}
	if (has_duplicates(nums, *count))
	{
		free(nums);
		put_error();
	}
	return (nums);
}
