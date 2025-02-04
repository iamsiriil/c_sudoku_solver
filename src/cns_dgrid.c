#include "../inc/cns_ssolver.h"

ss_num	**cns_create_grid(int x, int y, ss_num *a) {

	LOG_MESSAGE("Function call.");

	ss_num **gr = malloc(sizeof(ss_num *) * x);
	if (!gr) return NULL;				// error handling

	for (int i = 0, k = 0; i < x; ++i) {

		gr[i] = malloc(sizeof(ss_num) * y);
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

t_grid	*cns_initialize_grid(ss_num *a, int gs) {

	t_grid *gr = malloc(sizeof(t_grid));
	if (!gr) {
		perror("Failed to allocate memory for cns_grid");
		free(a);
		exit(1);	
	}

	gr->gx = gr->gy = (ss_num)gs;
	gr->sx = gr->sy = (ss_num)CNS_SQRT(gs);
	gr->g = cns_create_grid(gr->gx, gr->gy, a);

	return gr;
}

void	cns_print_grid(t_grid *gr) {

	LOG_MESSAGE("Function call.");

	for (int i = 0; i < gr->gx; ++i) {
		for (int j = 0; j < gr->gy; ++j) {
			printf("%d ", gr->g[i][j]);
		}
		printf("\n");
	}
}

void	cns_free_grid(t_grid *gr) {

	LOG_MESSAGE("Function call.");

	for (int i = 0; i < gr->gx; ++i)
		free(gr->g[i]);
	free(gr->g);
	free(gr);
}

