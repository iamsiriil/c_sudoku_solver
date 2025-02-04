#include "../inc/cns_ssolver.h"

int	cns_test_size(int n) {

	int i = 0;
	for (; i < NUM_OF_SIZES; ++i) {
		if (((int)CNS_SQRT(n) == GRID_SIZES[i]) && (n % GRID_SIZES[i] == 0))
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

	printf("n of values : %d\n", v);
	if ((gs = cns_test_size(v)) != 0) {
		ar = malloc(sizeof(ss_num) * v);
		if (! ar)
			cns_error_handler(b, NULL, "Failed to allocate memory");

		char *s = strtok(b, " ");
		int i = 0, n = 0;
		do {
			n = atoi(s);
			if (cns_test_range(n, gs)) {
				ar[i++] = n;
				if (i >= v) break;
			}
			else
				cns_error_handler(ar, b, "Value out of range");
		} while ((s = strtok(NULL, " ")) != NULL);

	}
	else
		cns_error_handler(b, NULL, "Invalid number of values");

	free(b);
	return cns_initialize_grid(ar, gs);
}

