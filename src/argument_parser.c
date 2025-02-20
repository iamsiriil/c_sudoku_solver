#include "../inc/sudoku_solver.h"

char	*argv_to_buffer(int ac, char **av) {

	LOG_MESSAGE("Function call.");

	size_t sz = get_size(ac, av);
	char *buff = malloc(sizeof(char) * sz + 1);
	if (!buff)
		error_handler(NULL, NULL, ERR_ALLOC);
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

	return clean_buffer(buff);
}

char	*file_to_buffer(char *p) {

	LOG_MESSAGE("Function call.");

	FILE *f = fopen(p, "r");
	if (f == NULL)
		error_handler(NULL, NULL, ERR_OFILE);

	fseek(f, 0, SEEK_END);
	size_t sz = (size_t)ftell(f);
	rewind(f);

	char *buff = malloc(sizeof(char) * sz + 1);
	if (!buff)
		error_handler(buff, NULL, ERR_ALLOC);
	memset(buff, 0, sz + 1);

	size_t rd = fread(buff, sizeof(char), sz, f);
	if (rd < sz)
		error_handler(buff, NULL, ERR_RFILE);
	buff[rd] = '\0';

	fclose(f);
	return clean_buffer(buff);
}

t_grid	*parse_arguments(int ac, char **av) {

	LOG_MESSAGE("Function call.");

	if (ac < 2)
		error_handler(NULL, NULL, ERR_NARGS);

	char *b = NULL;
	if (ac == 2)
		b = file_to_buffer(av[1]);
	else
		b = argv_to_buffer(ac, av);
	
	return test_buffer(b);
}

