/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmunkhjargal <zmunkhjargal@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:34:10 by zmunkhja          #+#    #+#             */
/*   Updated: 2023/08/08 15:13:05 by zmunkhjarga      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static void	*ft_memset(void *game, int counter, size_t length)
{
	unsigned char	*p;

	p = (unsigned char *)game;
	while (length--)
		*p++ = (unsigned char)counter;
	return (game);
}


int	close_game(void)
{
	exit(0);
}

int	exit_game(t_game_construct *game)
{
	int		line;

	line = 0;
	if (game->winpointer)
		mlx_destroy_window(game->mlxpointer, game->winpointer);
	free(game->mlxpointer);
	while (line < game->map_height - 1)
		free(game->map[line++]);
	free(game->map);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_game_construct	game;

	if (argc != 2)
	{
		perror("\033[1;31m🛑 ERROR\n \033[0m FORGOT TO INCLUDE YOUR MAP ???");
		exit(1);
	}
	ft_memset(&game, 0, sizeof(t_game_construct));
	check_file_type(argv[1], &game);
	read_map(&game, argv);
	if (game.map != 0 )
	{
		check_errors(&game);
		check_valid_map(&game);
		game.mlxpointer = mlx_init();
		game.winpointer = mlx_new_window(game.mlxpointer, (game.map_width * 40),
				(game.map_height * 40), "so_long");
		insert_images(&game);
		render_ui(&game);
		mlx_key_hook(game.winpointer, handle_keyboard_event, &game);
		mlx_hook(game.winpointer, 10, 0, exit_game, 0);
		mlx_hook(game.winpointer, 17, 1L << 17, close_game, 0);
		mlx_loop(game.mlxpointer);
	}
	return (0);
}
