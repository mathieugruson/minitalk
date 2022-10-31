/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:34:24 by mgruson           #+#    #+#             */
/*   Updated: 2022/10/31 12:02:09 by mgruson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft/libft/libft.h"
# include "libft/get_next_line/get_next_line.h"
# include "libft/ft_printf/ft_printf.h"
# include <signal.h>

/* error definition */

# define NO_ERROR 1
# define ERROR 0

/* server.c */

char		*send_char(int r, char *str);
char		*display_message(int r, char *str, siginfo_t *client);
void		handle_client_signal(int signal, siginfo_t *client, void *unused);

/* client.c */

void		send_message(int pid, char c);
void		handle_server_signal(int signal);

#endif 