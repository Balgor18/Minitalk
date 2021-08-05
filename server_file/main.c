/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 09:42:59 by fcatinau          #+#    #+#             */
/*   Updated: 2021/08/05 19:32:52 by fcatinau         ###   ########.fr       */
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
	static char		str[BUFFER] = "";
	static size_t	char_bite = 0;

	//printf("--------- %zu ---------\n", char_bite);
	//printf("char %d\n", c);
	if (num == SIGUSR1)
	{
		//printf("\nc avant 1 %d\n", c);
		c = (c >> 1) + 1;
		//printf("\nc apres 1 %d\n", c);
	}
	else if (num == SIGUSR2)
	{
		//printf("\nc avant 0 %d\n", c);
		c = (c >> 1);
		//printf("\nc apres 0 %d\n", c);
	}
	if (++char_bite == 8)
	{
		*str = c;
		ft_putstr_fd(str , 1);
		ft_putchar_fd('\n', 1);
		char_bite = 0;
		c = 0;
		++*str;
	}
	//ft_putstr_fd("char_bite ", 1);
	//ft_putnbr_fd(char_bite, 1);
	//ft_putchar_fd('\n', 1);
	//sleep(1);
	//printf("----------------------\n");
}

int	main(void)
{
	struct sigaction	sigac;

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
