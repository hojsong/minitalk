/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_all.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojsong <hojsong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:45:30 by hojsong           #+#    #+#             */
/*   Updated: 2022/12/30 16:15:31 by hojsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/mnt_bonus.h"

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
