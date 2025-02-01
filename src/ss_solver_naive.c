#include "../inc/sudoku_solver.h"

int	r = 0;

bool	ss_solver_naive(t_grid *gr, int r, int c)
{
	LOG_MESSAGE("function call : recursion #%d", ++r);

	if (r == gr->x - 1 && c == gr->x)
		return true;
	if (c == gr->x) {
		r++;
		c = 0;
	}
	if (gr->g[r][c] > 0)
		return (ss_solver_naive(gr, r, c + 1));

	for (ss_num n = 1; n <= gr->x; ++n) {
		if (ss_test_candidate(gr, r, c, n) == 1) {
			gr->g[r][c] = n;
			if (ss_solver_naive(gr, r, c + 1) == 1)
				return true;
		}	
		gr->g[r][c] = 0;
	}

	return false;
}
