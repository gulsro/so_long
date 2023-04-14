/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: gozturk <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/14 17:11:02 by gozturk       #+#    #+#                 */
/*   Updated: 2022/11/16 14:22:14 by gozturk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putnbr(int i)
{
	long int	n;
	int			len;

	len = 0;
	n = i;
	if (n < 0)
	{
		n = n * -1;
		write(1, "-", 1);
		len++;
	}
	if (n > 9)
	{
		len += ft_putnbr(n / 10);
	}
	n = n % 10;
	n = n + '0';
	len += write(1, &n, 1);
	return (len);
}
