/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_pos_info_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <hejang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 13:43:47 by yukim             #+#    #+#             */
/*   Updated: 2022/10/17 11:29:56 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	case_space(char *str);

int	change_rgb_str_to_array(char *rgb_str, int *array)
{
	int		i;
	char	*comma_ptr;
	char	*start;

	i = 0;
	start = rgb_str;
	while (i < 3)
	{
		array[i] = ERROR;
		comma_ptr = ft_strchr(start, ',');
		if (comma_ptr)
			*comma_ptr = '\0';
		if ((comma_ptr && i < 2) || (comma_ptr == NULL && i == 2))
			array[i] = ft_atoi(start);
		if (array[i] == ERROR)
			return (ERROR);
		else if (array[i] == SPACE)
			return (case_space(start));
		comma_ptr++;
		start = comma_ptr;
		i++;
	}
	return (TRUE);
}

static int	case_space(char *str)
{
	while (0 <= *str && *str <= 9)
		str++;
	while (*str)
	{
		if (is_space(*str) == FALSE)
			return (ERROR);
		str++;
	}
	return (TRUE);
}

char	*get_second_info(char *str)
{
	char	*second_info;
	int		i;

	second_info = NULL;
	while (*str && is_space(*str))
		str++;
	if (*str)
	{
		second_info = ft_strdup(str);
		if (!second_info)
			ft_error("[func : get_second_info] malloc faild.");
	}
	i = 0;
	while (second_info[i] && second_info[i] != '\n' && !is_space(second_info[i]))
		i++;
	second_info[i] = '\0';
	return (second_info);
}

char	*get_rgb_str(char **line)
{
	char	*copy;
	char	*rgb_str;
	int		i;

	if (!(*line))
	{
		return (NULL);
	}
	copy = get_skipped_copy_line(line, 0);
	if (!copy)
		return (NULL);
	i = extract_first_info_textlen(copy);
	rgb_str = get_second_info(copy + i);
	free(copy);
	return (rgb_str);
}
