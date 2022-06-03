/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoch <mkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:17:16 by mkoch             #+#    #+#             */
/*   Updated: 2021/12/03 15:08:54 by mkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_p(va_list vl)
{
	unsigned long	ptr;
	int				add_length;

	add_length = 0;
	ptr = va_arg(vl, unsigned long);
	ft_putchar_fd('0', 1);
	ft_putchar_fd('x', 1);
	add_length = add_length + 2;
	ft_putnbr_hex(ptr, 87);
	while (ptr / 16)
	{
		ptr = ptr / 16;
		add_length++;
	}
	add_length++;
	return (add_length);
}
