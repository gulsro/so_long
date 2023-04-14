/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_puthexlow.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: gozturk <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/14 17:12:04 by gozturk       #+#    #+#                 */
/*   Updated: 2022/11/16 14:42:20 by gozturk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_puthexlow(unsigned int i)
{
	int	len;

	len = 0;
	if (i > 15)
		len += ft_puthexlow(i / 16);
	i = i % 16;
	if (i < 10)
		i += 48;
	else
		i += 'a' - 10;
	return (len + write(1, &i, 1));
}
