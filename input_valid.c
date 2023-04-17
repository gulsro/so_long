#include "so_long.h"

//int	map_height(char *buf)

int	ft_strlen_protect(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	open_file(char **argv)
{
	int     fd;

	fd = open(argv[1], O_RDONLY);
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

char	*append_line_to_map(char *map, char *line)
{
	int		line_i;
	int		map_i;
	char	*appended;

	if (map == NULL)
	{
		map = ft_calloc(sizeof(char), (ft_strlen_protect(line) + 1));
		if (map == NULL)
			ft_exit("Map calloc failed.", 1);
	}
	appended = ft_calloc(sizeof(char), ft_strlen_protect(map) + ft_strlen_protect(line) + 1);
	if (appended == NULL)
	{
		free(map);
		ft_exit("Appended calloc failed.", 1);
	}
	map_i = -1;
	while (map[map_i++] != '\0')
		appended[map_i] = map[map_i];
	line_i = 0;
	while (line[line_i] != '\0')
		appended[map_i++] = line[line_i++];
	appended[map_i] = '\0';
	return (free(map), appended);
}

char	**make_map_arr(int fd)
{
	char	**map_arr;
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
	}
	map_arr = ft_split(map, '\n');
	if (!map_arr)
		ft_exit("Map_arr failed.", 1);
	return (map_arr);
}
