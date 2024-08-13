/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lantonio <lantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:40:43 by lantonio          #+#    #+#             */
/*   Updated: 2024/08/13 18:47:32 by lantonio         ###   ########.fr       */
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

typedef struct	s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct	s_game
{
	int		window_width;
	int		window_height;
	void	*mlx;
	void	*mlx_w;
	void	*img;
	void	*player;
	void	*batman;
	void	*batman_left;
	void	*batarang;
	void	*batmobile;
	void	*grass;
	void	*rocks;
	char	**map;
}	t_game;

char	**ft_split(char const *s, char c);
char	**get_map(char *av);
int		line_validator(char *str);
int		column_validator(char **str);
int		character_and_collectible_validator(char **str);
int		its_possible(char **map, char c);
int		map_validator(char *av);
int		ft_strlen(char *str);
int		matrix_len(char **matrix);
void	ft_putstr(char *str);
void	game_init(char **map);
int		key_press_handler(int keycode, t_game *vars);
void	map_render(t_game vars);
t_point	get_char_position(char **map, char c);
void	move_to_up(t_game *vars);
void	move_to_down(t_game *vars);
void	move_to_left(t_game *vars);
void	move_to_right(t_game *vars);
int	char_validator(char **map, char c);

#endif