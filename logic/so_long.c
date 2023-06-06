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

int exit_game(game_construct *game)
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
	if (argc != 2)
	{
		perror("\033[1;31m🛑ERROR \033[0m FORGOT TO INCLUDE YOUR MAP ???");
		exit(1);
	}
	ft_memset(&game, 0, sizeof(game_construct));
	read_map(&game, argv);
	if (game.map != NULL)
	{
		check_errors(&game);
		game.mlxpointer = mlx_init();
		game.winpointer = mlx_new_window(game.mlxpointer, (game.map_width * 40),
										 (game.map_height * 40), "so_long");
		insert_images(&game);
		render_ui(&game);
		mlx_key_hook(game.winpointer, handleKeyboardEvent, &game);
		mlx_hook(game.winpointer, 10, 0, (void *)exit, 0);
		mlx_hook(game.winpointer, 17, 1L<<17, (void *)exit, 0);

		mlx_loop(game.mlxpointer);
	}
	return (0);
}