/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <hejang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 21:54:41 by hejang            #+#    #+#             */
/*   Updated: 2022/09/30 14:03:22 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include "./definecub3d.h"
# include "./utils.h"
# include "./get_next_line.h"
# include "../mlx/mlx.h"


// get_text_type.

int		get_text_type(char **line, int fd);
int		extract_first_info_textlen(char *line);
int		is_space(char c);

// second_pos_info.c
char	*get_texture_filepath(char **line);
int		get_rgb_array(char **line, int *array);

// second_pos_info_utils.c
char	*get_second_info(char *str);
char	*get_rgb_str(char **line);
int		change_rgb_str_to_array(char *line, int *array, int *res);

// skip.c
char	*get_skipped_copy_line(char **line, int fd);
void	skip_new_line(char **line, int fd);
char	*skip_start_space(char **line, int fd);

//init_info.c
void	init_info(int fd, t_info *info);

//map.c
int		init_map(t_game *game, t_map *map, t_info *info);
int		check_map_element(char *line);

void	load_window(t_game *game);
void	load_texture(t_game *game);

// key.c
void	init_keyflag(t_game *game);
int		key_press(int keycode, t_game *game);
int		key_release(int keycode, t_game *game);
void	exit_game(t_game *game);

#endif