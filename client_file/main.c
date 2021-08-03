/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 14:58:58 by fcatinau          #+#    #+#             */
/*   Updated: 2021/08/03 12:57:02 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	test(void)
{
	sigset_t test;

	//segemptyset(&test);
	sigfillset(&test);
	sigaddset(&test, SIGUSR1);
	sigdelset(&test, SIGUSR1);
}

int	main(int agc, char **agv)
{
	t_data	data;

	ft_putstr_fd("Start client \n", 1);
	if (agc < 2)
		return (error_arg("Error not enough arguments \n"));
	if (!verif_str_digit(agv[1]))
		return (error_arg("Error bad arguments need int\nex: 1384\n"));
	if (!agv[2])
		return (error_arg("Error bad arguments need string\n"));
	green();
	ft_putstr_fd("Client work \n", 1);
	reset();
	init_data(&data ,agv);
	str_treatment(data);
	//sigaction(ft_atoi(agv[1]), test);
	return (0);
}
