#ifndef SUDOKU_SOLVER_H
# define SUDOKU_SOLVER_H

//# define DEBUG

# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdbool.h>

# include "../sslib/inc/sslib.h"
# include "logger.h"

# define SS_BUFFSZ 1024
extern char buffer[SS_BUFFSZ];

typedef unsigned char ss_num;

typedef enum {
	G4 = 4;
	G9 = 9;
	G16 = 16;
} e_gsize;

typedef enum {
	S2 = 2;
	S3 = 3;
	S4 = 4;
} e_sgsize;

typedef struct s_grid {
	e_gsize gx, gy;
	e_sdsize sx, sy;
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
void		ss_parse_file(t_grid *gr, char *f);

// Tester functions 
bool		ss_check_row(t_grid *gr, int r, ss_num n);
bool		ss_check_col(t_grid *gr, int c, ss_num n);
bool		ss_check_sgrid(t_grid *gr, int r, int c, ss_num n);
bool		ss_check_candidate(t_grid *gr, int r, int c, ss_num n);

// Util functions
void		ss_file_to_buff(char *f);
int		ss_get_grid_size(char *b);

// Solver
bool		ss_solver_naive(t_grid *gr, int r, int c);

#endif 
