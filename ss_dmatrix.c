#include "sudoku_solver.h"

unsigned char	**ss_create_matrix(int size)
{
	LOG_MESSAGE("Function call.");
	unsigned char	**matrix = (unsigned char **)malloc(sizeof(char **) * size);
	if (!matrix)
		return (NULL);

	for (int i = 0; i < size; i++)
	{
		matrix[i] = (unsigned char *)malloc(sizeof(char *) * size);
		if (!matrix[i])
			return (NULL);
		for (int j = 0; j < size; j++)
			matrix[i][j] = 0;
	}

	return (matrix);
}

void	ss_populate_matrix(int argc, char **argv, unsigned char **matrix)
{
	LOG_MESSAGE("Function call: argc : %d.", argc);
	(void)argc;
	int i = 0;
	while (i < 9)
	{
		int j = 0;
		while (j < 9)
		{
			argv++;
			matrix[i][j] = ss_atoi(*argv);
			j++;
		}
		i++;
	}
}

void	ss_print_matrix(unsigned char **matrix, int size)
{
	LOG_MESSAGE("Function call.");
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			printf("%d ", matrix[i][j]);
			if (j == size - 1)
				printf("\n");
		}
	}
}

void	ss_free_matrix(unsigned char **matrix, int size)
{
	LOG_MESSAGE("Function call.");
	for (int i = 0; i < size; i++)
		free(matrix[i]);
	free(matrix);
}

