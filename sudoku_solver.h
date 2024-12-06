#ifndef SUDOKU_SOLVER_H
# define SUDOKU_SOLVER_H

# define DEBUG

# include <stdio.h>
# include <stdlib.h>
# include "./sslib/sslib.h"
# include "logger.h"

// Dynamic matrix
unsigned char	**ss_create_matrix(int size);
void		ss_print_matrix(unsigned char **matrix, int size);
void		ss_free_matrix(unsigned char **matrix, int size);

// Parser functions
int	ss_test_input(char **argv);
void	ss_parse_input(char **argv, int matrix[9][9]);

// Utils
void	ss_populate_matrix(char **argv, int matrix[9][9]);

#endif 
