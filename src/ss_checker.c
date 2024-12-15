#include "../inc/sudoku_solver.h"

int	ss_check_row(ss_num **matrix, int row, ss_num nbr)
{
	for (int i = 0; i < 9; i++) {
		if (matrix[row][i] == nbr)
			return (0);
	}

	return (1);
}

int	ss_check_col(ss_num **matrix, int col, ss_num nbr)
{
	for (int i = 0; i < 9; i++) {
		if (matrix[i][col] == nbr)
			return (0);
	}

	return (1);
}

int	ss_check_sgrid(ss_num **matrix, int row, int col, int nbr)
{
	int	sg_row = row - (row % 3);
	int	sg_col = col - (col % 3);

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (matrix[i + sg_row][j + sg_col] == nbr)
				return (0);
		}
	}

	return (1);
}

int	ss_checker(ss_num **matrix, int row, int col, ss_num nbr)
{
	if (ss_check_row(matrix, row, nbr) == 0)
		return (0);
	if (ss_check_col(matrix, col, nbr) == 0)
		return (0);
	if (ss_check_sgrid(matrix, row, col, nbr) == 0)
		return (0);

	return (1);
}

