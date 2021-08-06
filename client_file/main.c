/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 14:58:58 by fcatinau          #+#    #+#             */
/*   Updated: 2021/08/06 17:21:38 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

#include <stdio.h>
void	send_char(pid_t pid, char *s)
{
	int i;

	i = -1;
	while (*s)
	{
		//printf("----- %c -----\n", *s);
		while (++i < 8)
		{
			//printf("%d|j'ai envoye ", i);
			if (*s & 0x080)
			{
				write(1, "1\n", 2);
				if (kill(pid, SIGUSR1) == -1)
					error_arg("Error PID\n");
			}
			else
			{
				write(1,"0\n", 2);
				if (kill(pid, SIGUSR2) == -1)
					error_arg("Error PID\n");
			}
			*s = *s << 1;
			usleep(10);
		}
		i = 0;
		++s;
	}
}

void	test(pid_t pid)
{
	int i;
	int j;
	char s[4] = "c\0";

	j = 0;
	i = -1;
	while (s[j])
	{
		printf("----- %c -----\n", s[j]);
		while (++i < 8)
		{
			printf("%d|j'ai envoye ", i);
			if (s[j] & 0x080)
			{
				printf("1\n");
				if (kill(pid, SIGUSR1) == -1)
					error_arg("Error PID\n");
			}
			else
			{
				printf("0\n");
				if (kill(pid, SIGUSR2) == -1)
					error_arg("Error PID\n");
			}
			*s = *s << 1;
			usleep(10);
		}
		i = -1;
		j++;
	}
}

int	main(int agc, char **agv)
{
	pid_t pid;
	if (agc < 2)
		return (error_no_arg());
	if (!verif_str_digit(agv[1]))
		return (error_arg("Error bad arguments need int\nex: 1384\n"));
	pid = ft_atoi(agv[1]);
	if (pid == 0)
		return (error_arg("Error PID\n"));
	if (!agv[2])
		return (error_arg("Error bad arguments need string\n"));
	green();
	ft_putstr_fd("Client work \n", 1);
	reset();

	str_treatment(agv[2]);
	//test(pid);
	send_char(pid, agv[2]);
	return (0);
}
