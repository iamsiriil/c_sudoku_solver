#include "../inc/sudoku_solver.h"

int	ss_test_size(int n) {

	int i = 0;
	for (; i < SS_NUM_OF_SIZES; ++i) {
		if ((int)SS_SQRT(n) == SS_GRID_SIZES[i])
			return SS_GRID_SIZES[i];
	}
	return 0;
}

bool	ss_test_range(int n, int sz) {

	return (n >= 0 && n <= sz) ? true : false;
}

t_grid	*ss_test_buffer(char *b) {

	int n = ss_get_n_values(b), gs = 0;
	ss_num *ar = NULL;

	if ((gs = ss_test_size(n)) != 0) {
		ar = malloc(sizeof(ss_num) * n);
		if (! ar) {
			perror("Program failed to allocate memory for array");
			free(b);
			exit(EXIT_FAILURE);
		} 
		char *s = strtok(b, " ");
		int i = 0, n = 0;
		do {
			n = atoi(s);
			if (ss_test_range(n, gs))
				ar[i++] = n;
			else {
				perror("value out of range");
				free(ar);
				free(b);
				exit(1);
			}
		} while ((s = strtok(NULL, " ")));
	} else {
		perror("Invalid number of values");
		free(b);
		exit(1);
	}

	free(b);
	return ss_initialize_grid(ar, gs);
}

