/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_filling.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lantonio <lantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:46:02 by lantonio          #+#    #+#             */
/*   Updated: 2024/08/23 11:17:34 by lantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	fill(char **map, t_point size, t_point cur, char *to_fill)
{
	int	i;

	i = 0;
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x)
		return ;
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
		return ;
	}
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x)
		return ;
	map[cur.y][cur.x] = '0';
	fill_exit(map, size, (t_point){cur.x - 1, cur.y}, to_fill);
	fill_exit(map, size, (t_point){cur.x, cur.y + 1}, to_fill);
	fill_exit(map, size, (t_point){cur.x + 1, cur.y}, to_fill);
	fill_exit(map, size, (t_point){cur.x, cur.y - 1}, to_fill);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin, "P0C");
	fill_exit(tab, size, begin, 'F');
}

void	ft_putnbr(int n)
{
	int		i;
	char	*str;

	i = 0;
	str = "0123456789";
	if (n > 9)
		ft_putnbr(n / 10);
	i += write (1, &str[n % 10], 1);
}

int	map_lenth(char *av)
{
	int		i;
	int		fd;
	char	c;

	i = 0;
	fd = open(av, O_RDONLY);
	if (fd == -1)
		exit_while_reading(fd);
	while (read(fd, &c, 1))
		i++;
	close(fd);
	return (i);
}
