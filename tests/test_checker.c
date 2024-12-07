#include "../ss_checker.c"
#include "../ss_dmatrix.c"
#include "../sslib/ss_atoi.c"
#include "../sslib/ss_isspace.c"
#include "../sslib/ss_isdigit.c"

int	main(void)
{
	unsigned char	**grid = ss_create_matrix(9);

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (j == i)
				grid[i][j] = 1;
		}
	}
	ss_print_matrix(grid, 9);

	printf("\n\nCHECK ROW\n\n");

	for (int i = 0; i < 9; i++)
		printf("exp : %d | got : %d\n", 1, ss_check_row(grid, i, 2));

	for (int i = 0; i < 9; i++)
		printf("exp : %d | got : %d\n", 0, ss_check_row(grid, i, 1));

	printf("\n\nCHECK COL\n\n");

	for (int i = 0; i < 9; i++)
		printf("exp : %d | got : %d\n", 1, ss_check_col(grid, i, 2));

	for (int i = 0; i < 9; i++)
		printf("exp : %d | got : %d\n", 0, ss_check_col(grid, i, 1));
		
	return (0);
}
