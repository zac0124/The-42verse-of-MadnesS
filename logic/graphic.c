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

static unsigned int ft_numsize(int n)
{
	unsigned int len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
		len += 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char *ft_itoa(int n)
{
	char *str;
	unsigned int num;
	unsigned int len;

	len = ft_numsize(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		num = -n;
	}
	else
		num = n;
	if (num == 0)
		str[0] = '0';
	str[len] = '\0';
	while (num != 0)
	{
		str[len - 1] = (num % 10) + '0';
		num = num / 10;
		len--;
	}
	return (str);
}

void place_player(game_construct *game, int height, int width)
{
	mlx_put_image_to_window(game->mlxpointer,
							game->winpointer, game->player, width * 40, height * 40);
	game->y_axis = height;
	game->x_axis = width;
}

void place_score(game_construct *game)
{
	int counter = game->counter;
	int pizza_count = game->collectables;
	

	char *step = ft_itoa(counter);
	char *pizza = ft_itoa(pizza_count);
	mlx_string_put(game->mlxpointer, game->winpointer, 5, 10, 0xffffff, step);
	mlx_string_put(game->mlxpointer, game->winpointer, 5, 20, 0xffffff, pizza);
}

void place_collectable(game_construct *game, int height, int width)
{
	mlx_put_image_to_window(game->mlxpointer,
							game->winpointer, game->collectable, width * 40, height * 40);
	game->collectables++;
}

void place_images_in_game(game_construct *game)
{
	int width;
	int height;

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

void adding_in_graphics(game_construct *game)
{
	int height;
	int width;

	height = 0;
	while (height < game->map_height)
	{
		width = 0;
		while (game->map[height][width])
		{
			if (game->map[height][width] == '1')
				mlx_put_image_to_window(game->mlxpointer,
										game->winpointer, game->wall, width * 40, height * 40);
			if (game->map[height][width] == 'C')
				place_collectable(game, height, width);
			if (game->map[height][width] == 'P')
				place_player(game, height, width);
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
