/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 19:30:19 by fcatinau          #+#    #+#             */
/*   Updated: 2021/07/30 10:25:43 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <unistd.h>
# include "../includes/lib_color/color.h"
# include "../includes/libft/libft.h"

# define TRUE 1
# define FALSE 0

/*
** Error
*/
int		error_arg(char *s);

/*
** Verif
*/
int		verif_str_digit(char *s);

#endif