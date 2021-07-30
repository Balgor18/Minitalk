/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 09:39:46 by fcatinau          #+#    #+#             */
/*   Updated: 2021/07/30 09:41:29 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	verif_str_digit(char *s)
{
	while (ft_isdigit(*s) && *s)
	{
		s++;
	}
	if (!*s)
		return (TRUE);
	return (FALSE);
}