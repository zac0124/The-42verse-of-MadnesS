/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmunkhja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 13:15:41 by zmunkhja          #+#    #+#             */
/*   Updated: 2023/08/11 14:15:11 by zmunkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	check_file_type(char *str, t_game_construct *game)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	if (str[i - 1] != 'r' && str[i - 2] != 'e'
		&& str[i - 3] != 'r' && str[i - 4] != '.')
	{
		perror("\033[1;31m🛑 ERROR\n \033[0m Invalid Map Extension!\n");
		return (exit_game(game));
	}
	return (1);
}

void	flood_fill(t_game_construct *game, int paint, int y, int x)
{
	if (game->copy_map[y][x] == WALL)
		return ;
	else if (game->copy_map[y][x] == COLLECTABLE)
	{
		game->copy_collectables++;
		game->copy_map[y][x] = FLOOR;
	}
	else if (game->copy_map[y][x] == MAP_EXIT)
	{
		game->copy_exit++;
		game->copy_map[y][x] = FLOOR;
	}
	if (game->copy_map[y][x] == FLOOR)
	{
		game->copy_map[y][x] = paint;
		flood_fill(game, paint, y, x + 1);
		flood_fill(game, paint, y, x - 1);
		flood_fill(game, paint, y + 1, x);
		flood_fill(game, paint, y - 1, x);
	}
}

int	valid_path(t_game_construct *game, int y, int x)
{
	int		i;

	i = 0;
	game->copy_map = malloc(sizeof(char *) * (game->map_width + 1));
	while (game->map[i])
	{
		game->copy_map[i] = ft_strdup(game->map[i]);
		i++;
	}
	y = game->y_axis;
	x = game->x_axis;
	game->copy_map[y][x] = FLOOR;
	flood_fill(game, 'P', y, x);
	if (game->collectables != game->copy_collectables
		|| game->exit_count != game->copy_exit)
	{
		perror("\033[1;31m🛑 ERROR\n \033[0m Path is not valid!\n");
		exit_game(game);
	}
	return (1);
}

int	check_valid_map(t_game_construct *game)
{
	int		y;
	int		x;

	y = 0;
	while (game->map[y] != 0)
	{
		x = 0;
		while (game->map[y][x] != 0)
		{
			if (game->map[y][x] == PLAYER)
			{
				game->x_axis = x;
				game->y_axis = y;
			}
			x++;
		}
		y++;
	}
	valid_path(game, y, x);
	return (0);
}
