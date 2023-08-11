/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmunkhjargal <zmunkhjargal@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 18:50:56 by zmunkhja          #+#    #+#             */
/*   Updated: 2023/08/08 16:31:00 by zmunkhjarga      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static int	horizontal_wall(t_game_construct *game)
{
	int	x;
	int	y;

	x = game->map_width;
	y = 0;
	while (y < x)
	{
		if (game->map[0][x] == '1' && game->map[game->map_height - 1][y] == '1')
			return (0);
		y++;
	}
	return (1);
}

static int	vertical_wall(t_game_construct *game)
{
	int	y;
	int	x;

	y = 0;
	x = game->map_width;
	while (y < game->map_height)
	{
		if (!(game->map[y][0] == '1' && game->map[y][x - 1] == '1'))
			return (0);
		y++;
	}
	return (1);
}

void	wall_validation(t_game_construct *game)
{
	int		vertical_walls;
	int		horizontal_walls;

	vertical_walls = vertical_wall(game);
	horizontal_walls = horizontal_wall(game);
	if (!vertical_walls || !horizontal_walls)
	{
		printf("\nError!\nCould not find valid wall in this map\n");
		exit_game(game);
	}
}
