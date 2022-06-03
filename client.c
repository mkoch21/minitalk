/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoch <mkoch@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:57:59 by mkoch             #+#    #+#             */
/*   Updated: 2022/02/10 13:16:58 by mkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "ft_printf/ft_printf.h"

static void	write_exit(char *str)
{
	write(1, str, ft_strlen(str));
	exit(1);
}

static void	send_signal(pid_t server_pid, int sig)
{	
	if (!((sig == SIGUSR1) || (sig == SIGUSR2)))
		write_exit("Wrong signal!\n");
	if (kill(server_pid, sig) != 0)
		write_exit("Signal not sent!\n");
	usleep(100);
	return ;
}

static void	send_char(char ch, int server_pid)
{
	int	j;

	j = 128;
	while (j >= 1)
	{
		if ((ch & j) != j)
			send_signal(server_pid, SIGUSR1);
		else
			send_signal(server_pid, SIGUSR2);
		j = j / 2;
		usleep(100);
	}
	return ;
}

static int	check_pid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((((str[i] < '0') || (str[i] > '9'))) && (str[i] != '-'))
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char	**argv)
{
	int					server_pid;
	int					i;

	if (argc != 3)
		write_exit("Input error!\n");
	if (check_pid (argv[1]))
		write_exit("Wrong pid!\n");
	server_pid = ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i])
		send_char(argv[2][i++], server_pid);
	send_char('\n', server_pid);
	return (0);
}
