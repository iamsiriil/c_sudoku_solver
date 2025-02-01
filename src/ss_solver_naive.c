#include "../inc/sudoku_solver.h"

bool	ss_solver_naive(t_grid *gr, int r, int c) {

	if (r == gr->x - 1 && c == gr->y)
		return true;

	if (c == gr->y) {
		r++;
		c = 0;
	}

	if (gr->g[r][c] > 0)
		return (ss_solver_naive(gr, r, c + 1));

	for (ss_num n = 1; n <= gr->x; ++n) {

		if (ss_test_candidate(gr, r, c, n) == true) {
			gr->g[r][c] = n;

			if (ss_solver_naive(gr, r, c + 1) == true)
				return true;
		}	
		gr->g[r][c] = 0;
	}

	return false;
}
