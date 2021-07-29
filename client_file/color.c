/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 19:03:29 by fcatinau          #+#    #+#             */
/*   Updated: 2021/07/29 16:21:14 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	blue(void)
{
	ft_putstr_fd("\033[0;34m", 1);
}

void	cyan(void)
{
	ft_putstr_fd("\033[0;36m", 1);
}

void	red(void)
{
	ft_putstr_fd("\033[0;31m", 1);
}

void	white(void)
{
	ft_putstr_fd("\033[0;37m", 1);
}

void	green(void)
{
	ft_putstr_fd("\033[0;32m", 1);
}
