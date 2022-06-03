/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_xX.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoch <mkoch@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:17:06 by mkoch             #+#    #+#             */
/*   Updated: 2022/02/09 16:19:17 by mkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_x(va_list vl, int shift)
{
	unsigned int	hex;
	int				add_length;

	add_length = 0;
	hex = va_arg(vl, int);
	ft_putnbr_hex(hex, shift);
	while (hex / 16)
	{
		hex = hex / 16;
		add_length++;
	}
	add_length++;
	return (add_length);
}

void	ft_putnbr_hex(unsigned long hex, int shift)
{
	if (hex >= 16)
	{
		ft_putnbr_hex(hex / 16, shift);
		if (hex % 16 > 9)
			ft_putchar_fd(hex % 16 + shift, 1);
		else
			ft_putnbr_fd(hex % 16, 1);
	}
	else if (hex % 16 > 9)
		ft_putchar_fd(hex % 16 + shift, 1);
	else
		ft_putnbr_fd(hex % 16, 1);
}
