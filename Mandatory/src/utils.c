/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamisoa <rmamisoa@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:06:26 by rmamisoa          #+#    #+#             */
/*   Updated: 2024/12/26 10:38:50 by rmamisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	check_pid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_strchr("0123456789", str[i]))
		{
			ft_printf("PID error.\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (ft_atoi(str));
}

void	init_msg(t_tab *msg_buf)
{
	msg_buf->buffer = malloc(INITIAL_BUFFER_SIZE);
	if (!msg_buf->buffer)
		exit(EXIT_FAILURE);
	msg_buf->index = 0;
	msg_buf->size = INITIAL_BUFFER_SIZE;
}

void	expand_tab(t_tab *msg_buf)
{
	char	*new_buffer;
	int		i;

	new_buffer = malloc(msg_buf->size * BUFFER_MULTIPLIER);
	if (!new_buffer)
	{
		ft_printf("Memory allocation failed\n");
		free_tab(msg_buf);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < msg_buf->index)
	{
		new_buffer[i] = msg_buf->buffer[i];
		i++;
	}
	free(msg_buf->buffer);
	msg_buf->buffer = new_buffer;
	msg_buf->size *= BUFFER_MULTIPLIER;
}

void	handle_msg(t_tab *msg_buf, char c, pid_t client)
{
	if (c == '\0')
	{
		msg_buf->buffer[msg_buf->index] = '\0';
		ft_printf("%s\n", msg_buf->buffer);
		msg_buf->index = 0;
		ft_kill(client, SIGUSR2);
	}
	else
	{
		if (msg_buf->index >= msg_buf->size - 1)
			expand_tab(msg_buf);
		msg_buf->buffer[msg_buf->index++] = c;
	}
}

void	free_tab(t_tab *msg_buf)
{
	free(msg_buf->buffer);
}
