#include "../inc/cns_ssolver.h"

int	log_count = 0;

int	main(int argc, char **argv) {

	t_grid *gr = cns_parse_arguments(argc, argv);

	if (cns_solver_naive(gr, 0, 0) == true)
		cns_print_grid(gr);

	cns_free_grid(gr);
	
	return EXIT_SUCCESS;
}

