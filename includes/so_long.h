/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lantonio <lantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:40:43 by lantonio          #+#    #+#             */
/*   Updated: 2024/08/23 12:05:37 by lantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_game
{
	int		x;
	int		y;
	int		qtt_moves;
	int		win_w;
	int		win_h;
	void	*mlx;
	void	*mlx_w;
	void	*img;
	void	*player;
	void	*batman;
	void	*bat_left;
	void	*batarang;
	void	*mobile;
	void	*grass;
	void	*rocks;
	char	**map;
}	t_game;

// UTILS
char	**ft_split(char const *s, char c);
void	free_matrix(char **matrix);
int		matrix_len(char **matrix);
int		ft_strlen(char *str);
void	ft_putstr(char *str);
int		ft_strcmp(char *s1, char *s2);
int		map_lenth(char *av);
void	ft_putnbr(int n);
void	show_player_moves(t_game *game);
t_point	get_player_position(char **map, char c);
t_point	get_char_position(char **map, char c);

// MAP READING
char	**get_map(char *av);
int		valid_extension(char *map_path);
int		non_breaks(char *str);

// MAP VALIDATION
int		map_validator(char *av);
int		line_validator(char *str);
int		column_validator(char **str);
int		valid_dimentions(char **map);
int		valid_chars_only(char **map);
int		player_validator(char **map);
int		collectable_validator(char **map);
int		exit_validator(char **map);
int		char_validator(char **map, char c);
void	flood_fill(char **tab, t_point size, t_point begin);

// GAME INITIALIZATION
void	game_init(char **map);
void	map_render(t_game game);

// EVENTS HANDLER & PLAYER MOVES
int		key_press_handler(int keycode, t_game *game);
void	move_to_up(t_game *game, t_point player_position);
void	move_to_right(t_game *game, t_point player_position);
void	move_to_down(t_game *game, t_point player_position);
void	move_to_left(t_game *game, t_point player_position);

// GAME EXIT
int		close_game(t_game *game);
void	finish_game(t_game *game);
void	exit_while_reading(int fd);
void	exit_cause_break(char *str);
void	exit_on_read(int fd, char *str);

#endif