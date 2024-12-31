/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamisoa <rmamisoa@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 11:45:12 by rmamisoa          #+#    #+#             */
/*   Updated: 2024/12/26 10:38:49 by rmamisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "lib/printf/ft_printf.h"
# include <limits.h>
# include <signal.h>
# include <stdbool.h>
# include <unistd.h>

# define INITIAL_BUFFER_SIZE 1024
# define BUFFER_MULTIPLIER 2

typedef struct s_tab
{
	char	*buffer;
	int		index;
	int		size;
}			t_tab;

void		init_tab(t_tab *msg_buf);
void		expand_tab(t_tab *msg_buf);
void		handle_msg(t_tab *msg_buf, char c,
				pid_t client);
void		free_tab(t_tab *msg_buf);

void		ft_signal(int signal, void *handler, bool use_siginfo);
int			check_pid(char *str);
void		ft_kill(pid_t pid, int signum);

void		*ft_memset(void *s, int c, size_t n);
int			ft_atoi(const char *nptr);
char		*ft_strchr(const char *s, int c);

#endif
