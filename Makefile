
NAME	:= get_next_line

CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror -D BUFFER_SIZE=42

SRC			:= get_next_line.c get_next_line_utils.c
OBJ_SRC		:= $(OBJ_SRC:.c=.o)

ifdef BONUS
OBJ := $(OBJ_SRC) $(OBJ_SRC_BONUS)
else
OBJ := $(OBJ_SRC)
endif

all: $(NAME)
	CC CFLAGS SRC -o $(NAME)
bonus:
	$(MAKE) BONUS=1 all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_SRC) $(OBJ_SRC_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
