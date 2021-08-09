/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 14:58:58 by fcatinau          #+#    #+#             */
/*   Updated: 2021/08/09 17:46:57 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	verif_str_digit(char *s)
{
	while (ft_isdigit(*s) && *s)
		s++;
	if (!*s)
		return (TRUE);
	return (FALSE);
}

void	last_char(pid_t pid)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		usleep(20);
		if (kill(pid, SIGUSR2) == -1)
		{
			error_arg("Error PID\n");
			break ;
		}
	}
}

void	print_acknow(int num)
{
	(void)num;
	blue();
	ft_putstr_fd("Message received\n", 1);
	reset();
}

void	print_work(void)
{
	green();
	ft_putstr_fd("Client work \n", 1);
	reset();
}

int	main(int agc, char **agv)
{
	pid_t				pid;
	struct sigaction	sig;

	sig.sa_flags = 0;
	sig.sa_mask = 128;
	sigemptyset(&sig.sa_flags);
	sigaddset(&sig.sa_flags, SIGUSR1);
	if (agc < 2)
		return (error_no_arg());
	if (!verif_str_digit(agv[1]))
		return (error_arg("Error bad arguments need int\nex: 1384\n"));
	pid = ft_atoi(agv[1]);
	if (pid == 0)
		return (error_arg("Error PID\n"));
	if (!agv[2])
		return (error_arg("Error bad arguments need string\n"));
	sig.sa_handler = print_acknow;
	sigaction(SIGUSR1, &sig, NULL);
	print_work();
	if (send_string(pid, agv[2]))
		return (1);
	last_char(pid);
	pause();
	return (0);
}
