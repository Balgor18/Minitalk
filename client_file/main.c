/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 14:58:58 by fcatinau          #+#    #+#             */
/*   Updated: 2021/07/29 19:29:24 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	main(int agc, char **agv)
{
	(void)agv;
	ft_putstr_fd("Start client \n", 1);
	if (agc < 2)
		return (error_arg());
	green();
	ft_putstr_fd("Client work \n", 1);
	return (0);
}
