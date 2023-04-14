#ifndef SO_LONG_H
# define SO_LONG_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "lib/MLX42/include/MLX42/MLX42.h"

# include <libft.h>
# include <get_next_line.h>
# include <ft_printf.h>

typedef struct s_map
{
	char 	**map_arr;
	int	width_x;
	int	height_y;
	int	count_e;
	int	count_p;
	int	count_c;

}	t_map;

#endif
