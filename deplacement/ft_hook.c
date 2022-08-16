/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:37:55 by luguilla          #+#    #+#             */
/*   Updated: 2022/03/01 14:59:26 by luguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_ground(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->window,
		game->sprites[SOL2].ref, x * 64, y * 64);
}

void	put_player(t_game *game, int x, int y, int i)
{
	mlx_put_image_to_window(game->mlx, game->window,
		game->sprites[i].ref, x * 64, y * 64);
}

int	ft_hook(int keycode, t_game *game)
{
	if (keycode == 65362 || keycode == 119)
		move_up(game);
	else if (keycode == 65364 || keycode == 115)
		move_down(game);
	else if (keycode == 65363 || keycode == 100)
		move_right(game);
	else if (keycode == 65361 || keycode == 97)
		move_left(game);
	else if (keycode == 65307)
		ft_close(game);
	return (0);
}
