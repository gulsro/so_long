NAME = so_long

SRC = main.c  

HEADER = -I ./libs/MLX42/include/MLX42/

CC = gcc

OBJ = $(SRC:.c= .o)

CLAGS = -Werror -Wextra -Wall

LIBMLX_DIR = libs/MLX42

LIBMLX = libmlx42.a

all: $(NAME)

$(NAME):	$(OBJ)
		cmake  $(LIBMLX_DIR)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(HEADER) $(LIBMLX_DIR)/$(LIBMLX)

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



