#include "../inc/sudoku_solver.h"

int	log_count = 0;

int	main(int argc, char **argv) {

	LOG_MESSAGE("Start program.");
	int sz = 0;

	switch (argc) {
		case 3:
			printf("parse_file\n");
			break;
		case 82:
			printf("parse_input | size : %dx%d\n", SS_9X9, SS_9X9);
			sz = SS_9X9;
			break;
		case 257:
			printf("parse_input\n");
			sz = SS_16X16;
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
	gr->x = sz;
	gr->y = sz;	
	gr->g = ss_create_grid(gr->x, gr->y);
	if (gr->g == NULL) {
		perror("Failed to create grid.");
		free(gr);
		exit(EXIT_FAILURE);
	}

	ss_print_grid(gr);
	ss_free_grid(gr);
	
	return EXIT_SUCCESS;
}
