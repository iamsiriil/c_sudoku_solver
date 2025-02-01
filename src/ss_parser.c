#include "../inc/sudoku_solver.h"

bool	ss_test_input(int ac, char **av, t_grid *gr) {

	LOG_MESSAGE("Function call.");

	int n = 0;
	for (int i = 1; i < (ac - 1); ++i) {
		n = atoi(av[i]);
		if (n < 0 || n > gr->x) return false;
	}

	return true;
}

void	ss_parse_file(t_grid *gr, char *f) {

	LOG_MESSAGE("Function call.");

	char buff[SS_BUFFSZ];
	int fd = open(f, O_RDONLY);	
	int b = read(fd, buff, SS_BUFFSZ);
	buff[b] = '\0';


	char *s = strtok(buff, " \n");
	ss_num n = (ss_num)atoi(s);

	for (int i = 0; i < gr->x; ++i) {
		for (int j = 0 ; j < gr->y; ++j) {
			gr->g[i][j] = n;
			if (!(i == 8 && j == 8))
				n = (ss_num)atoi(strtok(0, " \n"));
		}
	}	
	close(fd);
}
void	ss_parse_input(int ac, char **av, t_grid *gr) {

	LOG_MESSAGE("Function call.");

	if (!ss_test_input(ac, av, gr))
		exit(EXIT_FAILURE);
	else
		ss_populate_grid(gr, av);
}

