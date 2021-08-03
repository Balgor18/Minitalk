/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 09:42:59 by fcatinau          #+#    #+#             */
/*   Updated: 2021/08/03 11:48:04 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	print_pid(void)
{
	int	pid;

	pid = getpid();
	ft_putstr_fd("PID : ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
}

void	handler(int num)
{
	(void)num;
	ft_putstr_fd("I won't die!\n", 1);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = handler;
	while (1)
	{
		print_pid();
		//sigaction(SIGINT, &sa, NULL);
		signal(SIGTERM, handler);
		sleep(1);
	}
	//waitpid();
	return (0);
}
