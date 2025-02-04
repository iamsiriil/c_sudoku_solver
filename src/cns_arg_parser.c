#include "../inc/cns_ssolver.h"

char	*cns_argv_to_buffer(int ac, char **av) {

	size_t sz = cns_get_size(ac, av);
	char *buff = malloc(sizeof(char) * sz + 1);
	if (!buff) {
		perror("Failed to allocate memory for buffer");
		exit(EXIT_FAILURE);
	}
	memset(buff, 0, sz + 1);

	int k = 0;
	for (int i = 1; i < ac; ++i) {
		for (int j = 0; av[i][j]; ++j) {
			if (k >= sz) break;
			buff[k++] = av[i][j];
		}
		if (i != ac - 1 && k < sz)
			buff[k++] = ' ';
	}
	buff[k] = '\0';

	return cns_clean_buffer(buff);
}

char	*cns_file_to_buffer(char *p) {

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
	memset(buff, 0, sz + 1);

	size_t rd = fread(buff, sizeof(char), sz, f);
	if (rd < sz) {
		perror("Failed to read file");
		exit(EXIT_FAILURE);
	}
	buff[rd] = '\0';

	fclose(f);
	return cns_clean_buffer(buff);
}

t_grid	*cns_parse_arguments(int ac, char **av) {

	if (ac < 2) {
		perror("No arguments were passed");
		exit(1);
	}
	char *b = NULL;
	if (ac == 2)
		b = cns_file_to_buffer(av[1]);
	else
		b = cns_argv_to_buffer(ac, av);
	
	return cns_test_buffer(b);
}

