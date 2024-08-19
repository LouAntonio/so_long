/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_filling.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lantonio <lantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:46:02 by lantonio          #+#    #+#             */
/*   Updated: 2024/08/19 09:19:20 by lantonio         ###   ########.fr       */
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

int	char_in_str(char c)
{
	if (c == '1' || c == '0' || c == 'P' || c == 'E' || c == 'C')
		return (1);
	return (0);
}
