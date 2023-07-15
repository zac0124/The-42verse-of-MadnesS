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

#include "../headers/so_long.h"

void	count_checker(t_game_construct *game, int height, int width)
{
	if (game->map[height][width] != '1' &&
		game->map[height][width] != '0' &&
		game->map[height][width] != 'P' &&
		game->map[height][width] != 'E' &&
		game->map[height][width] != 'C' &&
		game->map[height][width] != '\n')
	{
		printf("\nError!\nThere is an error!%c\n", game->map[height][width]);
		exit_game(game);
	}
	if (game->map[height][width] == 'C')
		game->column_count++;
	if (game->map[height][width] == 'P')
		game->player_count++;
	if (game->map[height][width] == 'E')
		game->exit_count++;
}

void	game_validation(t_game_construct *game)
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
		printf("\nError!\nSomething is wrong!\n");
		printf("either player, exit or collectable issue\n");
		exit_game(game);
	}
}

void	check_errors(t_game_construct *game)
{
	wall_validation(game);
	game_validation(game);
}
