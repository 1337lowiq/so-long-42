/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 11:06:02 by luguilla          #+#    #+#             */
/*   Updated: 2022/03/10 13:26:57 by luguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include "minilibx/mlx.h"

enum {
	WALL = 0,
	P_FACE = 1,
	P_BACK = 2,
	P_LEFT = 3,
	P_RIGHT = 4,
	SOL = 5,
	SOL2 = 6,
	EXIT = 7,
	COLLEC = 8
};

typedef struct s_map
{
	char	**tab;
	int		height;
	int		width;
}	t_map;

typedef struct s_image
{
	void	*ref;
	int		x;
	int		y;
}	t_image;

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	int			collectible;
	int			move;
	t_map		map;
	t_image		sprites[5];
	t_player	player;
}	t_game;

int	is_correct_char(t_game *game, char c);
int		ft_strstr(char *str, char *to_find);
void	free_exit(t_game *game);
int		ft_strlen(const char *str);
int		ft_strchr(char *s, int c);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
char	**check_map(char *map, t_game *game);
int		count_line(int fd);
int		check_len(int fd);
int		ft_len(char *str);
char	*ft_strcpy(char *src);
void	check_size(t_game *game, int nbr_lines);
void	check_wall(t_game *game, int nbr_lines);
void	f_and_l_line(t_game *game, char *first, char *last);
void	check_char(t_game *game, int nbr_lines);
void	check_char2(t_game *game, int nbr_lines, int empty, int exit);
void	check_char3(t_game *game, int empty, int exit, int spawn);
int		screen_resolution(t_game *game, char *map);
void	ft_init(t_game *game);
void	sprite_to_window(int x, int y, t_game *game);
void	draw_map(t_game *game);
int		ft_hook(int keycode, t_game *game);
void	move_up(t_game *game);
void	ft_get_collectible(t_game *game);
void	put_ground(t_game *game, int x, int y);
void	put_player(t_game *game, int x, int y, int i);
void	move_down(t_game *game);
void	move_right(t_game *game);
void	ft_init2(t_game *game);
void	move_left(t_game *game);
void	free_all(t_game *game);
void	sprite_to_window2(int x, int y, t_game *game);
int		ft_printf(const char *input, ...);
int		isflag(char c);
int		ft_putstr(char *str);
int		ft_putchar(int c);
void	ft_putnbr(int nb);
int		ft_get_flags(char flag, va_list args);
int		nbrlen(int j);
char	*ft_itoa(unsigned long long n);
char	*ft_strrev(char *str);
int		ft_putuint(unsigned int nbr);
void	ft_hexa(uintptr_t num);
int		ft_putptr(unsigned long long ptr);
int		ft_ptr_len(uintptr_t num);
void	ft_puthex(unsigned int num, const char format);
int		ft_print_hex(unsigned int num, const char format);
int		ft_hex_len(unsigned int num);
int		ft_close(t_game *game);
int		check_ber(char *map);

#endif
