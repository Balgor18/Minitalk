/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 19:30:19 by fcatinau          #+#    #+#             */
/*   Updated: 2021/08/07 18:53:10 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <unistd.h>
# include <signal.h>
# include "../includes/lib_color/color.h"
# include "../includes/libft/libft.h"

# define TRUE 1
# define FALSE 0

/*
** Includes
*/
void	ft_putnbr_base(int nbr, char *base);

/*
** Error
*/
int		error_arg(char *s);
int		error_no_arg(void);
/*
** Verif
*/
int		verif_str_digit(char *s);

#endif
