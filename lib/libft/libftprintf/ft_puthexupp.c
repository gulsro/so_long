/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_puthexupp.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: gozturk <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/14 17:11:43 by gozturk       #+#    #+#                 */
/*   Updated: 2022/11/16 14:23:50 by gozturk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_puthexupp(unsigned int i)
{
	int	len;

	len = 0;
	if (i > 15)
		len += ft_puthexupp(i / 16);
	i = i % 16;
	if (i < 10)
		i += 48;
	else
		i += 'A' - 10;
	return (len + write(1, &i, 1));
}
