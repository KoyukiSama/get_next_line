
CC          := gcc
CFLAGS      := -Wall -Wextra -Werror -D BUFFER_SIZE=42

SRC_DIR		:= ..

SRC     	:= $(SRC_DIR)/get_next_line_utils.c
OBJ     	:= $(SRC:$(SRC_DIR)/%.c=$(SRC_DIR)/%.o)

TEST_MACROS := tester_macro.c

TEST_SRC 	:= test_ft_append.c
TEST_OUT 	:= $(TEST_SRC:%.c=%.out)

PINK      	:= \033[38;5;13m
PINK_HOT  	:= \033[38;5;201m
RESET     	:= \033[0m

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -c $^ -o $@

%.out: %.c $(TEST_MACROS) $(OBJ)
	@$(CC) $(CFLAGS) $^ -o $@

test: $(TEST_OUT)

clean:
	@rm -f $(SRC_DIR)/*.o

testclean:
	@rm -f *.out

retest: testclean test clean
	@i=1;
	@for outp in $(TEST_OUT); do \
	  printf "$(PINK)<3-----------|$(PINK_HOT) [TEST %d] : %s $(PINK)|---------------<3\n$(RESET)" "$$i" "$$outp"; \
	  valgrind --quiet --leak-check=full --track-origins=yes --show-reachable=yes --track-fds=yes ./$$outp; \
	  i=$$((i+1)); \
	done
