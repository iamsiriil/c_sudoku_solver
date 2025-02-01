#include "../inc/sudoku_solver.h"

bool	ss_test_row(t_grid *gr, int r, ss_num n) {

	for (int j = 0; j < gr->x; ++j) {
		if (gr->g[r][j] == n) return false;
	}

	return true;
}

bool	ss_test_col(t_grid *gr, int c, ss_num n) {

	for (int i = 0; i < gr->y; ++i) {
		if (gr->g[i][c] == n) return false;
	}

	return true;
}

bool	ss_test_sgrid(t_grid *gr, int r, int c, ss_num n) {

	int	sg_r = r - (r % 3);
	int	sg_c = c - (c % 3);

	for (int i = 0; i < SS_SQRT(gr->x); ++i) {
		for (int j = 0; j < SS_SQRT(gr->y); ++j) {
			if (gr->g[i + sg_r][j + sg_c] == n)
				return false;
		}
	}

	return true;
}

bool	ss_test_candidate(t_grid *gr, int r, int c, ss_num n) {

	if (ss_test_row(gr, r, n) &&
			ss_test_col(gr, c, n) &&
			ss_test_sgrid(gr, r, c, n))
		return true;

	return false;
}

