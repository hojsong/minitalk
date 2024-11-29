/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clinet.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojsong <hojsong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 16:35:34 by hojsong           #+#    #+#             */
/*   Updated: 2023/01/05 12:37:32 by hojsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/mnt.h"

int	main(int argc, char **argv)
{
	unsigned char	*msg;
	pid_t			pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid < 100 || pid > 99998)
			ft_error(1);
		msg = (unsigned char *)argv[2];
		send_msg(pid, msg);
	}
	else
		ft_error(2);
	return (0);
}

void	send_msg(int pid, unsigned char *msg)
{
	unsigned int	i;

	i = 0;
	while (msg[i])
	{
		send_bry(pid, msg[i]);
		i++;
	}
	send_bry(pid, 0);
}

void	send_bry(int pid, unsigned char c)
{
	unsigned int	i;
	unsigned char	base;

	base = 128;
	i = 0;
	while (i < 8)
	{
		if (c & base)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		base = base >> 1;
		i ++;
		usleep(100);
	}
}

void	ft_error(int i)
{
	ft_put_str("Error", 2);
	if (i == 1)
		write(2, "\n", 1);
	else if (i == 2)
		ft_put_strl(" : ./client [server PID] [message]!", 2);
	exit(EXIT_FAILURE);
}
