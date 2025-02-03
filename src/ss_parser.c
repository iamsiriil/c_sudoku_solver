#include "../inc/sudoku_solver.h"

t_grid	*ss_parse_arguments(int ac, char **av) {

	if (ac < 2) {
		perror("No arguments were passed");
		exit(1);
	}
	char *b = NULL;
	if (ac == 2)
		b = ss_file_to_buffer(av[1]);
	else
		b = ss_argv_to_buffer(ac, av);
	
	t_grid *gr = ss_test_buffer(b);
	return gr;
}

