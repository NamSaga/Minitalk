/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamisoa <rmamisoa@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 11:45:12 by rmamisoa          #+#    #+#             */
/*   Updated: 2024/12/24 13:06:23 by rmamisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "printf/ft_printf.h"
# include "libft/libft.h"
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <limits.h>
# include <stdbool.h>

# define BUSY	0
# define READY	1
# define ERRMSG_CLIENT "\e[33mInvalid input\n./client <PID> 'message'\e[0m\n"	
# define ERRMSG_SERVER "\e[33mInValid input\n./server \e[0m\n"	
# define MSGCHECK "\e[32mCheck!\e[0m\n"
# define PIDERROR "\e[33mTransmission Error\e[0m\n"

void	ft_signal(int signal, void *handler, bool use_siginfo);
int		check_pid(char *str);
void	ft_kill(pid_t pid, int signum);

#endif
