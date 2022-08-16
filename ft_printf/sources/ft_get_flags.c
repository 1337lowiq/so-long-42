/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 11:44:03 by luguilla          #+#    #+#             */
/*   Updated: 2022/02/23 15:43:08 by luguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

/*int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}*/

int	size_num(int nbr)
{
	int	size;

	size = nbrlen(nbr);
	ft_putnbr(nbr);
	return (size);
}

int	ft_get_flags(char flag, va_list args)
{
	int	print;

	print = 0;
	if (flag == 'c')
		print += ft_putchar(va_arg(args, int));
	if (flag == 's')
		print += ft_putstr(va_arg(args, char *));
	if (flag == 'p')
		print += ft_putptr(va_arg(args, unsigned long long));
	if (flag == 'd' || flag == 'i')
		print += size_num(va_arg(args, int));
	if (flag == 'u')
		print += ft_putuint(va_arg(args, unsigned int));
	if (flag == 'x' || flag == 'X')
		print += ft_print_hex(va_arg(args, unsigned int), flag);
	if (flag == '%')
	{
		print += 1;
		write (1, "%", 1);
	}
	return (print);
}
