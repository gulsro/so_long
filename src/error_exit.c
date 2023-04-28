/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_exit.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: gozturk <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/28 11:39:19 by gozturk       #+#    #+#                 */
/*   Updated: 2023/04/28 18:25:10 by gozturk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_error(char *error_msg)
{
	int	i;

	i = 0;
	while (error_msg[i])
	{
		write(2, &error_msg[i], 1);
		i++;
	}
}

void	ft_exit(char *error_msg)
{
	ft_error(error_msg);
	exit(1);
}
