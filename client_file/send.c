/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 12:09:13 by fcatinau          #+#    #+#             */
/*   Updated: 2021/08/09 17:22:00 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	send_char(pid_t pid, char c)
{
	int	i;
	int	ret;
	int	signal;

	i = -1;
	ret = 0;
	while (++i < 8)
	{
		usleep(20);
		if (c & 0x080)
			signal = SIGUSR1;
		else
			signal = SIGUSR2;
		if (kill(pid, signal) == -1)
		{
			ret = error_arg("Error PID\n");
			break ;
		}
		c = c << 1;
	}
	return (ret);
}

int	send_string(pid_t pid, char *s)
{
	int	j;
	int	ret;

	j = -1;
	while (s[++j])
	{
		ret = send_char(pid, s[j]);
		if (ret)
			break ;
	}
	return (ret);
}
