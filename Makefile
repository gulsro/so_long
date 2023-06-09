NAME	= so_long
CFLAGS	= -Wextra -Wall -Werror
LIBMLX	= ./lib/MLX42
LIBFT	= ./lib/libft/libft.a

HEADERS	= -I ./lib/libft/ -I $(LIBMLX)/include/
#LIBS	= $(LIBMLX)/build/libmlx42.a -Iinclude -lglfw -L"/opt/homebrew/Cellar/glfw/3.3.8/lib/"
LIBS   = $(LIBMLX)/build/libmlx42.a -Iinclude -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit
SRCS	= ./src/main.c \
		  ./src/map_array.c \
		  ./src/error_exit.c \
		  ./src/map_check.c \
		  ./src/map_utils.c \
		  ./src/walkable_map.c \
		  ./src/init_map.c \
		  ./src/image.c \
		  ./src/keys.c \
		  ./src/moves_utils.c \
		  ./src/moves.c \
		  ./src/free.c \
		  ./src/protect.c
OBJS	= $(SRCS:.c=.o)

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	$(MAKE) -C ./lib/libft
	@$(CC) $(OBJS) $(CFLAGS) $(LIBFT) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build
	@rm -f ./lib/libft/*.o ./lib/libft/*.a
	@rm -f ./lib/libft/libftprintf/*.o 

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx
