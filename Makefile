NAME 		= sudoku_solver

CC 		= gcc
CFLAGS 		= -Wall -Wextra -Werror

RM 		= rm -f
RMDIR 		= rm -rf

HDR_DIR		= ./inc/
HDRS 		= $(wildcard $(HDR_DIR)*.h)

SRC_DIR		= ./src/
SOURCE 		= $(wildcard $(SRC_DIR)*.c)

OBJ_DIR		= ./obj/
OBJS		= $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SOURCE))  

TST_DIR		= ./tests/
TST_OBJS	= $(filter-out $(OBJ_DIR)ss_main.o, $(OBJS))

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(HDRS) -lm 

clean:
	@$(RM) $(OBJS)
	@$(RMDIR) $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

test_checker:
	@$(CC) $(TST_DIR)test_checker.c $(TST_OBJS)
	./a.out

.PHONY: all clean fclean re
