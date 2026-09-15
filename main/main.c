#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_options   opts;       // Will hold strategy + bench settings, filled in by extract_options
	t_bench		bench;		// Will hold values needed for --bench option.
	int         remaining;  // Will hold how many tokens are left after flags are stripped out
	char        **tokens;   // Array of strings — the argv tokens that are numbers, not flags
	int         *nums;      // Array of actual parsed integers
	int         count;      // How many integers are in nums
	t_stack     *a;         // Pointer to stack A (the linked list, head node)
	t_stack     *b;         // Pointer to stack B, starts as NULL (empty)
	
	// Zero the structs so that the values inside are accessible.
	ft_bzero(&bench, sizeof(bench));
	ft_bzero(&opts, sizeof(opts));

	// Parses the arguments and extracts options if any are present. 
	// Sets strategy for opts and bench.
    tokens = extract_options(argc, argv, &opts, &remaining, &bench); 

	// Parses and validates the number tokens:w:.
    nums = parse_tokens(tokens, remaining, &count); 
	if (!nums)
		return (put_error(), 1);

	// Builds the main stack from the number tokens. ALSO calculates disorder.
	a = build_stack(nums, count); // First arg = top of stack, per subject
	free(nums);
	b = NULL;

	// Checks if the stack is sorted and if not - calls the sorting funtcion. 
	// Adds operations count to bench.
	if (!is_sorted(a))
		sort_stack(&a, &b, opts.strategy, &bench);

	// Prints benchmark if asked for by the option.
	if (opts.bench)
		print_benchmark(bench);

	// DONT FORGET TO FREE BOTH STACKS.
	free_stack(&a);
	free_stack(&b);
    return (0);
}
