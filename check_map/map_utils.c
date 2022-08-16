/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:42:47 by luguilla          #+#    #+#             */
/*   Updated: 2022/03/10 13:27:30 by luguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	f_and_l_line(t_game *game, char *first, char *last)
{
	int	i;
	int	size;

	i = -1;
	size = ft_len(first);
	while (++i < size - 1)
	{
		if (first[i] != '1')
		{
			ft_printf("Error !\nLa map n'est pas entourée de murs.\n");
			free_all(game);
			exit(0);
		}
	}
	i = -1;
	while (++i < size - 1)
	{
		if (last[i] != '1')
		{
			ft_printf("Error !\nLa map n'est pas entourée de murs.\n");
			free_all(game);
			exit(0);
		}
	}
}

void	free_exit(t_game *game)
{
	free_all(game);
	exit(0);
}

void	check_char2(t_game *game, int nbr_lines, int empty, int p_exit)
{
	int	collectible;
	int	spawn;
	int	i;
	int	j;

	collectible = 0;
	spawn = 0;
	i = -1;
	while (++i < nbr_lines)
	{
		j = -1;
		while (game->map.tab[i][++j])
		{
			if (game->map.tab[i][j] == 'C')
				collectible++;
			if (game->map.tab[i][j] == 'P')
				spawn++;
			is_correct_char(game ,game->map.tab[i][j]);
		}
	}
	if (collectible == 0)
	{
		ft_printf("Error\nPas d'item.\n");
		free_exit(game);
	}
	check_char3(game, empty, p_exit, spawn);
}

void	check_char3(t_game *game, int empty, int p_exit, int spawn)
{
	if (empty == 0)
	{
		ft_printf("Error\nPas d'emplacement vide.\n");
		free_all(game);
		exit(0);
	}
	if (p_exit == 0)
	{
		ft_printf("Error\nPas de sortie.\n");
		free_all(game);
		exit(0);
	}
	if (spawn == 0)
	{
		ft_printf("Error\nPas de position de départ.\n");
		free_all(game);
		exit(0);
	}
	if (spawn > 1)
	{
		ft_printf("Error\nTrop de joueurs.\n");
		free_all(game);
		exit(0);
	}
}
