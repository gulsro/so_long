/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putaddr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: gozturk <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/16 12:45:00 by gozturk       #+#    #+#                 */
/*   Updated: 2022/11/16 14:41:55 by gozturk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putaddr(unsigned long i)
{
	int	len;

	len = 0;
	if (i > 15)
		len += ft_putaddr(i / 16);
	i = i % 16;
	if (i < 10)
		i += '0';
	else
		i += 'a' - 10;
	return (len + write(1, &i, 1));
}
