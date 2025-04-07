NAME = libft.a

CC = cc
FLAGS = -Wall -Werror -Wextra -I
INCLUDE = ../push_swap.h
OBJ_DIR = obj/
LIBFT = ft_atol.c ft_putstr_fd.c ft_calloc.c ft_strlen.c ft_substr.c
PRINTF = printf/utils_print.c printf/char_print.c printf/num_print.c printf/ft_printf.c

SRC = $(LIBFT) $(PRINTF)
OBJ = $(patsubst %.c, $(OBJ_DIR)%.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

$(OBJ_DIR)%.o: %.c
	mkdir -p $(@D)
	$(CC) $(FLAGS) $(INCLUDE) -c $^ -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONE: all clean fclean re