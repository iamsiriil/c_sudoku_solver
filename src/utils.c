#include "../inc/sudoku_solver.h"

int	get_n_values(char *b) {

	LOG_MESSAGE("Function call.");

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

char	*clean_buffer(char *b) {

	LOG_MESSAGE("Function call.");

	char *pt = b;

	for (; *b; b++) {
		if (!isdigit(*b) && *b != ' ')
			*b = ' ';
	}

	return pt;
}

size_t	get_size(int ac, char ** av) {

	LOG_MESSAGE("Function call.");
	
	size_t sz = 0;

	for (int i = 1; i < ac; ++i) {
		for (int j = 0; av[i][j]; ++j)
			sz++;
		if (i != ac - 1)
			sz++;
	}

	return sz;
}

