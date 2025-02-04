#include "../inc/sudoku_solver.h"

int	ss_get_n_values(char *b) {

	int ct = 0;

	while (*b) {
		if (isdigit(*b)) {
			ct++;
			while (isdigit(*b)) b++;
		}
		else
			b++;
	}

	return ct;
}

char	*ss_clean_buffer(char *b) {

	char *pt = b;

	for (; *b; b++) {
		if (!isdigit(*b) && *b != ' ')
			*b = ' ';
	}

	return pt;
}

size_t	ss_get_size(int ac, char ** av) {
	
	size_t sz = 0;

	for (int i = 1; i < ac; ++i) {
		for (int j = 0; av[i][j]; ++j)
			sz++;
		if (i != ac - 1)
			sz++;
	}

	return sz;
}

