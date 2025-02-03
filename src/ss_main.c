#include "../inc/sudoku_solver.h"

int	log_count = 0;

int	main(int argc, char **argv) {

	t_grid *gr = ss_parse_arguments(argc, argv);

	if (ss_solver_naive(gr, 0, 0) == true)
		ss_print_grid(gr);

	ss_free_grid(gr);
	
	return EXIT_SUCCESS;
}

