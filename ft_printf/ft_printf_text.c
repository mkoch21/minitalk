/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_text.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoch <mkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:52:05 by mkoch             #+#    #+#             */
/*   Updated: 2021/12/03 15:02:25 by mkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_text(char c)
{
	int	add_length;

	add_length = 0;
	ft_putchar_fd(c, 1);
	add_length++;
	return (add_length);
}
