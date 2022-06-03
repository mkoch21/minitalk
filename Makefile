# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkoch <mkoch@student.21-school.ru>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/03 16:09:07 by mkoch             #+#    #+#              #
#    Updated: 2022/02/10 12:01:22 by mkoch            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printfminitalk.a

SRCS =  client.c server.c

SRCS_B =  client_bonus.c server_bonus.c

PRINTF = ft_printf/libftprintf.a

OBJ = $(SRCS:%.c=%.o)

OBJ_B = $(SRCS_B:%.c=%.o)

CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: $(NAME) client server

$(NAME): $(OBJ)
	$(MAKE) -C ./ft_printf

client: client.o Makefile
	$(CC) $(CFLAGS) $(PRINTF) client.o -o client
server: server.o Makefile
	$(CC) $(CFLAGS) $(PRINTF) server.o -o server

bonus: $(NAME_B) client_bonus server_bonus

$(NAME_B): $(OBJ_B)
	$(MAKE) -C ./ft_printf

client_bonus: client_bonus.o Makefile
	$(CC) $(CFLAGS) $(PRINTF) client_bonus.o -o client_bonus
server_bonus: server_bonus.o Makefile
	$(CC) $(CFLAGS) $(PRINTF) server_bonus.o -o server_bonus

clean:
	$(MAKE) clean -C ./ft_printf
	$(RM) $(OBJ) $(OBJ_B)

fclean: clean
	$(MAKE) fclean -C ./ft_printf
	$(RM) client server client_bonus server_bonus

re: fclean all

.PHONY: all clean fclean re bonus