#include "../inc/sudoku_solver.h"

int	r = 0;

int	ss_solver_naive(unsigned char **matrix, int row, int col, int size)
{
	LOG_MESSAGE("function call : recursion #%d", ++r);

	if (row == size - 1 && col == size)
		return (1);
	if (col == size) {
		row++;
		col = 0;
	}
	if (matrix[row][col] > 0)
		return (ss_solver_naive(matrix, row, col + 1, size));

	for (unsigned char nbr = 1; nbr <= size; nbr++) {
		if (ss_checker(matrix, row, col, nbr) == 1) {
			matrix[row][col] = nbr;
			if (ss_solver_naive(matrix, row, col + 1, size) == 1)
				return (1);
		}	
		matrix[row][col] = 0;
	}

	return (0);
}
