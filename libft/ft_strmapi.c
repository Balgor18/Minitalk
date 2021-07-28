/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 15:35:29 by fcatinau          #+#    #+#             */
/*   Updated: 2021/01/09 22:54:22 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*sp;
	int		i;

	if (!s || !f)
		return (NULL);
	if (!(sp = (char *)malloc(sizeof(char) * (ft_strlen((char *)s) + 1))))
		return (NULL);
	i = 0;
	while (s[i])
	{
		sp[i] = f(i, s[i]);
		++i;
	}
	sp[i] = '\0';
	return (sp);
}
