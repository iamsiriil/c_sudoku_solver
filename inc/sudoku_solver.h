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

# include "../sslib/inc/sslib.h"
# include "logger.h"

# define SS_NUM_OF_SIZES 3			// Number of valid grid sizes
# define SS_GRID_SIZES (int[]){4, 9, 16}	// Array of valid grid sizes
# define SS_SQRT(n) (int)sqrt(n)

# define SS_BUFFSZ 1024
extern char buffer[SS_BUFFSZ];

typedef unsigned char ss_num;

typedef struct s_grid {
	int gx, gy;
	int sx, sy;
	ss_num **g;
} t_grid;



// Dynamic grid
ss_num		**ss_create_grid(int x, int y, ss_num *a);
t_grid		*ss_initialize_grid(ss_num *a, int gs);
void		ss_print_grid(t_grid *gr);
void		ss_free_grid(t_grid *gr);

// Parser functions
t_grid		*ss_parse_arguments(int ac, char **av);

// Checker functions 
bool		ss_check_row(t_grid *gr, int r, ss_num n);
bool		ss_check_col(t_grid *gr, int c, ss_num n);
bool		ss_check_sgrid(t_grid *gr, int r, int c, ss_num n);
bool		ss_check_candidate(t_grid *gr, int r, int c, ss_num n);

// Tester functions
int		ss_test_size(int n);
bool		ss_test_range(int n, int gz);
t_grid		*ss_test_buffer(char *b);

// Util functions
int		ss_get_n_values(char *b);
char		*ss_clean_buffer(char *b);
size_t		ss_get_size(int ac, char ** av);
char		*ss_argv_to_buffer(int ac, char **av);
char		*ss_file_to_buffer(char *p);

// Solver
bool		ss_solver_naive(t_grid *gr, int r, int c);

#endif 
