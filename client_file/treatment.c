/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treatment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 12:44:55 by fcatinau          #+#    #+#             */
/*   Updated: 2021/08/03 13:29:17 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

#include <stdio.h>
/*void	char_treatment(int c)
{
	printf("Treatment |%c|\n", c);
}*/

void	str_treatment(t_data d)
{
	printf("str %s\n", d.s);
	while(*d.s)
	{

		ft_putnbr_base(*d.s, "01");
		printf(" |%c|\n", *d.s);
		//char_treatment(*d.s);
		d.s++;
	}
}
