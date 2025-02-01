#include "../inc/sudoku_solver.h"

bool	ss_test_input(int ac, char **av, t_grid *gr) {

	int n = 0;
	for (int i = 1; i < (ac - 1); ++i) {
		n = atoi(av[i]);
		if (n < 0 || n > gr->x) return false;
	}

	return true;
}

void	ss_parse_input(int ac, char **av, t_grid *gr) {

	if (!ss_test_input(ac, av, gr))
		exit(EXIT_FAILURE);
	else
		ss_populate_grid(gr, av);
}

