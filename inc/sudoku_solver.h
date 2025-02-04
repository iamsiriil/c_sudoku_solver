#ifndef SUDOKU_SOLVER_H
# define SUDOKU_SOLVER_H

//# define DEBUG

# include <math.h>
# include <ctype.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdbool.h>

# include "logger.h"

# define NUM_OF_SIZES 3				// Number of valid grid sizes
# define GRID_SIZES (int[]){4, 9, 16}		// Array of valid grid sizes
# define CNS_SQRT(n) (int)sqrt(n)

typedef unsigned char ss_num;

typedef struct s_grid {
	int gx, gy;
	int sx, sy;
	ss_num **g;
} t_grid;

// Dynamic grid
ss_num		**cns_create_grid(int x, int y, ss_num *a);
t_grid		*cns_initialize_grid(ss_num *a, int gs);
void		cns_print_grid(t_grid *gr);
void		cns_free_grid(t_grid *gr);

// Argument parser functions
char		*cns_argv_to_buffer(int ac, char **av);
char		*cns_file_to_buffer(char *p);
t_grid		*cns_parse_arguments(int ac, char **av);

// Argument tester functions
int		cns_test_size(int n);
bool		cns_test_range(int n, int gz);
t_grid		*cns_test_buffer(char *b);

// Checker functions 
bool		cns_check_row(t_grid *gr, int r, ss_num n);
bool		cns_check_col(t_grid *gr, int c, ss_num n);
bool		cns_check_sgrid(t_grid *gr, int r, int c, ss_num n);
bool		cns_check_constraints(t_grid *gr, int r, int c, ss_num n);

// Util functions
int		cns_get_n_values(char *b);
char		*cns_clean_buffer(char *b);
size_t		cns_get_size(int ac, char ** av);

// Solver
bool		cns_solver_naive(t_grid *gr, int r, int c);

#endif 

