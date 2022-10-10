/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <hejang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 21:54:41 by hejang            #+#    #+#             */
/*   Updated: 2022/10/10 00:53:35 by hejang           ###   ########.fr       */
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

// parsing
void	check_argument(int argc, char **argv);
int		get_text_type(char **line, int fd);
int		extract_first_info_textlen(char *line);
char	*get_texture_filepath(char **line);
int		get_rgb_array(char **line, int *array);
char	*get_second_info(char *str);
char	*get_rgb_str(char **line);
int		change_rgb_str_to_array(char *line, int *array, int *res);
int		ft_skip(const char *str, int *i);
char	*get_skipped_copy_line(char **line, int fd);
void	skip_new_line(char **line, int fd);
char	*skip_start_space(char **line, int fd);
void	init_info(int fd, t_info *info);
int		init_map(t_game *game, t_map *map, t_info *info);
int		check_map_element(char *line);
int		is_valid_map(t_map *map);

// init struct
void	init_cub3d(t_game *game);
void	save_dir_vector(t_game *game, char dir);
void	load_window(t_game *game);
void	load_texture(t_game *game);

// key.c
int		key_action(t_game *game);
int		key_press(int keycode, t_game *game);
int		exit_game(t_game *game);
void	rotate_camera(t_game *game);
void	move_left_or_right(t_game *game);
void	move_forward_or_backward(t_game *game);

int		main_loop_ray(t_game *game);

// raycast
void	init_ray_tex_struct(t_ray *ray);
void	raycast(t_game *game);
void	draw(t_game *game);
void	floorcast(t_game *game, t_ray *ray);
void	wallcast(t_game *game);
int		is_hit(t_game *game, t_ray *ray);
void	tex_wall(t_game *game, t_ray *ray);
void	coordinate_tex(t_game *game, t_ray *ray, int x);


#endif