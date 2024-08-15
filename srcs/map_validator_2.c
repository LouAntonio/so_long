/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lantonio <lantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:43:44 by lantonio          #+#    #+#             */
/*   Updated: 2024/08/15 13:54:32 by lantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	valid_dimentions(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		if (ft_strlen(map[0]) != ft_strlen(map[i]))
		{
			ft_putstr("Error\nThe map collumns lenth don't match!\n");
			return (0);
		}
		i++;
	}
	if (matrix_len(map) == ft_strlen(map[0]))
	{
		ft_putstr("Error\nThe map is a square!\n");
		return (0);
	}
	return (1);
}

int	char_validator(char **map, char c)
{
	int	i;
	int	j;
	int	qtt;

	i = 0;
	qtt = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				qtt++;
			j++;
		}
		i++;
	}
	if (qtt)
		return (qtt);
	return (0);
}

t_point	get_char_position(char **map, char c)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				return ((t_point){j, i});
			j++;
		}
		i++;
	}
	return ((t_point){i, j});
}

t_point	get_player_position(char **map, char c)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				return ((t_point){i, j});
			j++;
		}
		i++;
	}
	return ((t_point){i, j});
}

int	valid_chars_only(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1'
				&& map[i][j] != 'C' && map[i][j] != 'E' && map[i][j] != 'P')
			{
				ft_putstr("Error\nThere is an invalid char in the map!\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
