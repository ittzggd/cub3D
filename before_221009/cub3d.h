/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukim <yukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 21:54:41 by hejang            #+#    #+#             */
/*   Updated: 2022/09/24 13:49:04 by yukim            ###   ########.fr       */
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



// get_text_type.c
int		get_text_type(char **line, int fd);
int		extract_first_info_textlen(char *line);

// second_pos_info.c
char	*get_texture_filepath(char **line);
int		get_rgb_array(char **line, int *array);

// skip.c
char	*get_skipped_copy_line(char **line, int fd);
void	skip_new_line(char *line, int fd);
char	*skip_start_space(char **line, int fd);

#endif