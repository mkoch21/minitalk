/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoch <mkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:49:01 by mkoch             #+#    #+#             */
/*   Updated: 2021/12/03 15:02:12 by mkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_s(va_list vl)
{
	char	*str;
	int		add_length;

	add_length = 0;
	str = va_arg(vl, char *);
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		add_length = add_length + 6;
	}
	else
	{
		ft_putstr_fd(str, 1);
		add_length = add_length + ft_strlen(str);
	}
	return (add_length);
}
