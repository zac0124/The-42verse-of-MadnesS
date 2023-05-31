/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmunkhja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:34:10 by zmunkhja          #+#    #+#             */
/*   Updated: 2023/04/21 16:34:12 by zmunkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void *ft_memset(void *game, int counter, size_t length)
{
	unsigned char *p;

	p = (unsigned char *)game;
	while (length--)
		*p++ = (unsigned char)counter;
	return (game);
}

int exit_point(game_construct *game)
{
	int line;

	line = 0;
	if (game->winpointer)
		mlx_destroy_window(game->mlxpointer, game->winpointer);
	free(game->mlxpointer);
	while (line < game->map_height - 1)
		free(game->map[line++]);
	free(game->map);
	exit(0);
}

int main(int argc, char **argv)
{
	game_construct game;
	// char *step = ft_itoa(game.counter);
	// char *pizzaLeft = ft_itoa(game.collectables);

	if (argc != 2)
	{
		perror("\033[1;31m🛑ERROR \033[0m FORGOT TO INCLUDE YOUR MAP ???");
		exit(1);
	}
	ft_memset(&game, 0, sizeof(game_construct));
	map_reading(&game, argv);
	if (game.map != NULL)
	{
		check_errors(&game);
		game.mlxpointer = mlx_init();
		game.winpointer = mlx_new_window(game.mlxpointer, (game.map_width * 40),
										 (game.map_height * 40), "so_long");
		place_images_in_game(&game);
		adding_in_graphics(&game);
		// mlx_string_put(game.mlxpointer, game.winpointer, 5, 10, 0xffffff, step);
		// mlx_string_put(game.mlxpointer, game.winpointer, 5, 20, 0xffffff, pizzaLeft);

		mlx_key_hook(game.winpointer, controls_working, &game);
		mlx_hook(game.winpointer, 10, 0, (void *)exit, 0);

		mlx_loop(game.mlxpointer);
	}
	return (0);
}
