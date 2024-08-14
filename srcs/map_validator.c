/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lantonio <lantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 16:42:21 by lantonio          #+#    #+#             */
/*   Updated: 2024/08/14 17:34:30 by lantonio         ###   ########.fr       */
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

void	fill(char **map, t_point size, t_point cur, char *to_fill)
{
    int i;
    i = 0;
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x)
		return;
    while (to_fill[i])
    {
        if (to_fill[i] == (char)map[cur.y][cur.x])
        {
            map[cur.y][cur.x] = 'F';
            fill(map, size, (t_point){cur.x - 1, cur.y}, to_fill);
            fill(map, size, (t_point){cur.x, cur.y + 1}, to_fill);
            fill(map, size, (t_point){cur.x + 1, cur.y}, to_fill);
            fill(map, size, (t_point){cur.x, cur.y - 1}, to_fill);
        }
        i++;
    }
}
void	fill_exit(char **map, t_point size, t_point cur, char to_fill)
{
	if (to_fill != map[cur.y][cur.x])
	{
		map[cur.y][cur.x] = '0';
		return;	
	}
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x)
		return;
    map[cur.y][cur.x] = '0';
	fill_exit(map, size, (t_point){cur.x - 1, cur.y}, to_fill);
    fill_exit(map, size, (t_point){cur.x, cur.y + 1}, to_fill);
    fill_exit(map, size, (t_point){cur.x + 1, cur.y}, to_fill);
    fill_exit(map, size, (t_point){cur.x, cur.y - 1}, to_fill);
}
void	flood_fill_2(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin, "P0C");
	fill_exit(tab, size, begin, 'F');
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

int	map_validator(char *av)
{
	int	i;
	int	flag;
	int	width;
	int	height;

	i = 0;
	flag = 0;
	char **map = get_map(av);
	// while (map[i])
	// 	i++;
	// if (!line_validator(map[0]) && !line_validator(map[i - 1]))
	// 	flag = 1;
	// if (!column_validator(map))
	// 	flag = 1;
	// if (!character_validator(map))
	// 	flag = 1;
	// if (!exit_validator(map))
	// 	flag = 1;
	// if (flag)
	// 	return (0);
	map = get_map(av);
	//map_dimentions(map, &width, &height, &flag);
	flood_fill_2(map, (t_point){ft_strlen(map[0]) + 1, matrix_len(map) + 1}, get_char_position(get_map(av), 'P'));
	if (char_validator(map, 'P') || char_validator(map, 'E') || char_validator(map, 'C'))
	{
		ft_putstr("Its not possible to catch all the collectibles and exit\n");
		return (0);
	}
	return (1);
}
