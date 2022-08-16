/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:55:14 by luguilla          #+#    #+#             */
/*   Updated: 2022/02/23 15:42:31 by luguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

long	unbrlen(unsigned int j)
{
	int				size;
	unsigned int	i;

	i = 0;
	if (j == i)
		return (1);
	size = 0;
	if (j < i)
	{
		size++;
		j = -j;
	}
	while (j != i)
	{
		j /= 10;
		size++;
	}
	return (size++);
}

char	*ft_uitoa(unsigned int n)
{
	int				i;
	unsigned int	j;
	char			*str;
	unsigned int	k;

	k = 0;
	j = n;
	i = unbrlen(j);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	i--;
	if (j < k)
		j = -j;
	while (i >= 0)
	{
		str[i] = j % 10 + '0';
		i--;
		j /= 10;
	}
	if (n < k)
		str[0] = '-';
	return (str);
}

int	ft_putuint(unsigned int nbr)
{
	char	*str;

	str = ft_uitoa(nbr);
	write (1, str, ft_strlen(str));
	return (ft_strlen(str));
}
