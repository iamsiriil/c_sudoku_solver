#include "../inc/sudoku_solver.h"

bool	ss_test_input(int ac, char **av, t_grid *gr) {

	LOG_MESSAGE("Function call.");

	int n = 0;
	for (int i = 1; i < (ac - 1); ++i) {
		n = atoi(av[i]);
		if (n < 0 || n > gr->gx) return false;
	}

	return true;
}

t_grid	*ss_parse_arguments(int argc, char **argv) {

	t_grid *gr;

	switch (argc - 1) {
		case 1:
			//parse file
			break;
		case 16:
			// parse input 4x4
			break;
		case 81:
			//parse input 9x9
			break;
		case 256:
			// parse input 16x16
			break;
		default:
			// error
	}

	return gr;
}

