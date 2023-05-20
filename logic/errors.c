/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmunkhja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:33:47 by zmunkhja          #+#    #+#             */
/*   Updated: 2023/04/21 16:33:50 by zmunkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	horizontal_wall(t_complete *game)
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

static int	vertical_wall(t_complete *game)
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

static void	wall_validation(t_complete *game)
{
	int	vertical_walls;
	int	horizontal_walls;

	vertical_walls = vertical_wall(game);
	horizontal_walls = horizontal_wall(game);
	if (!vertical_walls || !horizontal_walls)
	{
		printf("\nCould not find any wall in this map\n");
		exit_point(game);
	}
}

static void	count_checker(t_complete *game, int height, int width)
{
	if (game->map[height][width] != '1' &&
		game->map[height][width] != '0' &&
		game->map[height][width] != 'P' &&
		game->map[height][width] != 'E' &&
		game->map[height][width] != 'C' &&
		game->map[height][width] != '\n')
	{
		printf("\nThere is an error!%c\n", game->map[height][width]);
		exit_point(game);
	}
	if (game->map[height][width] == 'C')
			game->column_count++;
	if (game->map[height][width] == 'P')
			game->player_count++;
	if (game->map[height][width] == 'E')
			game->exit_count++;
}

void	game_validation(t_complete *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map_height - 1)
	{
		x = 0;
		while (x <= game->map_width)
		{
			count_checker(game, y, x);
			x++;
		}
		y++;
	}
	if (!(game->player_count == 1 && game->column_count > 1
			&& game->exit_count == 1))
	{
		printf("\nError\nSomething is wrong!\n");
		printf("either player, exit or collectable issue\n");
		exit_point(game);
	}
}

void	check_errors(t_complete *game)
{
	wall_validation(game);
	game_validation(game);
}
