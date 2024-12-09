NAME 	= sslib.a

CC 	= gcc
CFLAGS 	= -Wall -Wextra -Werror

AR 	= ar rcs

RM 	= rm -f
RMDIR	= rm -rf

SRC_DIR = ./src/
SOURCE 	= $(wildcard $(SRC_DIR)*.c) 

OBJ_DIR = ./obj/
OBJS 	= $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SOURCE))

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)

clean:
	@$(RM) $(OBJS)
	@$(RMDIR) $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
