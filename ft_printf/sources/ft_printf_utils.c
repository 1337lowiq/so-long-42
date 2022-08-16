/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 12:34:58 by luguilla          #+#    #+#             */
/*   Updated: 2022/02/23 15:42:09 by luguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	nb = (nb % 10) + 48;
	write(1, &nb, 1);
}

int	nbrlen(int j)
{
	int					size;

	if (j == 0)
		return (1);
	size = 0;
	if (j < 0)
	{
		j = -j;
		size += 1;
	}
	while (j != 0)
	{
		j /= 10;
		size++;
	}
	return (size++);
}

char	*ft_itoa(unsigned long long n)
{
	int					i;
	unsigned long long	j;
	unsigned long long	k;
	char				*str;

	k = 0;
	j = n;
	i = nbrlen(j);
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
