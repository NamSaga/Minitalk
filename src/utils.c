/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamisoa <rmamisoa@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:06:26 by rmamisoa          #+#    #+#             */
/*   Updated: 2024/12/24 13:06:27 by rmamisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minitalk.h"

void	ft_signal(int signal, void *handler, bool use_siginfo)
{
	struct sigaction	sa;

	ft_memset(&sa, 0, sizeof(sa));
	if (use_siginfo)
	{
		sa.sa_sigaction = handler;
		sa.sa_flags = SA_SIGINFO;
	}
	else
		sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	if (sigaction(signal, &sa, NULL) < 0)
	{
		ft_printf("Signal handler setup failed");
		exit(EXIT_FAILURE);
	}
}

void	ft_kill(pid_t pid, int signum)
{
	if (kill(pid, signum) != 0)
	{
		ft_putstr_fd(PIDERROR, STDOUT_FILENO);
		exit(EXIT_FAILURE);
	}
}

int	check_pid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_strchr("0123456789", str[i]))
		{
			ft_putstr_fd(PIDERROR, STDOUT_FILENO);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (ft_atoi(str));
}
