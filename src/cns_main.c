#include "../inc/sudoku_solver.h"

int	log_count = 0;

int	main(int argc, char **argv) {

	LOG_MESSAGE("Function call.");

	t_grid *gr = cns_parse_arguments(argc, argv);

	if (cns_solver_naive(gr, 0, 0) == true)
		cns_print_grid(gr);

	cns_free_grid(gr);
	
	return EXIT_SUCCESS;
}

