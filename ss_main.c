#include "sudoku_solver.h"

int	log_count = 0;

int	main(int argc, char **argv)
{
	LOG_MESSAGE("Start program.");
	(void)argc;
	(void)argv;
	unsigned char	**matrix = ss_create_matrix(9);
	ss_print_matrix(matrix, 9);
	ss_free_matrix(matrix, 9);

	LOG_MESSAGE("End program.");
		
	return (EXIT_SUCCESS);
}
