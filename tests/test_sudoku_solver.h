#ifndef TEST_SUDOKU_SOLVER_H
# define TEST_SUDOKU_SOLVER_H

# include "../inc/sudoku_solver.h"

unsigned char	**ss_test_matrix01(int size)
{
	unsigned char	**test_matrix = ss_create_matrix(size);

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (j == i)
				test_matrix[i][j] = 1;
		}
	}

	return (test_matrix);
}

unsigned char	**ss_test_matrix02(int size)
{
	unsigned char	**test_matrix = ss_create_matrix(size);

	for (int i = 0; i < size; i += 4) {
		for (int j = 0; j < size; j += 4)
			test_matrix[i][j] = 1;
	}

	return (test_matrix);
}

static void	ss_number_sgrid(unsigned char **matrix, int row, int col)
{
	int		sg_row = row - (row % 3);
	int		sg_col = col - (col % 3);
	static int	k = 0;

	k++;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			matrix[i + sg_row][j + sg_col] = k;
	}
}

unsigned char	**ss_test_matrix03(int size)
{
	unsigned char	**test_matrix = ss_create_matrix(size);

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
			ss_number_sgrid(test_matrix, i, j);
	}

	return (test_matrix);
}

#endif
