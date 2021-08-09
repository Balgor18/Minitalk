/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 12:04:22 by fcatinau          #+#    #+#             */
/*   Updated: 2021/08/09 12:04:40 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	error_no_arg(void)
{
	write(1, "usage : \033[0;31m./client \033[0;32m [PID]\
	\033[0;33m [STRING]\e[0m", 58);
	return (0);
}

int	error_arg(char *s)
{
	red();
	ft_putstr_fd(s, 1);
	white();
	return (EXIT_FAILURE);
}
