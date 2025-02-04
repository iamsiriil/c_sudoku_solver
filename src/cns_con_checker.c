#include "../inc/cns_ssolver.h"

bool	cns_check_row(t_grid *gr, int r, ss_num n) {

	LOG_MESSAGE("Function call.");

	for (int j = 0; j < gr->gx; ++j) {
		if (gr->g[r][j] == n) return false;
	}

	return true;
}

bool	cns_check_col(t_grid *gr, int c, ss_num n) {

	LOG_MESSAGE("Function call.");

	for (int i = 0; i < gr->gy; ++i) {
		if (gr->g[i][c] == n) return false;
	}

	return true;
}

bool	cns_check_sgrid(t_grid *gr, int r, int c, ss_num n) {

	LOG_MESSAGE("Function call.");

	int	sg_r = r - (r % 3);
	int	sg_c = c - (c % 3);

	for (int i = 0; i < gr->sx; ++i) {
		for (int j = 0; j < gr->sy; ++j) {
			if (gr->g[i + sg_r][j + sg_c] == n)
				return false;
		}
	}

	return true;
}

bool	cns_check_constraints(t_grid *gr, int r, int c, ss_num n) {

	LOG_MESSAGE("Function call.");

	if (!cns_check_row(gr, r, n))
		return false;
	if (!cns_check_col(gr, c, n))
		return false;
	if (!cns_check_sgrid(gr, r, c, n))
		return false;

	return true;
}

