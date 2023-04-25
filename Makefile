NAME	= so_long
CFLAGS	= -Wextra -Wall -Werror -g #-fsanitize=address
LIBMLX	= ./lib/MLX42
LIBFT	= ./lib/libft/libft.a

HEADERS	= -I ./lib/libft/ -I $(LIBMLX)/include/
LIBS	= $(LIBMLX)/build/libmlx42.a -Iinclude -lglfw -L"/opt/homebrew/Cellar/glfw/3.3.8/lib/"
#LIBS   = $(LIBMLX)/build/libmlx42.a -Iinclude -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit
SRCS	= main.c \
		  map_array.c \
		  error_exit.c \
		  map_check.c \
		  map_utils.c \
		  walkable_map.c \
		  init_map.c \
		  image.c \
		  keys.c \
		  keys_utils.c \
		  moves.c
OBJS	= $(SRCS:.c=.o)

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	$(MAKE) -C ./lib/libft
	@$(CC) $(OBJS) $(LIBFT) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build
	@rm -f ./lib/libft/*.o ./lib/libft/*.a
	@rm -f ./lib/libft/libftprintf/*.o 

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx
