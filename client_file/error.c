/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 16:20:32 by fcatinau          #+#    #+#             */
/*   Updated: 2021/07/29 19:11:50 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	error_arg(void)
{
	red();
	ft_putstr_fd("Error not enough arguments \n", 1);
	white();
	return (0);
}
