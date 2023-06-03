/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmunkhja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:33:38 by zmunkhja          #+#    #+#             */
/*   Updated: 2023/04/21 16:33:41 by zmunkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int move_2_right(game_construct *game, int x, int y)
{
	if (game->map[y][x] == 'E')
	{
		if (game->collectables != 0)
			return (0);
		printf("\nWinner !!!\n");
		exit_game(game);
	}
	if (game->map[y][x] == '0')
	{
		game->map[y][x] = 'P';
		game->x_axis = x;
		game->y_axis = y;
		game->counter++;
	}
	if (game->map[y][x] == 'C')
	{
		game->map[y][x] = 'P';
		game->x_axis = x;
		game->y_axis = y;
		game->collectables--;
		game->counter++;
	}
	return (1);
}

static int go_down_up(game_construct *game, int movement)
{
	int x;
	int y;
	int z;

	x = game->x_axis;
	y = game->y_axis;
	if (movement == 13) // carriage return
	{
		y--;
		if (game->map[y][x] == '1')
			return (0);
		z = move_2_right(game, x, y);
		if (!z)
			return (0);
		game->map[y + 1][x] = '0';
	}
	else if (movement == 1)
	{
		y++;
		if (game->map[y][x] == '1')
			return (0);
		z = move_2_right(game, x, y);
		if (!z)
			return (0);
		game->map[y - 1][x] = '0';
	}
	printf("The number of steps: %i\n", game->counter);
	printf("The number of pizza should be eaten: %i\n", game->collectables);

	return (1);
}

static int go_left_right(game_construct *game, int movement)
{
	int x;
	int y;
	int z;

	x = game->x_axis;
	y = game->y_axis;
	if (movement == 0)
	{
		x--;
		if (game->map[y][x] == '1')
			return (0);
		z = move_2_right(game, x, y);
		if (!z)
			return (0);
		game->map[y][x + 1] = '0';
	}
	else if (movement == 2)
	{
		x++;
		if (game->map[y][x] == '1')
			return (0);
		z = move_2_right(game, x, y);
		if (!z)
			return (0);
		game->map[y][x - 1] = '0';
	}
	printf("The number of steps: %i\n", game->counter);
	printf("The number of pizza should be eaten: %i\n", game->collectables);
	return (1);
}

int handleKeyboardEvent(int command, game_construct *game)
{
	int mode;

	if (command == 53)
		exit_game(game);
	if (command == 13)
		mode = go_down_up(game, command);
	if (command == 1)
		mode = go_down_up(game, command);
	if (command == 0)
		mode = go_left_right(game, command);
	if (command == 2)
		mode = go_left_right(game, command);
	if (mode)
	{
		render_ui(game);
		mlx_string_put(game->mlxpointer, game->winpointer, 10, 10, 0xFFFFFF, "Collect:");
		mlx_string_put(game->mlxpointer, game->winpointer, 10, 30, 0xFFFFFF, "Steps:");

		char scoreStr[10];
		char stepStr[10];

		sprintf(scoreStr, "%i", game->collectables);
		sprintf(stepStr, "%i", game->counter);

		mlx_string_put(game->mlxpointer, game->winpointer, 70, 10, 0xFFFFFF, scoreStr);
		mlx_string_put(game->mlxpointer, game->winpointer, 70, 30, 0xFFFFFF, stepStr);
	}
	// mlx_clear_window(game->mlxpointer, game->winpointer);

	return (1);
}
