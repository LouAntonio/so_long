/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lantonio <lantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:40:43 by lantonio          #+#    #+#             */
/*   Updated: 2024/08/16 11:52:28 by lantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_game
{
	int		x;
	int		y;
	int		win_w;
	int		win_h;
	void	*mlx;
	void	*mlx_w;
	void	*img;
	void	*player;
	void	*batman;
	void	*b_b;
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

// MAP VALIDATION
char	**get_map(char *av);
int		map_validator(char *av);
int		line_validator(char *str);
int		column_validator(char **str);
int		valid_chars_only(char **map);
int		valid_dimentions(char **map);
int		valid_extension(char *map_path);
int		exit_validator(char **map);
int		char_validator(char **map, char c);
int		player_validator(char **map);
int		collectable_validator(char **map);
t_point	get_char_position(char **map, char c);
void	flood_fill(char **tab, t_point size, t_point begin);

// GAME INITIALIZATION
void	game_init(char **map);
void	map_render(t_game vars);

// EVENTS HANDLER & PLAYER MOVES
int		key_press_handler(int keycode, t_game *vars);
t_point	get_player_position(char **map, char c);
void	move_to_up(t_game *vars, t_point player_position);
void	move_to_right(t_game *vars, t_point player_position);
void	move_to_down(t_game *vars, t_point player_position);
void	move_to_left(t_game *vars, t_point player_position);

// GAME EXIT
void	exit_on_read(int fd);
void	finish_game(t_game *vars);
int		close_game(t_game *vars);
void	exit_while_reading(int fd);

#endif