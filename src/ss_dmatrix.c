#include "../inc/sudoku_solver.h"

ss_num	**ss_create_grid(int x, int y) {

	LOG_MESSAGE("Function call.");

	ss_num **gr = malloc(sizeof(ss_num *) * x);
	if (!gr) return NULL;

	for (int i = 0; i < x; ++i) {

		gr[i] = malloc(sizeof(ss_num) * y);
		if (!gr[i]) {
			for (int j = 0; j < i; ++j)
				free(gr[j]);
			free(gr);
			return NULL;
		}

		for (int j = 0; j < y; ++j)
			gr[i][j] = 0;
	}

	return gr;
}

void	ss_populate_grid(t_grid *gr, char **av) {

	LOG_MESSAGE("Function call.");

	++av;
	for (int i = 0; i < gr->gx; ++i) {
		for (int j = 0; j < gr->gy; ++j) {
			gr->g[i][j] = ss_atoi(*av++);
		}
	}
}

void	ss_print_grid(t_grid *gr) {

	LOG_MESSAGE("Function call.");

	for (int i = 0; i < gr->gx; ++i) {
		for (int j = 0; j < gr->gy; ++j) {
			printf("%d ", gr->g[i][j]);
		}
		printf("\n");
	}
}

void	ss_free_grid(t_grid *gr) {

	LOG_MESSAGE("Function call.");

	for (int i = 0; i < gr->gx; ++i)
		free(gr->g[i]);
	free(gr->g);
	free(gr);
}

