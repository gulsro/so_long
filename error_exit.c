#include "so_long.h"

void	ft_exit(char *error_msg, int exit_code)
{
	perror(error_msg);
	exit(exit_code);
}
