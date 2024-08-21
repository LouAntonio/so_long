/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lantonio <lantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 16:33:57 by lantonio          #+#    #+#             */
/*   Updated: 2024/08/21 12:33:44 by lantonio         ###   ########.fr       */
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
			return (1);
	}
	else
		ft_putstr("Error\nInvalid number of arguments!\n");
	return (0);
}
