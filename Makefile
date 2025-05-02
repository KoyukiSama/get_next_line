
NAME	:= libft.a
CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror

SRC		:= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
			ft_isprint.c ft_toupper.c ft_tolower.c ft_toint.c \
			ft_tochar.c ft_isspace.c \
			ft_memset.c ft_memcpy.c ft_memmove.c ft_memchr.c \
			ft_memcmp.c ft_bzero.c ft_calloc.c \
			ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c \
			ft_strrchr.c ft_strcmp.c ft_strncmp.c ft_strnstr.c \
			ft_strdup.c ft_str_mallocpy.c ft_substr.c ft_strjoin.c \
			ft_strtrim.c ft_split.c ft_atoi.c ft_isdigit.c ft_itoa.c ft_strmapi.c \
			ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
			ft_putnbr_fd.c

SRC_BONUS	:= ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
				ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
				ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJ 		:= $(SRC:.c=.o)

OBJ_BONUS 	:= $(SRC_BONUS:.c=.o)

ifdef BONUS
OBJ := $(OBJ) $(OBJ_BONUS)
endif

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

bonus:
	$(MAKE) BONUS=1 all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
