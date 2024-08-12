/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lantonio <lantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 16:33:57 by lantonio          #+#    #+#             */
/*   Updated: 2024/08/12 19:12:36 by lantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int main(int ac, char **av)
{
	char **map;

	(void)ac;
	map = get_map(av[1]);
	if (map_validator(av[1]))
		map_render(get_map(av[1]));
	else
		printf("KO main\n");
	
	return (0);
}
