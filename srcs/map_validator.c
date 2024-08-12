/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lantonio <lantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 16:42:21 by lantonio          #+#    #+#             */
/*   Updated: 2024/08/12 12:52:47 by lantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**get_map(char *av)
{
	int		i;
	char	c;
	int		fd;
	char	**mat;
	char	str[2000];

	i = 0;
	fd = open(av, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Error\nError while reading the map!\n");
		exit(1);
	}
	while (read(fd, &c, 1))
		str[i++] = c;
	str[i] = '\0';
	close(fd);
	mat = ft_split(str, '\n');
	return (mat);
}

int	line_validator(char *str)
{
	while (*str)
	{
		if (*str != '1')
		{
			ft_putstr("Error\nThe top or the bottom of the map is not closed!\n");
			return (0);
		}
		str++;
	}
	return (1);
}

int	column_validator(char **str)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (str[i])
	{
		if (str[i][0] == '1' && str[i][strlen(str[i]) - 1] == '1')
			k++;
		i++;
	}
	if (k == i)
		return (1);
	return (0);
}

int	character_validator(char **map)
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
			if (map[i][j] == 'P')
				qtt++;
			j++;
		}
		i++;
	}
	if (qtt == 0)
		ft_putstr("Error\nThere is not a player in the map!\n");
	if (qtt > 1)
		ft_putstr("Error\nThere is more then one player in the map!\n");
	if (qtt == 1)
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
		ft_putstr("Error\nThere is not a exit in the map!\n");
	else if (qtt > 1)
		ft_putstr("Error\nThere is more then one exit in the map!\n");
	if (qtt == 1)
		return (1);
	return (0);
}

void	flood_fill(char **map, int x, int y, int *found)
{
	if (map[x][y] == 'P')
	{
		*found = 1;
		return ;
	}
	if (map[x][y] == '1' || map[x][y] == 'V')
		return ;
	map[x][y] = 'V';
	flood_fill(map, x + 1, y, found);
	flood_fill(map, x - 1, y, found);
	flood_fill(map, x, y + 1, found);
	flood_fill(map, x, y - 1, found);
}

int	its_possible(char **map, char c)
{
	int	i;
	int	j;
	int	k;
	int	found;

	i = 0;
	j = 0;
	k = 0;
	found = 0;
	while (map[i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == c)
			{
				flood_fill(map, i, j, &found);
				k++;
			}
		}
		i++;
	}
	if (k == found)
		return (1);
	return (0);
}

void	map_dimentions(char **map, int *width, int *height, int *flag)
{
	int	i;
	int	j;
	int	k;

	i = matrix_len(map);
	k = ft_strlen(map[0]);
	*height = matrix_len(map);
	i = 0;
	while (map[i])
	{
		j = ft_strlen(map[i]);
		if (j != k)
		{
			ft_putstr("Error\nThe map collumns lenth don't match!\n");
			*width = 0;
			*flag = 1;
			break ;
		}
		i++;
	}
	*width = k;
	if (width == height)
	{
		ft_putstr("The map is a square!\n");
		*flag = 1;
	}
}

int	map_validator(char **map)
{
	int	i;
	int	flag;
	int	width;
	int	height;

	i = 0;
	flag = 0;
	while (map[i])
		i++;
	if (!line_validator(map[0]) && !line_validator(map[i - 1]))
		flag = 1;
	if (!column_validator(map))
		flag = 1;
	if (!character_validator(map))
		flag = 1;
	if (!exit_validator(map))
		flag = 1;
	map_dimentions(map, &width, &height, &flag);
	if (flag)
		return (0);
	if (!its_possible(map, 'C') || !its_possible(map, 'E'))
	{
		printf("Its not possible to catch all the collectibles and exit!\n");
		return (0);
	}
	printf("W = %d | H = %d\n", width, height);
	return (1);
}
