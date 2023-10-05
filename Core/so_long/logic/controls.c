/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmunkhjargal <zmunkhjargal@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:33:38 by zmunkhja          #+#    #+#             */
/*   Updated: 2023/07/28 18:20:21 by zmunkhjarga      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static int	move_2_right(t_game_construct *game, int x, int y)
{
	if (game->map[y][x] == MAP_EXIT)
	{
		if (game->collectables != 0)
			return (0);
		printf("\nWinner !!!\n");
		exit_game(game);
	}
	if (game->map[y][x] == FLOOR)
	{
		game->map[y][x] = PLAYER;
		game->x_axis = x;
		game->y_axis = y;
		game->counter++;
	}
	if (game->map[y][x] == COLLECTABLE)
	{
		game->map[y][x] = PLAYER;
		game->x_axis = x;
		game->y_axis = y;
		game->collectables--;
		game->counter++;
	}
	return (1);
}

static int	wall_check(int current_position)
{
	if (current_position == WALL)
		return (0);
	return (1);
}

static int	go_down_up(t_game_construct *game, int movement)
{
	int		x;
	int		y;
	int		z;

	x = game->x_axis;
	y = game->y_axis;
	if (movement == UP)
	{
		y--;
		z = move_2_right(game, x, y);
		if (!z)
			return (0);
		game->map[y + 1][x] = FLOOR;
	}
	else if (movement == DOWN)
	{
		y++;
		z = move_2_right(game, x, y);
		if (!z)
			return (0);
		game->map[y - 1][x] = FLOOR;
	}
	printf("The number of steps: %i\n", game->counter);
	printf("The number of pizza should be eaten: %i\n", game->collectables);
	return (wall_check(game->map[y][x]));
}

static int	go_left_right(t_game_construct *game, int movement)
{
	int		x;
	int		y;
	int		z;

	x = game->x_axis;
	y = game->y_axis;
	if (movement == LEFT)
	{
		x--;
		z = move_2_right(game, x, y);
		if (!z)
			return (0);
		game->map[y][x + 1] = FLOOR;
	}
	else if (movement == RIGHT)
	{
		x++;
		z = move_2_right(game, x, y);
		if (!z)
			return (0);
		game->map[y][x - 1] = FLOOR;
	}
	printf("The number of steps: %i\n", game->counter);
	printf("The number of pizza should be eaten: %i\n", game->collectables);
	return (wall_check(game->map[y][x]));
}

int	handle_keyboard_event(int command, t_game_construct *game)
{
	int		mode;
	char	score_str[10];
	char	step_str[10];

	if (command == ESC || command == X)
		exit_game(game);
	if (command == UP || command == DOWN)
		mode = go_down_up(game, command);
	if (command == LEFT || command == RIGHT)
		mode = go_left_right(game, command);
	if (mode)
	{
		render_ui(game);
		mlx_string_put(game->mlxpointer, game->winpointer,
			10, 10, 0xFFFFFF, "Collect:");
		mlx_string_put(game->mlxpointer, game->winpointer,
			10, 30, 0xFFFFFF, "Steps:");
		sprintf(score_str, "%i", game->collectables);
		sprintf(step_str, "%i", game->counter);
		mlx_string_put(game->mlxpointer, game->winpointer,
			70, 10, 0xFFFFFF, score_str);
		mlx_string_put(game->mlxpointer, game->winpointer,
			70, 30, 0xFFFFFF, step_str);
	}
	return (1);
}
