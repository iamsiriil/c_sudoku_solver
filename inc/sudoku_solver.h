#ifndef SUDOKU_SOLVER_H
# define SUDOKU_SOLVER_H

//# define DEBUG

# include <stdio.h>
# include <stdlib.h>
# include "../sslib/inc/sslib.h"
# include "logger.h"

typedef unsigned char ss_num;

// Dynamic matrix
ss_num		**ss_create_matrix(int size);
void		ss_populate_matrix(char **argv, ss_num **matrix);
void		ss_print_matrix(ss_num **matrix, int size);
void		ss_free_matrix(ss_num **matrix, int size);

// Parser functions
int		ss_test_input(int argc, char **argv);
void		ss_parse_input(int argc, char **argv, ss_num **matrix);

// Checker functions
int		ss_check_row(ss_num **matrix, int row, ss_num nbr);
int		ss_check_col(ss_num **matrix, int col, ss_num nbr);
int		ss_check_sgrid(ss_num **matrix, int row, int col, int nbr);
int		ss_checker(ss_num **matrix, int row, int col, ss_num nbr);

// Solver
int		ss_solver_naive(ss_num **matrix, int row, int col, int size);

#endif 
