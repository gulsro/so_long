#include "so_long.h"

//int	map_height(char *buf)
int	open_file(int argc, char **argv)
{
	int     fd;


        fd = open(argv[1], O_RDONLY);
        if (fd < 0)
        {
                perror("Map file can not be opened");
                exit(1);
        }
        else if (fd == 0)
        {
                perror("Map file is empty");
                exit(1);
	}
	return (fd);
}
char **read_pass_arr(int fd)
{
	char	*buf;

        while (1)
        {
                read(fd, )
        }
}
