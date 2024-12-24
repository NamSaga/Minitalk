/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamisoa <rmamisoa@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:34:57 by rmamisoa          #+#    #+#             */
/*   Updated: 2024/12/24 13:06:28 by rmamisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_server = BUSY;

static void	ft_msgcheck(int sig)
{
	fputs("\n\t✅ msg received ✅\n", stdout);
	exit(EXIT_SUCCESS);
}


static void	ft_servcheck(int sig)
{
	g_server = READY;
}

static void	send_char(char c, pid_t server)
{
	int	bit;

	bit = 0;
	while (bit < CHAR_BIT)
	{

		if (c & (0x80 >> bit))
			ft_kill(server, SIGUSR1);
		else
			ft_kill(server, SIGUSR2);
		bit++;

		while (BUSY == g_server)
			usleep(42);

		g_server = BUSY;
	}
}

int	main(int ac, char **av)
{
	pid_t	server;
	char	*msg;
	int		i;

	if (ac != 3)
	{
		fputs("Usage: ./client <server> \"msg\"\n", stderr);
		return (EXIT_FAILURE);
	}
	server = atoi(av[1]);
	msg = av[2];

	ft_signal(SIGUSR1, ft_servcheck, false);
	ft_signal(SIGUSR2, ft_msgcheck, false);

	i = 0;
	while (msg[i])
		send_char(msg[i++], server);
	send_char('\0', server);

	return (EXIT_SUCCESS);
}
