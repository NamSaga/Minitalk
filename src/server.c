/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamisoa <rmamisoa@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 07:58:17 by rmamisoa          #+#    #+#             */
/*   Updated: 2024/12/24 11:16:29 by rmamisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void		ft_handler(int sig, siginfo_t *info, void *more_info)
{
	static char		c;
	static int		bit;
	static pid_t	client;

	(void)more_info;
	if (info->si_pid)
		client = info->si_pid;
	if (sig == SIGUSR1)
		c |= (0b10000000 >> bit);
	else if (sig == SIGUSR2)
		c &= ~(0x80 >> bit);
	bit++;
	if (bit == CHAR_BIT)
	{
		bit = 0;
		if ('\0' == c)
		{
			write(STDOUT_FILENO, "\n", 1);
			ft_kill(client, SIGUSR2);
			c = 0;
			return ;
		}
		write(STDOUT_FILENO, &c, 1);
		c = 0;
	}
	ft_kill(client, SIGUSR1);
}

int	main(int ac, char **av)
{
	(void)av;
	if (ac != 1)
	{
		ft_putstr_fd(ERRMSG_SERVER, STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	ft_printf("Server PID: %d\n", getpid());
	ft_signal(SIGUSR1, ft_handler, true);
	ft_signal(SIGUSR2, ft_handler, true);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
