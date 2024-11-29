/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clinet.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojsong <hojsong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 16:35:34 by hojsong           #+#    #+#             */
/*   Updated: 2023/01/05 12:42:45 by hojsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/mnt_bonus.h"

int	main(int argc, char **argv)
{
	unsigned char	*msg;
	int				s_id;

	signal(SIGUSR1, fin_msg);
	signal(SIGUSR2, fin_msg);
	if (argc != 3)
		ft_error(2);
	s_id = ft_atoi(argv[1]);
	msg = (unsigned char *)argv[2];
	send_msg(s_id, msg);
	while (1)
		pause();
	return (0);
}

void	send_msg(int pid, unsigned char *msg)
{
	int	i;

	i = 0;
	while (msg[i])
	{
		send_bry(pid, msg[i]);
		i++;
	}
	send_bry(pid, '\0');
}

void	send_bry(int pid, unsigned char c)
{
	unsigned char	base;
	unsigned int	i;

	base = 128;
	i = 0;
	while (i < 8)
	{
		if (c & base)
		{
			if (kill(pid, SIGUSR1) == -1)
				ft_error(3);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				ft_error(3);
		}
		base = base >> 1;
		i++;
		usleep(200);
	}
}

void	fin_msg(int sig)
{
	if (sig == SIGUSR1)
	{
		ft_put_strl("Message Sent", 1);
		exit(1);
	}
	usleep(150);
}
