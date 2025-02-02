#include "../inc/sudoku_solver.h"

char buffer[SS_BUFFSZ];

void	ss_file_to_buff(char *f) {

	int fd = open(f, O_RDONLY);
	int bt = read(fd, buffer, SS_BUFFSZ);
	buffer[bt] = '\0';

	close(fd);
}

int	ss_get_grid_size(char *b) {

	int ct = 0;

	for (; *b; b++) {
		if (ss_isdigit(*b)) ct++;
	}

	return ct = SS_SQRT(ct);
}

