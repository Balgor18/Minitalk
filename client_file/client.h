/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 19:30:19 by fcatinau          #+#    #+#             */
/*   Updated: 2021/07/29 19:31:10 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <unistd.h>
# include "../libft/libft.h"

# define TRUE 1
# define FALSE 0

/*
** Color
*/
void	blue(void);
void	cyan(void);
void	red(void);
void	white(void);
void	green(void);

/*
** Error
*/
int		error_arg(void);

#endif
