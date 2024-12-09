#include "./test_sudoku_solver.h"

int	main(void)
{
	int		size = 9;

	unsigned char	**matrix01 = ss_test_matrix01(size);
	unsigned char	**matrix02 = ss_test_matrix01(size);

	printf("\n\nCHECK ROW\n\n");

	for (int i = 0; i < size; i++)
		printf("exp : %d | got : %d\n", 1, ss_check_row(matrix01, i, 2));

	for (int i = 0; i < size; i++)
		printf("exp : %d | got : %d\n", 0, ss_check_row(matrix01, i, 1));

	printf("\n\nCHECK COL\n\n");

	for (int i = 0; i < size; i++)
		printf("exp : %d | got : %d\n", 1, ss_check_col(matrix01, i, 2));

	for (int i = 0; i < size; i++)
		printf("exp : %d | got : %d\n", 0, ss_check_col(matrix01, i, 1));

	printf("\n\nCHECK SUB-ROW\n\n");

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			printf("matrix[%d][%d] : exp : %d | got : %d\n", i, j, 0, ss_check_sgrid(matrix02, i, j, 1));
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			printf("matrix[%d][%d] : exp : %d | got : %d\n", i, j, 1, ss_check_sgrid(matrix02, i, j, 2));
	}

	ss_free_matrix(matrix01, size);
	ss_free_matrix(matrix02, size);

	return (0);
}
