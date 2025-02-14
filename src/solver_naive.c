#include "../inc/sudoku_solver.h"

bool	solver_naive(t_grid *gr, int r, int c) {

	LOG_MESSAGE("Function call.");

	if (r == gr->gx - 1 && c == gr->gy)
		return true;

	if (c == gr->gy) {
		r++;
		c = 0;
	}

	if (gr->g[r][c] > 0)
		return (solver_naive(gr, r, c + 1));

	for (ssint n = 1; n <= gr->gx; ++n) {

		if (check_constraints(gr, r, c, n) == true) {
			gr->g[r][c] = n;
			if (solver_naive(gr, r, c + 1) == true)
				return true;
		}	
		gr->g[r][c] = 0;
	}

	return false;
}
