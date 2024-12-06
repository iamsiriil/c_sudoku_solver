NAME = sslib.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

RM = rm -f

SOURCE = ss_atoi.c    \
	 ss_isdigit.c \
	 ss_isspace.c

OBJS = $(SOURCE:.c=.o)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)

all: $(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
