/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:39:38 by luguilla          #+#    #+#             */
/*   Updated: 2022/02/25 14:12:19 by luguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	finish(t_game *game)
{
	game->move++;
	ft_printf("Vous avez fini en %d déplacement(s).\n", game->move);
	ft_close(game);
}

void	move_up(t_game *game)
{
	int	x;
	int	y;

	x = game->player.x;
	y = game->player.y;
	if (game->map.tab[y - 1][x] == '0' || game->map.tab[y - 1][x] == 'C')
	{
		if (game->map.tab[y - 1][x] == 'C')
			game->collectible--;
		game->map.tab[y - 1][x] = 'P';
		game->map.tab[y][x] = '0';
		put_ground(game, x, y);
		game->player.y -= 1;
		put_player(game, x, game->player.y, 2);
		game->move++;
		ft_printf("%d déplacement(s)\n", game->move);
	}
	if (game->map.tab[y - 1][x] == 'E' && game->collectible == 0)
		finish(game);
}

void	move_down(t_game *game)
{
	int	x;
	int	y;

	x = game->player.x;
	y = game->player.y;
	if (game->map.tab[y + 1][x] == '0' || game->map.tab[y + 1][x] == 'C')
	{
		if (game->map.tab[y + 1][x] == 'C')
			game->collectible--;
		game->map.tab[y + 1][x] = 'P';
		game->map.tab[y][x] = '0';
		put_ground(game, x, y);
		game->player.y += 1;
		put_player(game, x, game->player.y, 1);
		game->move++;
		ft_printf("%d déplacement(s)\n", game->move);
	}
	if (game->map.tab[y + 1][x] == 'E' && game->collectible == 0)
		finish(game);
}

void	move_right(t_game *game)
{
	int	x;
	int	y;

	x = game->player.x;
	y = game->player.y;
	if (game->map.tab[y][x + 1] == '0' || game->map.tab[y][x + 1] == 'C')
	{
		if (game->map.tab[y][x + 1] == 'C')
			game->collectible--;
		game->map.tab[y][x + 1] = 'P';
		game->map.tab[y][x] = '0';
		put_ground(game, x, y);
		game->player.x += 1;
		put_player(game, game->player.x, y, 4);
		game->move++;
		ft_printf("%d déplacement(s)\n", game->move);
	}
	if (game->map.tab[y][x + 1] == 'E' && game->collectible == 0)
		finish(game);
}

void	move_left(t_game *game)
{
	int	x;
	int	y;

	x = game->player.x;
	y = game->player.y;
	if (game->map.tab[y][x - 1] == '0' || game->map.tab[y][x - 1] == 'C')
	{
		if (game->map.tab[y][x - 1] == 'C')
			game->collectible--;
		game->map.tab[y][x - 1] = 'P';
		game->map.tab[y][x] = '0';
		put_ground(game, x, y);
		game->player.x -= 1;
		put_player(game, game->player.x, y, 3);
		game->move++;
		ft_printf("%d déplacement(s)\n", game->move);
	}
	if (game->map.tab[y][x - 1] == 'E' && game->collectible == 0)
		finish(game);
}
