/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 14:58:58 by fcatinau          #+#    #+#             */
/*   Updated: 2021/07/30 09:53:49 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	main(int agc, char **agv)
{
	(void)agv;
	ft_putstr_fd("Start client \n", 1);
	if (agc < 2)
		return (error_arg("Error not enough arguments \n"));
	if (!verif_str_digit(agv[1]))
		return (error_arg("Error bad arguments need int\nex: 1384\n"));
	green();
	ft_putstr_fd("Client work \n", 1);
	return (0);
}
