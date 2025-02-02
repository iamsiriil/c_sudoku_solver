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

void	ss_parse_file(t_grid *gr, char *f) {

	LOG_MESSAGE("Function call.");

	ss_file_to_buff(f);

	gr->gx = gr->gy = ss_get_grid_size(buffer);

	gr->g = ss_create_grid(gr->gx, gr->gy);
	if (gr->g == NULL) {
		perror("Failed to create grid.");
		free(gr);
		exit(EXIT_FAILURE);
	}

	ss_num n = atoi(strtok(buffer, " \n"));

	for (int i = 0; i < gr->gx; ++i) {
		for (int j = 0 ; j < gr->gy; ++j) {
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

