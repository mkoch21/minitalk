/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoch <mkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:17:10 by mkoch             #+#    #+#             */
/*   Updated: 2021/12/03 15:09:57 by mkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_u(va_list vl)
{
	unsigned int	nbr;
	int				add_length;

	add_length = 0;
	nbr = va_arg(vl, unsigned int);
	while (nbr > 4294967295)
		nbr = nbr - 4294967295 - 1;
	if (nbr < 0)
		nbr = nbr + 4294967295;
	ft_putnbr_u(nbr);
	while (nbr / 10)
	{
		nbr = nbr / 10;
		add_length++;
	}
	add_length++;
	return (add_length);
}

void	ft_putnbr_u(unsigned int n)
{
	if (n >= 10)
	{
		ft_putnbr_u(n / 10);
		ft_putchar_fd(n % 10 + '0', 1);
	}
	if (n < 10)
		ft_putchar_fd(n % 10 + '0', 1);
}
