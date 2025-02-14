#include "../inc/sudoku_solver.h"

int	log_count = 0;

int	main(int argc, char **argv) {

	LOG_MESSAGE("Function call.");

	t_grid *gr = parse_arguments(argc, argv);

	if (solver_naive(gr, 0, 0) == true)
		print_grid(gr);

	free_grid(gr);
	
	return EXIT_SUCCESS;
}

