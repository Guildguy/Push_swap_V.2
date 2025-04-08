NAME = push_swap

CC = cc
FLAGS = -Wall -Wextra -Werror -I
LIBFT = Libft/libft.a
OBJ_DIR = obj/
FILE_DIR = Files/
MAIN = $(FILE_DIR)main/ft_lstlast.c $(FILE_DIR)main/ft_lstsize.c $(FILE_DIR)main/p_split.c $(FILE_DIR)main/populate_stack.c $(FILE_DIR)main/push_utils.c $(FILE_DIR)main/push_swap.c
MOVE = $(FILE_DIR)moves/move_utils.c $(FILE_DIR)moves/push.c $(FILE_DIR)moves/reverse.c $(FILE_DIR)moves/rotate.c $(FILE_DIR)moves/swap.c
SORTER = $(FILE_DIR)sorter/full_sort.c $(FILE_DIR)sorter/prep_a.c $(FILE_DIR)sorter/prep_b.c $(FILE_DIR)sorter/small_sort.c

SRC = $(MAIN) $(MOVE) $(SORTER)
OBJ = $(patsubst $(FILE_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(FLAGS) push_swap.h $^ -o $@

$(LIBFT):
	make -C ./Libft

$(OBJ_DIR)%.o: $(FILE_DIR)%.c
	mkdir -p $(@D)
	$(CC) $(FLAGS) push_swap.h -c $< -o $@

test: $(NAME)
	$(eval ARG = $(shell shuf -i 0-1000 -n 500))
	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

clean:
	rm -rf $(OBJ_DIR)
	make clean -C ./Libft

fclean: clean
	rm -rf $(NAME)
	rm -rf $(LIBFT)

re: fclean all

.PHONY: all test clean fclean re
