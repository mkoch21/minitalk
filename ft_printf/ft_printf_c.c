/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoch <mkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:48:53 by mkoch             #+#    #+#             */
/*   Updated: 2021/12/03 15:00:59 by mkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_c(va_list vl)
{
	char	c;
	int		add_length;

	add_length = 0;
	c = va_arg(vl, int);
	ft_putchar_fd(c, 1);
	add_length++;
	return (add_length);
}
