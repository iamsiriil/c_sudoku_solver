#ifndef SUDOKU_SOLVER_H
# define SUDOKU_SOLVER_H

//# define DEBUG

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

# include "../sslib/inc/sslib.h"
# include "logger.h"

# define SS_4X4 4
# define SS_9X9 9
# define SS_16X16 16

# define SS_ARRAY_SIZE 256

# define SS_SQRT(n) (ss_num)sqrt(n)

typedef unsigned char ss_num;

typedef struct s_grid {
	ss_num x, y;
	ss_num **g;
} t_grid;

// Dynamic grid
ss_num		**ss_create_grid(int x, int y);
void		ss_populate_grid(t_grid *gr, char **av);
void		ss_print_grid(t_grid *gr);
void		ss_free_grid(t_grid *gr);

// Parser functions
bool		ss_test_input(int ac, char **av, t_grid *gr);
void		ss_parse_input(int ac, char **av, t_grid *gr);

// Tester functions 
bool		ss_test_row(t_grid *gr, int r, ss_num n);
bool		ss_test_col(t_grid *gr, int c, ss_num n);
bool		ss_test_sgrid(t_grid *gr, int r, int c, ss_num n);
bool		ss_test_candidate(t_grid *gr, int r, int c, ss_num n);

// Solver
bool		ss_solver_naive(t_grid *gr, int r, int c);

#endif 
