#include "../inc/sudoku_solver.h"

int	test_size(int n) {

	LOG_MESSAGE("Function call.");

	int i = 0;
	for (; i < NUM_OF_SIZES; ++i) {
		if (((int)SQRT(n) == GRID_SIZES[i]) && (n % GRID_SIZES[i] == 0))
			return GRID_SIZES[i];
	}
	return 0;
}

bool	test_range(int n, int sz) {

	LOG_MESSAGE("Function call.");

	return (n >= 0 && n <= sz) ? true : false;
}

t_grid	*test_buffer(char *b) {

	LOG_MESSAGE("Function call.");

	int v = get_n_values(b), gs = 0;
	ssint *ar = NULL;

	if ((gs = test_size(v)) != 0) {
		ar = malloc(sizeof(ssint) * v);
		if (! ar)
			error_handler(b, NULL, ERR_ALLOC);

		char *s = strtok(b, " ");
		int i = 0, n = 0;
		do {
			n = atoi(s);
			if (test_range(n, gs)) {
				ar[i++] = n;
				if (i >= v) break;
			}
			else
				error_handler(ar, b, ERR_RANGE);
		} while ((s = strtok(NULL, " ")) != NULL);

	}
	else
		error_handler(b, NULL, ERR_NVALS);

	free(b);
	return initialize_grid(ar, gs);
}

