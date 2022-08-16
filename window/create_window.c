/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:04:09 by luguilla          #+#    #+#             */
/*   Updated: 2022/03/01 14:59:19 by luguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	screen_resolution(t_game *game, char *map)
{
	int	fd;

	game->map.width = 0;
	game->map.height = 0;
	while (game->map.tab[0][game->map.width])
		game->map.width++;
	game->map.width--;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (-1);
	game->map.height = check_len(fd);
	if (close(fd) == -1)
		return (-1);
	return (0);
}

void	ft_init(t_game *game)
{
	game->sprites[WALL].ref = mlx_xpm_file_to_image(game->mlx,
			"xpm/wall.xpm",
			&game->sprites[WALL].x, &game->sprites[WALL].y);
	game->sprites[P_FACE].ref = mlx_xpm_file_to_image(game->mlx,
			"xpm/p_face.xpm",
			&game->sprites[P_FACE].x, &game->sprites[P_FACE].y);
	game->sprites[P_BACK].ref = mlx_xpm_file_to_image(game->mlx,
			"xpm/p_back.xpm",
			&game->sprites[P_BACK].x, &game->sprites[P_BACK].y);
	game->sprites[P_LEFT].ref = mlx_xpm_file_to_image(game->mlx,
			"xpm/p_left.xpm",
			&game->sprites[P_LEFT].x, &game->sprites[P_LEFT].y);
	game->sprites[P_RIGHT].ref = mlx_xpm_file_to_image(game->mlx,
			"xpm/p_right.xpm",
			&game->sprites[P_RIGHT].x, &game->sprites[P_RIGHT].y);
	ft_init2(game);
}

void	ft_init2(t_game *game)
{
	game->sprites[SOL2].ref = mlx_xpm_file_to_image(game->mlx,
			"xpm/ground2.xpm",
			&game->sprites[SOL2].x, &game->sprites[SOL2].y);
	game->sprites[EXIT].ref = mlx_xpm_file_to_image(game->mlx,
			"xpm/end.xpm",
			&game->sprites[EXIT].x, &game->sprites[EXIT].y);
	game->sprites[COLLEC].ref = mlx_xpm_file_to_image(game->mlx,
			"xpm/collectible.xpm",
			&game->sprites[COLLEC].x, &game->sprites[COLLEC].y);
}

void	sprite_to_window(int x, int y, t_game *game)
{
	if (game->map.tab[y][x] == '1')
	{
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprites[WALL].ref,
			x * game->sprites[WALL].x, y * game->sprites[WALL].y);
	}
	if (game->map.tab[y][x] == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprites[P_FACE].ref,
			x * game->sprites[P_FACE].x, y * game->sprites[P_FACE].y);
	}
	if (game->map.tab[y][x] == '0')
	{
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprites[SOL2].ref,
			x * game->sprites[SOL2].x, y * game->sprites[SOL2].y);
	}
}

void	draw_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < game->map.height)
	{
		while (x < game->map.width)
		{
			sprite_to_window(x, y, game);
			sprite_to_window2(x, y, game);
			x++;
		}
		y++;
		x = 0;
	}
}
