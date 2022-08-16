/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_to_win.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 10:52:08 by luguilla          #+#    #+#             */
/*   Updated: 2022/03/01 15:00:08 by luguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	sprite_to_window2(int x, int y, t_game *game)
{
	if (game->map.tab[y][x] == 'E')
	{
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprites[EXIT].ref,
			x * game->sprites[EXIT].x, y * game->sprites[EXIT].y);
	}
	if (game->map.tab[y][x] == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprites[COLLEC].ref,
			x * game->sprites[COLLEC].x, y * game->sprites[COLLEC].y);
	}
}
