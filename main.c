#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		exit(1);
	fd = open_file(argc, argv);
	read_pass_arr(fd);

	char *map = "banana";
    char *line = "lemonade";
    printf("new string is: %s\n", append_line_to_map(map, line));

}
