
CC           := gcc
CFLAGS       := -Wall -Wextra -Werror

SRC     := $(wildcard ../*.c)
OBJ     := $(SRC:$(SRC_DIR)/%.c=$(SRC_DIR)/%.o)

TEST_MACROS := tester_macro.c
TEST_SRC := test_ft_append.c
TEST_OUT := $(TEST_SRC:%.c=%.out)

PINK      := \033[38;5;13m
PINK_HOT  := \033[38;5;201m
RESET     := \033[0m

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
