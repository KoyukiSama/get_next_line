
PROJECT_NAME := libft
NAME         := libft.a

CC           := gcc
CFLAGS       := -Wall -Wextra -Werror

SRC_DIR := ../$(PROJECT_NAME)
SRC     := $(wildcard $(SRC_DIR)/*.c)
OBJ     := $(SRC:$(SRC_DIR)/%.c=$(SRC_DIR)/%.o)

TEST_MACROS := tester_macro.c
TEST_SRC := main_ctype.c main_mem.c main_stdlib.c main_str.c main_str2.c \
			main_fd.c main_lst_bonus.c
TEST_OUT := $(TEST_SRC:%.c=%.out)

PINK      := \033[38;5;13m
PINK_HOT  := \033[38;5;201m
RESET     := \033[0m

$(NAME): $(OBJ)
	@ar rcs $@ $^

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -c $^ -o $@

%.out: %.c $(NAME) $(TEST_MACROS)
	@$(CC) $(CFLAGS) $^ -L. -lft -o $@

test: $(NAME) $(TEST_OUT)

clean:
	@rm -f $(SRC_DIR)/*.o

fclean: clean
	@rm -f $(NAME)

testclean:
	@rm -f *.out

testre: testclean test clean

retest: testre fclean
	@i=1;
	@for outp in $(TEST_OUT); do \
	  printf "$(PINK)<3-----------|$(PINK_HOT) [TEST %d] : %s $(PINK)|---------------<3\n$(RESET)" "$$i" "$$outp"; \
	  valgrind --leak-check=full --track-origins=yes --show-reachable=yes --track-fds=yes ./$$outp; \
	  ./$$outp; \
	  i=$$((i+1)); \
	done
