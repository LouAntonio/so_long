/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lantonio <lantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:40:43 by lantonio          #+#    #+#             */
/*   Updated: 2024/08/09 13:23:19 by lantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

char	**ft_split(char const *s, char c);
char	**get_map(char **av);
int		line_validator(char *str);
int		column_validator(char **str);
int		character_and_collectible_validator(char **str);
void	flood_fill(char **map, int x, int y, int *found);
int		its_possible(char **map, char c);
int		map_validator(char **map);
int		ft_strlen(char *str);
int		matrix_len(char **matrix);

#endif