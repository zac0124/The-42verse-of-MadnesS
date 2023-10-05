/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmunkhjargal <zmunkhjargal@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:33:47 by zmunkhja          #+#    #+#             */
/*   Updated: 2023/08/08 16:35:20 by zmunkhjarga      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	count_checker(t_game_construct *game, int height, int width)
{
	if (game->map[height][width] == COLLECTABLE)
		game->collectables++;
	if (game->map[height][width] == PLAYER)
		game->player_count++;
	if (game->map[height][width] == MAP_EXIT)
		game->exit_count++;
	if (game->map[height][width] != WALL &&
		game->map[height][width] != FLOOR &&
		game->map[height][width] != PLAYER &&
		game->map[height][width] != MAP_EXIT &&
		game->map[height][width] != COLLECTABLE &&
		game->map[height][width] != '\n')
	{
		printf("\nError!\nThere is an error!%c\n", game->map[height][width]);
		exit_game(game);
	}
}

void	game_validation(t_game_construct *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map_height - 1)
	{
		x = 0;
		while (x < game->map_width)
		{
			count_checker(game, y, x);
			x++;
		}
		y++;
	}
	if (
		game->player_count != 1
		|| game->collectables < 1
		|| game->exit_count != 1
	)
	{
		printf("\nError!\nGame validation went wrong!\n");
		exit_game(game);
	}
}

void	check_errors(t_game_construct *game)
{
	wall_validation(game);
	game_validation(game);
}
