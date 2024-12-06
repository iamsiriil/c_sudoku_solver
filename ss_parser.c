#include "sudoku_solver.h"

int	ss_test_input(char **argv)
{
	int i;

	i = 1;
	while (i < 82)
	{
		if (!ss_isdigit((int)argv[i][0]))
			return (0);
		if (argv[i][1] != '\0')
			return (0);
		i++;
	}
	return (1);

}

void	ss_parse_input(char **argv, int matrix[9][9])
{
	if (!ss_test_input(argv))
		exit(EXIT_FAILURE);
	else
		ss_populate_matrix((argv + 1), matrix);
}
