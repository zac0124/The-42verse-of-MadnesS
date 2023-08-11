/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmunkhjargal <zmunkhjargal@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:32:56 by zmunkhja          #+#    #+#             */
/*   Updated: 2023/08/11 14:20:28 by zmunkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <stdlib.h>
# include "get_next_line.h"
# include "../minilibx/mlx.h"

# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2
# define ESC 53
# define X 17

# define WALL "1"
# define FLOOR "0"
# define COLLECTABLE "C"
# define PLAYER "P"
# define MAP_EXIT "E"

typedef struct s_game_start
{
	int		fd;
	int		map_height;
	int		map_width;
	int		player_count;
	int		exit_count;
	int		x_axis;
	int		y_axis;
	int		counter;
	int		collectables;
	int		copy_collectables;
	int		copy_exit;

	char	**map;
	char	**copy_map;

	void	*floor;
	void	*wall;
	void	*player;
	void	*exit;
	void	*collectable;
	void	*mlxpointer;
	void	*winpointer;

}	t_game_construct;

int		exit_game(t_game_construct *game);
int		close_game(void);
int		read_map(t_game_construct *game, char **argv);
int		handle_keyboard_event(int command, t_game_construct *game);
int		check_file_type(char *str, t_game_construct *game);
int		check_valid_map(t_game_construct *game);
void	render_ui(t_game_construct *game);
void	insert_images(t_game_construct *game);
void	check_errors(t_game_construct *game);
void	game_validation(t_game_construct *game);
void	wall_validation(t_game_construct *game);
void	count_checker(t_game_construct *game, int height, int width);

#endif
