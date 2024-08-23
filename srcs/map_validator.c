/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lantonio <lantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 16:42:21 by lantonio          #+#    #+#             */
/*   Updated: 2024/08/23 12:05:00 by lantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**get_map(char *av)
{
	int		i;
	char	c;
	int		fd;
	char	**matrix;
	char	*str;

	i = 0;
	if (!valid_extension(av))
		exit(1);
	fd = open(av, O_RDONLY);
	if (fd == -1)
		exit_while_reading(fd);
	str = malloc(sizeof (char *) * (map_lenth(av) + 1));
	while (read(fd, &c, 1))
		str[i++] = c;
	str[i] = '\0';
	if (ft_strlen(str) < 9)
		exit_on_read(fd, str);
	close(fd);
	if (!non_breaks(str))
		exit_cause_break(str);
	matrix = ft_split(str, '\n');
	free(str);
	return (matrix);
}

int	line_validator(char *str)
{
	while (*str)
	{
		if (*str != '1')
		{
			ft_putstr("Error\nThe top or the bottom of the map is not closed!\n");
			return (1);
		}
		str++;
	}
	return (0);
}

int	column_validator(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i][0] != '1' || str[i][ft_strlen(str[i]) - 1] != '1')
		{
			ft_putstr("Error\nAt least one of the map collumns is not closed!\n");
			return (0);
		}
		i++;
	}
	return (1);
}

void	keep_validating(char *av)
{
	int		w;
	int		h;
	char	**map;
	char	**map_new;

	map = get_map(av);
	map_new = get_map(av);
	w = ft_strlen(map[0]) + 1;
	h = matrix_len(map) + 1;
	flood_fill(map, (t_point){w, h}, get_char_position(map_new, 'P'));
	if (char_validator(map, 'P') || char_validator(map, 'E')
		|| char_validator(map, 'C'))
	{
		free_matrix(map);
		free_matrix(map_new);
		ft_putstr("Error\nCan't catch all the collectables and exit!\n");
		exit (1);
	}
	free_matrix(map);
	free_matrix(map_new);
}

int	map_validator(char *av)
{
	int		flag;
	char	**map;

	flag = 0;
	map = get_map(av);
	if (line_validator(map[0]) || line_validator(map[matrix_len(map) - 1]))
		flag = 1;
	if (!column_validator(map) || !valid_dimentions(map))
		flag = 1;
	if (!player_validator(map) || !collectable_validator(map))
		flag = 1;
	if (!exit_validator(map) || !valid_chars_only(map))
		flag = 1;
	free_matrix(map);
	if (flag)
		return (0);
	keep_validating(av);
	return (1);
}
