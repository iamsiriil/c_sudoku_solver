#include "../inc/sudoku_solver.h"

ssint	**create_grid(int x, int y, ssint *a) {

	LOG_MESSAGE("Function call.");

	ssint **gr = malloc(sizeof(ssint *) * x);
	if (!gr)
		error_handler(NULL, NULL, ERR_ALLOC);

	for (int i = 0, k = 0; i < x; ++i) {

		gr[i] = malloc(sizeof(ssint) * y);
		if (!gr[i]) {				// error handling
			for (int j = 0; j < i; ++j)
				free(gr[j]);
			free(gr);
			return NULL;
		}

		for (int j = 0; j < y; ++j)
			gr[i][j] = a[k++];
	}

	free(a);
	return gr;
}

t_grid	*initialize_grid(ssint *a, int gs) {

	LOG_MESSAGE("Function call.");

	t_grid *gr = malloc(sizeof(t_grid));
	if (!gr) 
		error_handler(NULL, NULL, ERR_ALLOC);

	gr->gx = gr->gy = (ssint)gs;
	gr->sx = gr->sy = (ssint)SQRT(gs);
	gr->g = create_grid(gr->gx, gr->gy, a);

	return gr;
}

void	print_grid(t_grid *gr) {

	LOG_MESSAGE("Function call.");

	for (int i = 0; i < gr->gx; ++i) {
		for (int j = 0; j < gr->gy; ++j) {
			printf("%d ", gr->g[i][j]);
		}
		printf("\n");
	}
}

void	free_grid(t_grid *gr) {

	LOG_MESSAGE("Function call.");

	for (int i = 0; i < gr->gx; ++i)
		free(gr->g[i]);
	free(gr->g);
	free(gr);
}

