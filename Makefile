NAME = fdf
CC = gcc
FLAGS = -Wall -Werror -Wextra
INCL = fdf.h
SRC_DIR = src/
SRC = $(addprefix $(SRC_DIR), $(C_FILES))
OBJ = $(SRC:.c=.o)
LIB = libft/libft.a
C_FILES = main.c utils.c parse.c
MLX = minilibx_macos/libmlx.a
MLX_LNK = -L minilibx_macos/ -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ) $(LIB) $(MLX)
	$(CC) $(OBJ) $(LIB) $(MLX_LNK) -o $(NAME)

%.o: %.c $(INCL)
	$(CC) -c $(FLAGS) $< -o $@

$(LIB):
	make -C libft

$(MLX):
	make -C minilibx_macos

clean:
	make -C libft/ clean
	rm -rf $(OBJ)
	make -C minilibx_macos clean

fclean:
	make -C libft/ fclean
	rm -rf $(NAME)

re: fclean all