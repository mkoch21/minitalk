/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoch <mkoch@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:30:55 by mkoch             #+#    #+#             */
/*   Updated: 2022/02/09 16:20:18 by mkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define  FT_PRINTF_H

# include <stdarg.h>
# include <limits.h>
# include "libft/libft.h"

int		ft_printf(const char *format, ...);
int		ft_printf_text(char c);
int		ft_printf_c(va_list vl);
int		ft_printf_s(va_list vl);
int		ft_printf_p(va_list vl);
int		ft_printf_d_i(va_list vl);
int		ft_printf_u(va_list vl);
int		ft_printf_x(va_list vl, int shift);
void	ft_putnbr_u(unsigned int n);
void	ft_putnbr_hex(unsigned long hex, int shift);
int		ft_if_percent(va_list vl, const char *ptr);
int		ft_if_space(void);

#endif