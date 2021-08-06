/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 09:42:59 by fcatinau          #+#    #+#             */
/*   Updated: 2021/08/06 17:24:22 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

//#define ONE		SIGUSR1
//#define ZERO	SIGUSR2
#define BUFFER	1024

#include <stdio.h>
void	print_pid(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putstr_fd("PID : ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
}

void	receive(int num)
{
	static char		c = 0;
	//static char		str[BUFFER] = "";
	static size_t	char_bite = 0;

	if (num == SIGUSR1)
		c = (c << 1) + 1;
	else if (num == SIGUSR2)
		c = (c << 1);
	if (++char_bite == 8)
	{
		write (1, &c, 1);
		//*str = c;
		//ft_putstr_fd(str , 1);
		//ft_putchar_fd('\n', 1);
		char_bite = 0;
		c = 0;
		//++*str;
	}
	//ft_putnbr_fd(char_bite, 1);
	//ft_putchar_fd('\n', 1);
}

int	main(void)
{
	struct sigaction	sigac;// problem

	sigac.sa_handler = receive;
	sigemptyset(&sigac.sa_mask);
	//sigac.sa_flags = 0;
	if (sigaction(SIGUSR1, &sigac , NULL)== -1)
		return (error_arg("Error positioning signal"));
	if (sigaction(SIGUSR2, &sigac , NULL)== -1)
		return (error_arg("Error positioning signal"));
	print_pid();
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
