/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_second_position_value.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukim <yukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 13:38:32 by yukim             #+#    #+#             */
/*   Updated: 2022/09/24 13:38:32 by yukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"

// outside : if get_texture_filepath return NULL => ERROR
char *get_texture_filepath(char **line)
{
	char	*copy;
	char	*filepath;
	int		i;

	if (!*(line))
		return (NULL);
	copy = get_skipped_copy_line(line, 0);
	if (!copy)
		return (NULL);
	i = extract_first_info_textlen(copy);
	filepath = get_second_info(copy + i);
	free(copy);
//	free(line);
//	*line = NULL;
	return(filepath);
}


// outside : if get_color_array_value return ERROR => ERROR
int get_rgb_array(char **line, int *array)
{
	char	*rgb_str;
	int		i;
	int		res;

	if (!(*line))
		return (ERROR);
	res = ERROR;
	rgb_str = get_rgb_str(line);
	if (rgb_str)
	{
		change_rgb_str_to_array(rgb_str, array, &res);
		free(rgb_str);
	}
//	free(*line);
//	*line = NULL;
	return (res);
}











