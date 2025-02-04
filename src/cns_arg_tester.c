#include "../inc/sudoku_solver.h"

int	cns_test_size(int n) {

	int i = 0;
	for (; i < NUM_OF_SIZES; ++i) {
		if ((int)CNS_SQRT(n) == GRID_SIZES[i])
			return GRID_SIZES[i];
	}
	return 0;
}

bool	cns_test_range(int n, int sz) {

	return (n >= 0 && n <= sz) ? true : false;
}

t_grid	*cns_test_buffer(char *b) {

	int v = cns_get_n_values(b), gs = 0;
	ss_num *ar = NULL;

	if ((gs = cns_test_size(v)) != 0) {
		ar = malloc(sizeof(ss_num) * v);
		if (! ar) {
			perror("Program failed to allocate memory for array");
			free(b);
			exit(EXIT_FAILURE);
		} 
		char *s = strtok(b, " ");
		int i = 0, n = 0;
		do {
			n = atoi(s);
			if (cns_test_range(n, gs)) {
				ar[i++] = n;
				//if (i >= v) break;
			}
			else {
				perror("value out of range");
				free(ar);
				free(b);
				exit(1);
			}
		} while ((s = strtok(NULL, " ")) != NULL);
	} else {
		perror("Invalid number of values");
		free(b);
		exit(1);
	}

	free(b);
	return cns_initialize_grid(ar, gs);
}

