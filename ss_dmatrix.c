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

//int	main(void)
//{
//	int		size = 9;
//	unsigned char	**matrix = ss_create_matrix(size);
//	ss_print_matrix(matrix, size);
//	ss_free_matrix(matrix, size);
//	return (0);
//}
