#include "sudoku_solver.h"

void	ss_populate_matrix(char **argv, int matrix[9][9])
{
	int	i, j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			matrix[i][j] = ss_atoi((const char *)*argv++);
			j++;
		}
		i++;
	}
}

