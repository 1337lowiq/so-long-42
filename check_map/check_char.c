/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:10:45 by luguilla          #+#    #+#             */
/*   Updated: 2022/03/10 13:26:46 by luguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is_correct_char(t_game *game, char c)
{
	if (c == '1' || c == '0' || c == 'P' || c == 'C' || c == 'E'
			|| c == '\n')
		return (1);
	else
	{
		ft_printf("Error\ncaractere incorrect.\n");
		free_all(game);
		exit (0);
	}
}
