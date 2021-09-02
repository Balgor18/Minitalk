/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 09:42:59 by fcatinau          #+#    #+#             */
/*   Updated: 2021/09/02 09:56:20 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#define BUFFER	1024
#include <unistd.h>
#include <signal.h>
#include "../includes/lib_color/color.h"
#include "../includes/libft/libft.h"
#define TRUE 1
#define FALSE 0

int	error_arg(char *s)
{
	red();
	ft_putstr_fd(s, 2);
	white();
	return (EXIT_FAILURE);
}

void	print_pid(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putstr_fd("PID : ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
}

void	receive(int num, siginfo_t *info, void *s)
{
	static char		c = 0;
	static size_t	char_byte = 0;

	(void)s;
	c = c << 1;
	if (num == SIGUSR1)
		c = c + 1;
	else if (num == SIGUSR2)
		c = c + 0;
	if (++char_byte == 8)
	{
		if (c == 0)
			kill(info->si_pid, SIGUSR1);
		else
			ft_putchar_fd(c, 1);
		char_byte = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sigac;

	sigac.sa_sigaction = receive;
	sigac.sa_flags = 0;
	sigac.sa_mask = 128;
	sigemptyset(&sigac.sa_flags);
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
