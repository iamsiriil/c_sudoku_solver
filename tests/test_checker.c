#include "../ss_checker.c"
#include "../ss_dmatrix.c"
#include "../sslib/ss_atoi.c"
#include "../sslib/ss_isspace.c"
#include "../sslib/ss_isdigit.c"

void	ss_test_sgrid(unsigned char **matrix, int row, int col)
{
	int		sg_row = row - (row % 3);
	int		sg_col = col - (col % 3);
	static int	k = 0;

	k++;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			matrix[i + sg_row][j + sg_col] = k;
	}
}

int	main(void)
{
	int		size = 9;
	unsigned char	**grid01 = ss_create_matrix(size);

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (j == i)
				grid01[i][j] = 1;
		}
	}
	ss_print_matrix(grid01, size);

	printf("\n\nCHECK ROW\n\n");

	for (int i = 0; i < size; i++)
		printf("exp : %d | got : %d\n", 1, ss_check_row(grid01, i, 2));

	for (int i = 0; i < size; i++)
		printf("exp : %d | got : %d\n", 0, ss_check_row(grid01, i, 1));

	printf("\n\nCHECK COL\n\n");

	for (int i = 0; i < size; i++)
		printf("exp : %d | got : %d\n", 1, ss_check_col(grid01, i, 2));

	for (int i = 0; i < size; i++)
		printf("exp : %d | got : %d\n", 0, ss_check_col(grid01, i, 1));

	unsigned char	**grid02 = ss_create_matrix(size);

	for (int i = 0; i < size; i += 4)
	{
		for (int j = 0; j < size; j += 4)
			grid02[i][j] = 1;
	}
		

	printf("\n\nCHECK SUB-ROW\n\n");

	ss_print_matrix(grid02, size);

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			printf("grid[%d][%d] : exp : %d | got : %d\n", i, j, 0, ss_check_sgrid(grid02, i, j, 1));
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			printf("grid[%d][%d] : exp : %d | got : %d\n", i, j, 1, ss_check_sgrid(grid02, i, j, 2));
	}
	ss_free_matrix(grid01, size);
	ss_free_matrix(grid02, size);

	printf("\n\nCHECK SUB-ROW #2\n\n");

	unsigned char	**grid03 = ss_create_matrix(size);

	for (int i = 0; i < size; i += 4)
	{
		for (int j = 0; j < size; j += 4)
			ss_test_sgrid(grid03, i, j);
	}

	ss_print_matrix(grid03, size);

	ss_free_matrix(grid03, size);
	return (0);
}
