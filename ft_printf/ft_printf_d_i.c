/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d_i.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoch <mkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:17:12 by mkoch             #+#    #+#             */
/*   Updated: 2021/12/03 15:01:21 by mkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_d_i(va_list vl)
{
	int		nbr;
	int		add_length;

	add_length = 0;
	nbr = va_arg(vl, int);
	ft_putnbr_fd(nbr, 1);
	if (nbr < 0)
		add_length++;
	while (nbr / 10)
	{
		nbr = nbr / 10;
		add_length++;
	}
	add_length++;
	return (add_length);
}
