/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_vars_validation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lantonio <lantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:50:59 by lantonio          #+#    #+#             */
/*   Updated: 2024/08/22 08:42:08 by lantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	player_validator(char **map)
{
	int	i;
	int	j;
	int	qtt;

	i = -1;
	qtt = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			if (map[i][j] == 'P')
				qtt++;
	}
	if (qtt == 0)
		ft_putstr("Error\nThere is not a player in the map!\n");
	if (qtt > 1)
		ft_putstr("Error\nThere is more then one player in the map!\n");
	if (qtt == 1)
		return (1);
	return (0);
}

int	collectable_validator(char **map)
{
	int	i;
	int	j;
	int	qtt;

	i = -1;
	qtt = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			if (map[i][j] == 'C')
				qtt++;
	}
	if (qtt == 0)
		ft_putstr("Error\nThere is not a collectable in the map!\n");
	if (qtt > 0)
		return (1);
	return (0);
}

int	exit_validator(char **map)
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
			if (map[i][j] == 'E')
				qtt++;
			j++;
		}
		i++;
	}
	if (qtt == 0)
		ft_putstr("Error\nThere is not an exit in the map!\n");
	else if (qtt > 1)
		ft_putstr("Error\nThere is more then one exit in the map!\n");
	if (qtt == 1)
		return (1);
	return (0);
}

int	valid_extension(char *map_path)
{
	int	map_path_len;

	map_path_len = ft_strlen(map_path) - 4;
	if (!ft_strcmp(map_path + map_path_len, ".ber"))
		ft_putstr("Error\nInvalid map extension\n");
	return (ft_strcmp(map_path + map_path_len, ".ber"));
}

int	non_breaks(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if ((str[i] == '\n' && str[i + 1] == '\n')
			|| (str[i] == '\n' && str[i + 1] == '\0'))
		{
			ft_putstr("Error\nYou cant have a breakline in the map!\n");
			return (0);
		}
	}
	return (1);
}
