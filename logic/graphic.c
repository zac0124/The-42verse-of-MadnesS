/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmunkhja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:33:55 by zmunkhja          #+#    #+#             */
/*   Updated: 2023/05/27 16:49:19 by zmunkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_player(t_game_construct *game, int height, int width)
{
	mlx_put_image_to_window(game->mlxpointer,
		game->winpointer, game->player, width * 40, height * 40);
	game->y_axis = height;
	game->x_axis = width;
}

void	render_collectable(t_game_construct *game, int height, int width)
{
	mlx_put_image_to_window(game->mlxpointer,
		game->winpointer, game->collectable, width * 40, height * 40);
	game->collectables++;
}

void	insert_images(t_game_construct *game)
{
	int		width;
	int		height;

	game->floor = mlx_xpm_file_to_image(game->mlxpointer,
			"images/road.xpm", &width, &height);
	game->wall = mlx_xpm_file_to_image(game->mlxpointer,
			"images/wall.xpm", &width, &height);
	game->player = mlx_xpm_file_to_image(game->mlxpointer,
			"images/ninja.xpm", &width, &height);
	game->exit = mlx_xpm_file_to_image(game->mlxpointer,
			"images/home.xpm", &width, &height);
	game->collectable = mlx_xpm_file_to_image(game->mlxpointer,
			"images/pizza.xpm", &width, &height);
}

void	render_ui(t_game_construct *game)
{
	int		height;
	int		width;

	height = 0;
	game->collectables = 0;
	while (height < game->map_height)
	{
		width = 0;
		while (game->map[height][width])
		{
			if (game->map[height][width] == '1')
				mlx_put_image_to_window(game->mlxpointer,
					game->winpointer, game->wall, width * 40, height * 40);
			if (game->map[height][width] == 'C')
				render_collectable(game, height, width);
			if (game->map[height][width] == 'P')
				render_player(game, height, width);
			if (game->map[height][width] == 'E')
				mlx_put_image_to_window(game->mlxpointer,
					game->winpointer, game->exit, width * 40, height * 40);
			if (game->map[height][width] == '0')
				mlx_put_image_to_window(game->mlxpointer,
					game->winpointer, game->floor, width * 40, height * 40);
			width++;
		}
		height++;
	}
}
