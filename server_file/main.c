/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 09:42:59 by fcatinau          #+#    #+#             */
/*   Updated: 2021/07/28 10:41:46 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	print_pid()
{
	int	pid;

	pid = getpid();
	ft_putstr_fd("PID : ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
}

int	main(int agc, char **agv)
{
	(void)agc;
	(void)agv;
	print_pid();
	return (0);
}
