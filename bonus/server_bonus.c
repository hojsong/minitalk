/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojsong <hojsong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 17:07:45 by hojsong           #+#    #+#             */
/*   Updated: 2023/01/06 16:21:56 by hojsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/mnt_bonus.h"

int	main(void)
{
	pid_t				pid;
	char				*str;
	struct sigaction	action;

	pid = getpid();
	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = ft_signal_handler;
	ft_put_str("Server PID : ", 1);
	str = ft_itoa(pid);
	ft_put_strl(str, 1);
	free(str);
	while (1)
	{
		sigaction(SIGUSR1, &action, NULL);
		sigaction(SIGUSR2, &action, NULL);
		pause();
	}
	return (0);
}

void	ft_signal_handler(int sig, siginfo_t *info, void *context)
{
	static unsigned int	pid;

	if (pid != (unsigned int)info->si_pid)
	{
		pid = info->si_pid;
		ft_put_nbr(pid);
		ft_put_str(" : ", 1);
	}
	(void)context;
	ft_signal_tl(sig, pid);
}

void	ft_signal_tl(int sig, int pid)
{
	static char	str;
	static int	idx;

	if (sig == SIGUSR1)
		str = str * 2 + 1;
	if (sig == SIGUSR2)
		str = str * 2;
	idx++;
	if (idx == 8)
	{
		ft_put_char_mnt(str, pid);
		idx = 0;
	}
}

void	ft_put_char_mnt(char c, int pid)
{
	if (c == '\0')
	{
		write(1, "\n", 1);
		kill(pid, SIGUSR1);
		usleep(100);
	}
	else
	{
		write(1, &c, 1);
		kill(pid, SIGUSR2);
		usleep(100);
	}
}
