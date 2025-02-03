#include "../inc/sudoku_solver.h"

int	log_count = 0;

int	main(int argc, char **argv) {

	LOG_MESSAGE("Start program.");
	int sz = 0;

	switch (argc) {
		case 2:
			break;
		case 82:
			break;
		case 257:
			break;
		default:
			printf("error: argc : %d\n", argc);
			exit(EXIT_FAILURE);
	}

	t_grid *gr = malloc(sizeof(t_grid));
	if (!gr) {
		perror("Failed to allocate memory for grid structure.");
		exit(EXIT_FAILURE);
	}
	ss_parse_file(gr, argv[1]);
	if (ss_solver_naive(gr, 0, 0) == true)
		ss_print_grid(gr);

	ss_free_grid(gr);
	
	return EXIT_SUCCESS;
}
