#include "../inc/sudoku_solver.h"

int	ss_get_n_values(char *b) {

	int ct = 0;
	while (*b) {
		if (isdigit(*b)) {
			ct++;
			for (; isdigit(*b); b++) ;
		}
		else b++;
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

char	*ss_argv_to_buffer(int ac, char **av) {

	size_t sz = ss_get_size(ac, av);
	char *buff = malloc(sizeof(char) * sz + 1);
	if (!buff) {
		perror("Failed to allocate memory for buffer");
		exit(EXIT_FAILURE);
	}

	int k = 0;
	for (int i = 1; i < ac; ++i) {
		for (int j = 0; av[i][j]; ++j)
			buff[k++] = av[i][j];
		if (i != ac - 1)
			buff[k++] = ' ';
	}
	buff[k] = '\0';

	return ss_clean_buffer(buff);
}

char	*ss_file_to_buffer(char *p) {

	FILE *f = fopen(p, "r");
	if (f == NULL) {
		perror("Failed to open file");
		exit(EXIT_FAILURE);
	}

	fseek(f, 0, SEEK_END);
	size_t sz = (size_t)ftell(f);
	rewind(f);

	char *buff = malloc(sizeof(char) * sz + 1);
	if (!buff) {
		perror("Failed to allocate mamory for buffer");
		exit(EXIT_FAILURE);
	}

	size_t rd = fread(buff, sizeof(char), sz, f);
	if (rd < sz) {
		perror("Failed to read file");
		exit(EXIT_FAILURE);
	}

	fclose(f);
	return ss_clean_buffer(buff);
}

