/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_all.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojsong <hojsong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:45:30 by hojsong           #+#    #+#             */
/*   Updated: 2023/01/05 12:47:07 by hojsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/mnt_bonus.h"

void	ft_put_str(char	*str, int fd)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}

void	ft_put_strl(char *str, int fd)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}

void	ft_put_nbr(unsigned int i)
{
	char	c;

	c = i % 10 + '0';
	if (i > 9)
		ft_put_nbr(i / 10);
	write(1, &c, 1);
}

int	ft_atoi(char *str)
{
	int	i;
	int	pm;
	int	result;

	result = 0;
	pm = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			pm = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + ((str[i] - '0') * pm);
		i++;
	}
	return (result);
}

void	ft_error(int i)
{
	ft_put_str("Error", 2);
	if (i == 1)
		write(2, "\n", 1);
	else if (i == 2)
		ft_put_strl(" : ./client [server PID] [message]!", 2);
	else if (i == 3)
		ft_put_strl(" Check of PID", 2);
	exit(EXIT_FAILURE);
}
