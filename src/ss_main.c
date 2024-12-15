#include "../inc/sudoku_solver.h"

int	log_count = 0;

int	main(int argc, char **argv)
{
	LOG_MESSAGE("Start program.");

	if ((argc - 1) != 81)
		exit(EXIT_FAILURE);

	ss_num	**matrix = ss_create_matrix(9);

	ss_parse_input(argc, argv, matrix);

	if (ss_solver_naive(matrix, 0, 0, 9) == 1)
		ss_print_matrix(matrix, 9);

	ss_free_matrix(matrix, 9);

	LOG_MESSAGE("End program.");
	return (EXIT_SUCCESS);
}
