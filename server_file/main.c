/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 09:42:59 by fcatinau          #+#    #+#             */
/*   Updated: 2021/08/07 18:32:37 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

//#define ONE		SIGUSR1
//#define ZERO	SIGUSR2
#define BUFFER	1024

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
	static size_t	char_byte = 0;

	c = c << 1;
	if (num == SIGUSR1)
		c = c + 1;
	else if (num == SIGUSR2)
		c = c + 0;
	if (++char_byte == 8)
	{
		char_byte = 0;
		ft_putchar_fd(c, 1);
		//ft_putchar_fd('\n', 1);
		c = 0;
	}
}

/*
**struct sigaction
** {
**	void		(*sa_handler) (int);
**	void		(*sa_sigaction) (int, siginfo_t *, void *);
**	sigset_t	sa_mask;
**	int			sa_flags;
**	void		(*sa_restorer) (void);
** };
*/
int	main(void)
{
	struct sigaction	sigac;

	sigac.sa_handler = receive;
	sigac.sa_flags = 0;
	sigac.sa_mask = 128;
	//sigemptyset(&sigac.sa_mask);
	sigemptyset(&sigac.sa_flags);
	//signal(SIGUSR1, receive);
	//signal(SIGUSR2, receive);
	sigaddset(&sigac.sa_flags, SIGUSR1);
	sigaddset(&sigac.sa_flags, SIGUSR2);
	if (sigaction(SIGUSR1, &sigac, NULL) == -1)
		return (error_arg("Error positioning signal"));
	if (sigaction(SIGUSR2, &sigac, NULL) == -1)
		return (error_arg("Error positioning signal"));
	print_pid();
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
