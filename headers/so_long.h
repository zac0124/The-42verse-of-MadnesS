/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmunkhja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:32:56 by zmunkhja          #+#    #+#             */
/*   Updated: 2023/04/21 16:32:59 by zmunkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "get_next_line.h"
# include "../minilibx/mlx.h"

typedef struct game_start
{
	int		fd;
	int		map_height;
	int		map_width;
	int		player_count;
	int		column_count;
	int		exit_count;
	int		x_axis;
	int		y_axis;
	int		counter;
	int		collectables;

	char	**map;

	void	*floor;
	void	*wall;
	void	*player;
	void	*exit;
	void	*collectable;
	void	*mlxpointer;
	void	*winpointer;

}	game_construct;

int		exit_point(game_construct *game);
int		map_reading(game_construct *game, char **argv);
int		controls_working(int command, game_construct *game);
void	adding_in_graphics(game_construct *game);
void	place_images_in_game(game_construct *game);
void	check_errors(game_construct *game);
void 	place_score(game_construct *game);


#endif
