#ifndef SSOLVER_H
# define SSOLVER_H

//# define DEBUG

# include <math.h>
# include <stdio.h>
# include <ctype.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>

# include "logger.h"
# include "./error_handler.h"

# define NUM_OF_SIZES 3				// Number of valid grid sizes
# define GRID_SIZES (int[]){4, 9, 16}		// Array of valid grid sizes
# define SQRT(n) (int)sqrt(n)

typedef unsigned char ssint;

typedef struct s_grid {
	int gx, gy;
	int sx, sy;
	ssint **g;
} t_grid;

// Dynamic grid
ssint		**create_grid(int x, int y, ssint *a);
t_grid		*initialize_grid(ssint *a, int gs);
void		print_grid(t_grid *gr);
void		free_grid(t_grid *gr);

// Argument parser functions
char		*argv_to_buffer(int ac, char **av);
char		*file_to_buffer(char *p);
t_grid		*parse_arguments(int ac, char **av);

// Argument tester functions
int		test_size(int n);
bool		test_range(int n, int gz);
t_grid		*test_buffer(char *b);

// Checker functions 
bool		check_row(t_grid *gr, int r, ssint n);
bool		check_col(t_grid *gr, int c, ssint n);
bool		check_sgrid(t_grid *gr, int r, int c, ssint n);
bool		check_constraints(t_grid *gr, int r, int c, ssint n);

// Util functions
int		get_n_values(char *b);
char		*clean_buffer(char *b);
size_t		get_size(int ac, char ** av);

// Solver
bool		solver_naive(t_grid *gr, int r, int c);

#endif 

