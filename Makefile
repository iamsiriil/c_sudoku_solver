NAME 		= sudoku_solver

CC 		= gcc
CFLAGS 		= -Wall -Wextra -Werror

RM 		= rm -f
RMDIR 		= rm -rf

SSLIB_DIR 	= ./sslib/
SSLIB 		= $(SSLIB_DIR)sslib.a

HDR_DIR		= ./inc/
HDRS 		= $(wildcard $(HDR_DIR)*.h)

SRC_DIR		= ./src/
SOURCE 		= $(wildcard $(SRC_DIR)*.c)

OBJ_DIR		= ./obj/
OBJS		= $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SOURCE))  

TST_DIR		= ./tests/
TST_OBJS	= $(filter-out $(OBJ_DIR)ss_main.o, $(OBJS))

all: $(SSLIB) $(NAME)

$(SSLIB):
	@$(MAKE) -C $(SSLIB_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS) $(SSLIB)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(HDRS) -L$(SSLIB_DIR) -l:sslib.a

clean:
	@$(RM) $(OBJS)
	@$(RMDIR) $(OBJ_DIR)
	@$(MAKE) -C $(SSLIB_DIR) clean

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(SSLIB_DIR) fclean

re: fclean all

test_checker:
	@$(CC) $(TST_DIR)test_checker.c $(TST_OBJS) -L$(SSLIB_DIR) -l:sslib.a
	./a.out

.PHONY: all clean fclean re
