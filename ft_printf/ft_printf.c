/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 10:48:42 by luguilla          #+#    #+#             */
/*   Updated: 2022/02/23 15:40:15 by luguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_printf(const char *input, ...)
{
	int		i;
	va_list	args;
	int		strlen;

	strlen = 0;
	i = 0;
	va_start(args, input);
	while (input[i])
	{
		if (input[i] == '%' && isflag(input[i + 1]))
		{
			strlen += ft_get_flags(input[i + 1], args);
			i += 2;
			continue ;
		}
		strlen += ft_putchar(input[i]);
		i++;
	}
	va_end(args);
	return (strlen);
}

int	isflag(char c)
{
	if (c == 'd' || c == 's' || c == 'c' || c == 'u' || c == 'p'
		|| c == 'x' || c == 'X' || c == '%' || c == 'i')
		return (1);
	return (0);
}
