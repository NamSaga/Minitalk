/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamisoa <rmamisoa@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 07:58:17 by rmamisoa          #+#    #+#             */
/*   Updated: 2024/12/26 10:38:45 by rmamisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

static t_tab	g_msg_buffer;

static void	process_msg(char c, pid_t client)
{
	handle_msg(&g_msg_buffer, c, client);
}

static void	ft_handler(int sig, siginfo_t *info, void *context)
{
	static char		c;
	static int		bit;
	static pid_t	client;

	(void)context;
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
		process_msg(c, client);
		c = 0;
	}
	ft_kill(client, SIGUSR1);
}

int	main(int ac, char **av)
{
	(void)av;
	if (ac != 1)
	{
		ft_printf("Invalid Server Input\n");
		return (EXIT_FAILURE);
	}
	init_msg(&g_msg_buffer);
	ft_printf("Server PID: %d\n", getpid());
	ft_signal(SIGUSR1, ft_handler, true);
	ft_signal(SIGUSR2, ft_handler, true);
	while (1)
		pause();
	free_tab(&g_msg_buffer);
	return (EXIT_SUCCESS);
}
