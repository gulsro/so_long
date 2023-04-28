/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_array.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: gozturk <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/28 11:44:16 by gozturk       #+#    #+#                 */
/*   Updated: 2023/04/28 12:10:50 by gozturk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen_protect(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	open_file(char *argv)
{
	int	fd;

	if (ft_strncmp(argv + ft_strlen(argv) - 4, ".ber", 4) != 0)
	{
		ft_exit("Bad map file extension", 1);
	}
	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		ft_exit("Map file can not be opened", 1);
	}
	else if (fd == 0)
	{
		ft_exit("Map file is empty", 1);
	}
	return (fd);
}

static void	exit_free(char *error_msg, int exit_code, char *map)
{
	free(map);
	perror(error_msg);
	exit(exit_code);
}

static char	*append_line_to_map(char *map, char *line)
{
	int		line_i;
	int		map_i;
	char	*appended;

	if (map == NULL)
		map = protect_mem(ft_calloc((ft_strlen_protect(line) + 1),
					sizeof(char)));
	appended = protect_mem(ft_calloc(sizeof(char), ft_strlen_protect(map)
				+ ft_strlen_protect(line) + 1));
	if (!appended)
		exit_free("Memory allocation", 1, map);
	map_i = 0;
	while (map[map_i] != '\0')
	{
		appended[map_i] = map[map_i];
		map_i++;
	}
	line_i = 0;
	while (line[line_i] != '\0')
		appended[map_i++] = line[line_i++];
	appended[map_i] = '\0';
	if (line)
		free(line);
	return (free(map), appended);
}

void	make_map_arr(t_map *my_map, int fd)
{
	char	*map;
	char	*line;

	map = NULL;
	line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map = append_line_to_map(map, line);
		if (!map)
			ft_exit("Error\nMap_arr cant be made.", 1);
	}
	my_map->map_arr = ft_split(map, '\n');
	if (!my_map->map_arr)
		ft_exit("Error\nMap_arr failed.", 1);
	free(map);
}
