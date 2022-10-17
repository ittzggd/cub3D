/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_pos_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukim <yukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 13:38:32 by yukim             #+#    #+#             */
/*   Updated: 2022/10/17 11:34:43 by yukim            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*get_texture_filepath(char **line)
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
	i = 0;
	while (filepath[i] && is_space(filepath[i]) == FALSE)
		i++;
	if (is_space(filepath[i]) == TRUE)
		filepath[i] = '\0';
	return (filepath);
}

int	get_rgb_array(char **line, int *array)
{
	char	*rgb_str;
	int		res;

	if (!(*line))
		return (ERROR);
	res = ERROR;
	rgb_str = get_rgb_str(line);
	if (rgb_str)
	{
		res = change_rgb_str_to_array(rgb_str, array);
		free(rgb_str);
	}
	return (res);
}
