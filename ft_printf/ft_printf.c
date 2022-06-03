/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoch <mkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:17:20 by mkoch             #+#    #+#             */
/*   Updated: 2021/12/06 15:49:41 by mkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		length;
	int		i;
	va_list	vl;

	length = 0;
	i = 0;
	va_start(vl, format);
	while (*(format + i))
	{
		if (*(format + i) != '%')
			length = length + ft_printf_text(*(format + i));
		else
		{
			i++;
			if ((*(format + i) == ' '))
			{
				length = length + ft_if_space();
				i++;
			}
			length = length + ft_if_percent(vl, &(*(format + i)));
		}
		i++;
	}
	va_end(vl);
	return (length);
}
