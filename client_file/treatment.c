/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treatment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 12:44:55 by fcatinau          #+#    #+#             */
/*   Updated: 2021/08/04 17:25:10 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

#include <stdio.h>
/*void	char_treatment(int c)
{
	printf("Treatment |%c|\n", c);
}*/

void	str_treatment(char *s)
{
	printf("str %s\n", s);
	while(*s)
	{
		ft_putnbr_base(*s, "01");
		printf(" |%c|\n", *s);
		//char_treatment(*d.s);
		++s;
	}
}
