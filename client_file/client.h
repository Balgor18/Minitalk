/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 12:04:52 by fcatinau          #+#    #+#             */
/*   Updated: 2021/08/09 17:23:07 by fcatinau         ###   ########.fr       */
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
** Error
*/
int		error_no_arg(void);
int		error_arg(char *s);

/*
** Send
*/
int		send_char(pid_t pid, char c);
int		send_string(pid_t pid, char *s);

#endif
