/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoch <mkoch@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:58:11 by mkoch             #+#    #+#             */
/*   Updated: 2022/02/10 13:42:54 by mkoch            ###   ########.fr       */
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

static int	ft_pow(int a, int b)
{
	int	res;
	int	i;

	res = 1;
	i = 1;
	while (i++ <= b)
		res = res * a;
	return (res);
}

static void	handle_sigusr(int sig, siginfo_t *siginfo, void *context)
{
	static int	i = 1;
	static int	ch = 0;

	(void)context;
	if (sig == SIGUSR2)
		ch = ch + (256 / ft_pow(2, i));
	i++;
	if (i == 9)
	{
		write(1, &ch, 1);
		usleep(100);
		if (ch == '\n')
			kill(siginfo->si_pid, SIGUSR1);
		i = 1;
		ch = 0;
	}
	return ;
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server process id = %d\n", getpid());
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&(sa.sa_mask));
	sigaddset(&(sa.sa_mask), SIGUSR1);
	sigaddset(&(sa.sa_mask), SIGUSR2);
	sa.sa_sigaction = &handle_sigusr;
	if (sigaction(SIGUSR1, &sa, NULL) != 0)
		write_exit("Sigaction error!\n");
	if (sigaction(SIGUSR2, &sa, NULL) != 0)
		write_exit("Sigaction error!\n");
	while (1)
		pause();
	return (0);
}
