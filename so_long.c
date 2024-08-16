/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lantonio <lantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 16:33:57 by lantonio          #+#    #+#             */
/*   Updated: 2024/08/16 17:53:47 by lantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		if (map_validator(av[1]))
			game_init(get_map(av[1]));
		else
			exit(1);
	}
	else
		ft_putstr("Error\nYou need to pass a map path!\n");
	return (0);
}
