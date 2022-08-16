/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 12:41:22 by luguilla          #+#    #+#             */
/*   Updated: 2022/03/10 13:27:31 by luguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_len(int fd)
{
	int		ret;
	char	buf[4096];
	int		i;
	int		lines;

	i = 0;
	lines = 0;
	ret = read(fd, buf, 4096);
	if (ret < 1)
		exit(0);
	if (buf[0] == '\0')
	{
		ft_printf("Error\nFichier vide.\n");
		exit(0);
	}
	(void)ret;
	while (buf[i])
	{
		if (buf[i] == '\n')
			lines++;
		i++;
	}
	return (lines);
}

char	**check_map(char *map, t_game *game)
{
	int		fd;
	int		nbr_lines;
	int		i;

	i = -1;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		exit (0);
	nbr_lines = check_len(fd);
	game->map.height = nbr_lines;
	if (close(fd) == -1)
		exit (0);
	fd = open(map, O_RDONLY);
	if (fd == -1)
		exit (0);
	game->map.tab = malloc(sizeof(char *) * nbr_lines);
	while (++i < nbr_lines)
		game->map.tab[i] = get_next_line(fd);
	get_next_line(fd);
	check_size(game, nbr_lines);
	check_wall(game, nbr_lines);
	check_char(game, nbr_lines);
	if (close(fd) == -1)
		exit (0);
	return (game->map.tab);
}

void	check_size(t_game *game, int nbr_lines)
{
	int	i;
	int	size;
	int	tmp;

	i = 1;
	size = ft_len(game->map.tab[0]);
	while (i < nbr_lines)
	{
		tmp = ft_len(game->map.tab[i]);
		if (tmp != size)
		{
			ft_printf("Error !\nTaille des murs.\n");
			free_all(game);
			exit(0);
		}
		i++;
	}
}

void	check_wall(t_game *game, int nbr_lines)
{
	int	i;

	f_and_l_line(game, game->map.tab[0], game->map.tab[nbr_lines - 1]);
	i = 0;
	while (++i < nbr_lines - 1)
	{
		if ((game->map.tab[i][0] != '1') ||
			(game->map.tab[i][ft_len(game->map.tab[i]) - 2] != '1'))
		{
			ft_printf("Error !\nLa map n'est pas entourée de murs.\n");
			free_all(game);
			exit(0);
		}
	}
}

void	check_char(t_game *game, int nbr_lines)
{
	int	empty;
	int	p_exit;
	int	i;
	int	j;

	i = 0;
	empty = 0;
	p_exit = 0;
	while (i < nbr_lines)
	{
		j = 0;
		while (game->map.tab[i][j])
		{
			if (game->map.tab[i][j] == '0')
				empty++;
			if (game->map.tab[i][j] == 'E')
				p_exit++;
			j++;
		}
		i++;
	}
	check_char2(game, nbr_lines, empty, p_exit);
}
