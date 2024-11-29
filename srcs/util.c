/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_all.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojsong <hojsong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:45:30 by hojsong           #+#    #+#             */
/*   Updated: 2022/12/30 16:12:57 by hojsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/mnt.h"

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

char	*ft_itoa(int id)
{
	char	*result;
	int		ids;
	int		idx;

	idx = 0;
	ids = malsize(id);
	result = malloc(sizeof(char) * (ids + 1));
	if (result == NULL)
		return (0);
	result[ids] = '\0';
	if (id == 0)
		result[0] = '\0';
	while (id != 0)
	{
		result[ids - 1] = (id % 10) + '0';
		ids--;
		id /= 10;
	}
	return (result);
}

int	malsize(int i)
{
	int	num;
	int	size;

	num = i;
	size = 0;
	if (num <= 0)
		size++;
	while (num)
	{
		num /= 10;
		size++;
	}
	return (size);
}
