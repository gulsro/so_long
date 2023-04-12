NAME = so_long

SRC = main.c  

HEADER = -I lib/MLX42/include/MLX42

CC = gcc

OBJ = $(SRC:.c= .o)

CLAGS = -Werror -Wextra -Wall

LIBMLX_DIR = ./lib/MLX42

LIBMLX = $(LIBMLX_DIR)/build/libmlx42.a -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit

all: $(NAME) libmlx

libmlx:
	@cmake $(LIBMLX_DIR) -B $(LIBMLX_DIR)/build && make -C $(LIBMLX_DIR)/build -j4

$(NAME):	$(OBJ)
		$(CC) $(CFLAGS) $(LIBMLX) -o $(NAME) $(OBJ) $(HEADER)

%.o: %.c 
		$(CC) $(CFLAGS) $(HEADER) -c $< -o $(<:.c=.o)

clean:
		rm -f $(LIBMLX_DIR)
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)
		rm -f $(LIBMLX_DIR)

re:		fclean all

.PHONY:	all clean fclean re bonus



