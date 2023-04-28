/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_exit.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: gozturk <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/28 11:39:19 by gozturk       #+#    #+#                 */
/*   Updated: 2023/04/28 12:44:03 by gozturk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_exit(char *error_msg, int exit_code)
{
	perror(error_msg);
	exit(exit_code);
}

void	ft_error(char *error_msg)
{
	perror(error_msg);
}
