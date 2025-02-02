#include "../inc/sudoku_solver.h"

bool	ss_test_input(int ac, char **av, t_grid *gr) {

	LOG_MESSAGE("Function call.");

	int n = 0;
	for (int i = 1; i < (ac - 1); ++i) {
		n = atoi(av[i]);
		if (n < 0 || n > gr->x) return false;
	}

	return true;
}

void	ss_parse_file(t_grid *gr, char *f) {

	LOG_MESSAGE("Function call.");

	ss_file_to_buff(f);

	gr->x = gr->y = ss_get_grid_size(buffer);

	gr->g = ss_create_grid(gr->x, gr->y);
	if (gr->g == NULL) {
		perror("Failed to create grid.");
		free(gr);
		exit(EXIT_FAILURE);
	}

	ss_num n = atoi(strtok(buffer, " \n"));
	printf("size of n : %zu\n", sizeof(n));

	for (int i = 0; i < gr->x; ++i) {
		for (int j = 0 ; j < gr->y; ++j) {
			gr->g[i][j] = n;
			if (!(i == 8 && j == 8))
				n = atoi(strtok(0, " \n"));
		}
	}	
}

void	ss_parse_input(int ac, char **av, t_grid *gr) {

	LOG_MESSAGE("Function call.");

	if (!ss_test_input(ac, av, gr))
		exit(EXIT_FAILURE);
	else
		ss_populate_grid(gr, av);
}

