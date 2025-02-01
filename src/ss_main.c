#include "../inc/sudoku_solver.h"

int	log_count = 0;

int	main(int argc, char **argv) {

	LOG_MESSAGE("Start program.");

	int sz = 0;
	switch (argc) {
		case 3:
			// parse_file
			printf("parse_file\n");
			break;
		case 82:
			// parse_input 9x9
			printf("parse_input | size : %dx%d\n", SS_9X9, SS_9X9);
			sz = SS_9X9;
			break;
		case 257:
			// parse_input 16x16
			printf("parse_input\n");
			sz = SS_16X16;
			break;
		default:
			printf("error: argc : %d\n", argc);
			exit(1);
	}

	printf("size : %d\n", sz);
	t_grid g = {sz, sz};

//	ss_num	**matrix = ss_create_matrix(9);
//
//	ss_parse_input(argc, argv, matrix);
//
//	if (ss_solver_naive(matrix, 0, 0, 9) == 1)
//		ss_print_matrix(matrix, 9);
//
//	ss_free_matrix(matrix, 9);
//
//	LOG_MESSAGE("End program.");
//	return (EXIT_SUCCESS);
}
