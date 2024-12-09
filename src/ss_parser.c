#include "../inc/sudoku_solver.h"

int	ss_test_input(int argc, char **argv)
{
	for (int i = 1; i < (argc - 1); i++) {
		if (!ss_isdigit((int)argv[i][0]) && argv[i][1] != '\0')
			return (0);
		i++;
	}

	return (1);
}

void	ss_parse_input(int argc, char **argv, unsigned char **matrix)
{
	if (!ss_test_input(argc, argv))
		exit(EXIT_FAILURE);
	else
		ss_populate_matrix(argv, matrix);
}
