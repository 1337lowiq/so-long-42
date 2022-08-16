/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 10:06:32 by luguilla          #+#    #+#             */
/*   Updated: 2022/03/10 11:15:43 by luguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_all(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.height)
	{
		free(game->map.tab[i]);
		i++;
	}
	free(game->map.tab);
	free(game->mlx);
}

void	ft_get_position(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (game->map.tab[i][j] != '\n')
		{
			if (game->map.tab[i][j] == 'P')
			{
				game->player.y = i;
				game->player.x = j;
			}
			j++;
		}
		i++;
	}
}

void	ft_get_collectible(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (game->map.tab[i][j] != '\n')
		{
			if (game->map.tab[i][j] == 'C')
			{
				game->collectible++;
			}
			j++;
		}
		i++;
	}
}

int	ft_close(t_game *game)
{
	mlx_destroy_image(game->mlx, game->sprites[P_FACE].ref);
	mlx_destroy_image(game->mlx, game->sprites[P_BACK].ref);
	mlx_destroy_image(game->mlx, game->sprites[P_RIGHT].ref);
	mlx_destroy_image(game->mlx, game->sprites[P_LEFT].ref);
	mlx_destroy_image(game->mlx, game->sprites[SOL2].ref);
	mlx_destroy_image(game->mlx, game->sprites[COLLEC].ref);
	mlx_destroy_image(game->mlx, game->sprites[EXIT].ref);
	mlx_destroy_image(game->mlx, game->sprites[WALL].ref);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	mlx_loop_end(game->mlx);
	free_all(game);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_printf("Error\nNombre de map.\n");
		exit (0);
	}
	if (check_ber(argv[1]) == 0)
	{
		ft_printf("Error\nFormat de map.\n");
		exit(0);
	}
	game.collectible = 0;
	game.map.tab = check_map(argv[1], &game);
	screen_resolution(&game, argv[1]);
	game.mlx = mlx_init();
	game.window = mlx_new_window(game.mlx, game.map.width * 64,
			game.map.height * 64, "So_long");
	ft_init(&game);
	draw_map(&game);
	ft_get_position(&game);
	ft_get_collectible(&game);
	mlx_hook(game.window, 2, 1L << 0, ft_hook, &game);
	mlx_hook(game.window, 17, 1L << 0, ft_close, &game);
	mlx_loop(game.mlx);
}
