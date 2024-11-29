/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mnt.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojsong <hojsong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 15:12:12 by hojsong           #+#    #+#             */
/*   Updated: 2022/12/27 13:22:04 by hojsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MNT_H
# define MNT_H

# include <signal.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>

void	send_msg(int pid, unsigned char *msg);
void	send_bry(int pid, unsigned char c);
void	ft_error(int i);

void	ft_put_str(char *str, int fd);
void	ft_put_strl(char *str, int fd);
int		ft_atoi(char *str);
char	*ft_itoa(int id);
int		malsize(int i);

void	cng_bry(int sig);
void	pric(char *str);
char	ft_itob(char *str);

#endif
