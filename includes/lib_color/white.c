/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   white.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 10:01:20 by fcatinau          #+#    #+#             */
/*   Updated: 2021/07/30 10:19:24 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

void	white(void)
{
	ft_putstr_fd("\033[0;37m", 1);
}
