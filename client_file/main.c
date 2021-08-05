/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 14:58:58 by fcatinau          #+#    #+#             */
/*   Updated: 2021/08/05 18:32:06 by fcatinau         ###   ########.fr       */
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
		printf("----- %c -----\n", *s);
		while (++i < 8)
		{
			printf("%d|j'ai envoye ", i);
			if (*s & 0x080)
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
			//sleep(1);
		}
		i = 0;
		++s;
	}
}

/*void	test(char *s)
{

}*/

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
	//test(agv[2]);
	send_char(pid, agv[2]);
	return (0);
}
