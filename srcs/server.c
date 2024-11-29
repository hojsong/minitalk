/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojsong <hojsong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 17:07:45 by hojsong           #+#    #+#             */
/*   Updated: 2022/12/30 16:11:25 by hojsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/mnt.h"

int	main(void)
{
	char	*pid;

	pid = ft_itoa(getpid());
	ft_put_str("Server PID : ", 1);
	ft_put_strl(pid, 1);
	signal(SIGUSR1, cng_bry);
	signal(SIGUSR2, cng_bry);
	while (1)
		pause();
	free(pid);
	pid = 0;
	return (0);
}

void	cng_bry(int sig)
{
	static char	str[8];
	static int	idx;

	if (sig == SIGUSR1)
		str[idx] = '1';
	else if (sig == SIGUSR2)
		str[idx] = '0';
	idx++;
	if (idx == 8)
	{
		pric(str);
		idx = 0;
	}
}

void	pric(char *str)
{
	char	c;

	c = ft_itob(str);
	if (c == 0)
		write(1, "\n", 1);
	write(1, &c, 1);
}

char	ft_itob(char *str)
{
	int		i;
	char	c;

	i = 0;
	c = 0;
	while (str[i])
	{
		if (str[i] == '1')
			c = c * 2 + 1;
		else if (str[i] == '0')
			c = c * 2;
		i++;
	}
	return (c);
}
