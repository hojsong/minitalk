/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mnt.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojsong <hojsong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 15:12:12 by hojsong           #+#    #+#             */
/*   Updated: 2023/01/05 13:08:13 by hojsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MNT_BONUS_H
# define MNT_BONUS_H

# include <signal.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdio.h>

void	ft_signal_handler(int sig, siginfo_t *info, void *context);
void	ft_signal_tl(int sig, int pid);
void	ft_put_char_mnt(char c, int pid);

void	ft_error(int i);
void	ft_send_terminator(int pid);

void	ft_put_str(char *str, int fd);
void	ft_put_strl(char *str, int fd);
void	ft_put_nbr(unsigned int i);

int		ft_atoi(char *str);
char	*ft_itoa(int id);
int		malsize(int i);

void	send_msg(int pid, unsigned char *msg);
void	send_bry(int pid, unsigned char c);
void	ft_receipt(int sig, siginfo_t *info, void *context);
void	fin_msg(int sig);

#endif
