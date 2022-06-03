# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkoch <mkoch@student.21-school.ru>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/03 16:09:07 by mkoch             #+#    #+#              #
#    Updated: 2022/02/09 16:20:55 by mkoch            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c \
	ft_printf_text.c \
	ft_printf_c.c \
	ft_printf_s.c \
    ft_printf_d_i.c \
    ft_printf_p.c \
    ft_printf_u.c \
    ft_printf_x.c \
	ft_if_percent.c \
	ft_if_space.c

HEADER = ft_printf.h
LIBFT = libft/libft.a

OBJECTS = $(SRCS:%.c=%.o)

CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: $(NAME)

$(NAME): $(OBJECTS)
	$(MAKE) -C ./libft
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $?

%.o : %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJECTS)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
