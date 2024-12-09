#ifndef SUDOKU_SOLVER_H
# define SUDOKU_SOLVER_H

//# define DEBUG

# include <stdio.h>
# include <stdlib.h>
# include "../sslib/inc/sslib.h"
# include "logger.h"

// Dynamic matrix
unsigned char	**ss_create_matrix(int size);
void		ss_populate_matrix(char **argv, unsigned char **matrix);
void		ss_print_matrix(unsigned char **matrix, int size);
void		ss_free_matrix(unsigned char **matrix, int size);

// Parser functions
int		ss_test_input(int argc, char **argv);
void		ss_parse_input(int argc, char **argv, unsigned char **matrix);

// Checker functions
int		ss_check_row(unsigned char **matrix, int row, unsigned char nbr);
int		ss_check_col(unsigned char **matrix, int col, unsigned char nbr);
int		ss_check_sgrid(unsigned char **matrix, int row, int col, int nbr);
int		ss_checker(unsigned char **matrix, int row, int col, unsigned char nbr);

// Solver
int		ss_solver_naive(unsigned char **matrix, int row, int col, int size);

#endif 
