/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmunkhjargal <zmunkhjargal@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:34:02 by zmunkhja          #+#    #+#             */
/*   Updated: 2023/08/08 14:19:05 by zmunkhjarga      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static int	width_of_map(char *string)
{
	int	width;

	width = 0;
	while (string[width] != '\0')
		width++;
	if (string[width - 1] == '\n')
		width--;
	return (width);
}

static int	copy_map_line(t_game_construct *game, char *line)
{
	int		i;

	if (!line)
		return (0);
	i = 0;
	game->map_height++;
	game->copy_map = (char **)malloc(sizeof(char *) * (game->map_height + 1));
	game->copy_map[game->map_height] = 0;
	while (i < game->map_height - 1)
	{
		game->copy_map[i] = game->map[i];
		i++;
	}
	game->copy_map[i] = line;
	if (game->map)
		free(game->map);
	game->map = game->copy_map;
	return (1);
}

int	read_map(t_game_construct *game, char **argv)
{
	char	*readmap;

	game->fd = open(argv[1], O_RDONLY);
	if (game->fd < 0)
		return (0);
	while (1)
	{
		readmap = get_next_line(game->fd);
		if (!copy_map_line(game, readmap))
			break ;
	}
	close (game->fd);
	game->map_width = width_of_map(game->map[0]);
	return (1);
}
