NAME = sudoku_solver

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SSLIB_DIR = ./sslib/
SSLIB = $(SSLIB_DIR)sslib.a

HDRS = sudoku_solver.h logger.h
SOURCE = ss_parser.c ss_utils.c ss_main.c ss_dmatrix.c ss_checker.c
OBJS = $(SOURCE:.c=.o)

all: $(SSLIB) $(NAME)

$(SSLIB):
	@$(MAKE) -C $(SSLIB_DIR)

$(NAME): $(OBJS) $(SSLIB)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(HDRS) -L$(SSLIB_DIR) -l:sslib.a

%.o: %.c $(HDRS)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@$(MAKE) -C $(SSLIB_DIR) clean

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(SSLIB_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
