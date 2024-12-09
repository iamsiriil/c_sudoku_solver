#include "../inc/sudoku_solver.h"

int	ss_check_row(unsigned char **matrix, int row, unsigned char nbr)
{
	for (int i = 0; i < 9; i++)
	{
		if (matrix[row][i] == nbr)
			return (0);
	}
	return (1);
}

int	ss_check_col(unsigned char **matrix, int col, unsigned char nbr)
{
	for (int i = 0; i < 9; i++)
	{
		if (matrix[i][col] == nbr)
			return (0);
	}
	return (1);
}

int	ss_check_sgrid(unsigned char **matrix, int row, int col, int nbr)
{
	int	sg_row = row - (row % 3);
	int	sg_col = col - (col % 3);

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (matrix[i + sg_row][j + sg_col] == nbr)
				return (0);
		}
	}
	return (1);
}

int	ss_checker(unsigned char **matrix, int row, int col, unsigned char nbr)
{
	if (ss_check_row(matrix, row, nbr) == 0)
		return (0);
	if (ss_check_col(matrix, col, nbr) == 0)
		return (0);
	if (ss_check_sgrid(matrix, row, col, nbr) == 0)
		return (0);
	return (1);
}

