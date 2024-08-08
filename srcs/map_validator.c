/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lantonio <lantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 16:42:21 by lantonio          #+#    #+#             */
/*   Updated: 2024/08/08 17:01:41 by lantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**get_map(char **av)
{
	int		i;
	char	c;
	int		fd;
	char	**mat;
	char	str[2000];

	i = 0;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Error\nErro ao ler o mapa\n");
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
			return (0);
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

int	character_and_collectible_validator(char **str)
{
	int	i;
	int	j;
	int	qtt_e_p;
	int	qtt_c;

	i = 0;
	qtt_c = 0;
	qtt_e_p = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'E' || str[i][j] == 'P')
				qtt_e_p++;
			if (str[i][j] == 'C')
				qtt_c++;
			j++;
		}
		i++;
	}
	if (qtt_e_p == 2 && qtt_c)
		return (1);
	return (0);
}

void	flood_fill(char **map, int x, int y, int *found)
{
	if (map[x][y] == 'P')
	{
		printf("OK\n");
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
		return (k);
	return (0);
}