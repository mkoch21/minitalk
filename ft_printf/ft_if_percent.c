/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoch <mkoch@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:17:12 by mkoch             #+#    #+#             */
/*   Updated: 2022/02/09 16:20:08 by mkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_if_percent(va_list vl, const char *ptr)
{
	int	add_length;

	add_length = 0;
	if ((*ptr == 'c'))
		add_length = add_length + ft_printf_c(vl);
	else if (*ptr == 's')
		add_length = add_length + ft_printf_s(vl);
	else if (*ptr == 'p')
		add_length = add_length + ft_printf_p(vl);
	else if ((*ptr == 'd') || (*ptr == 'i'))
		add_length = add_length + ft_printf_d_i(vl);
	else if (*ptr == 'u')
		add_length = add_length + ft_printf_u(vl);
	else if (*ptr == 'x')
		add_length = add_length + ft_printf_x(vl, 87);
	else if (*ptr == 'X')
		add_length = add_length + ft_printf_x(vl, 55);
	else if (*ptr == '%')
	{
		ft_putchar_fd('%', 1);
		add_length++;
	}
	return (add_length);
}
