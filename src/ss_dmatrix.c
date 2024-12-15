#include "../inc/sudoku_solver.h"

ss_num	**ss_create_matrix(int size)
{
	LOG_MESSAGE("Function call.");

	ss_num	**matrix;

	matrix = (ss_num **)malloc(sizeof(char **) * size);
	if (!matrix)
		return (NULL);

	for (int i = 0; i < size; i++) {
		matrix[i] = (ss_num *)malloc(sizeof(char *) * size);
		if (!matrix[i])
			return (NULL);
		for (int j = 0; j < size; j++)
			matrix[i][j] = 0;
	}

	return (matrix);
}

void	ss_populate_matrix(char **argv, ss_num **matrix)
{
	LOG_MESSAGE("Function call: argc : %d.", argc);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			argv++;
			matrix[i][j] = ss_atoi(*argv);
		}
	}
}

void	ss_print_matrix(ss_num **matrix, int size)
{
	LOG_MESSAGE("Function call.");

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			printf("%d ", matrix[i][j]);
			if (j == size - 1)
				printf("\n");
		}
	}
}

void	ss_free_matrix(ss_num **matrix, int size)
{
	LOG_MESSAGE("Function call.");

	for (int i = 0; i < size; i++)
		free(matrix[i]);
	free(matrix);
}

