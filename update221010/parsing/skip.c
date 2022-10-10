/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukim <yukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 13:38:44 by yukim             #+#    #+#             */
/*   Updated: 2022/10/10 16:25:24 by yukim            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*get_skipped_copy_line(char **line, int fd)
{
	char	*copy;

	if (*line)
		skip_new_line(line, fd);
	if (!(*line))
		return (NULL);
	copy = skip_start_space(line, fd);
	if (!copy)
	{
		free(*line);
		*line = NULL;
		return (NULL);
	}
	return (copy);
}

void	skip_new_line(char **line, int fd)
{
	if (!(*line))
		return ;
	while (**line == '\n')
	{
		free(*line);
		*line = get_next_line(fd);
		if (!(*line))
			return ;
	}
}

char	*skip_start_space(char **line, int fd)
{
	int		i;
	char	*copy;

	if (!(*line))
		return (NULL);
	i = 0;
	while ((*line)[i] && is_space((*line)[i]))
		i++;
	if ((*line)[i] == '\0' && fd > 0)
	{
		free(*line);
		*line = get_next_line(fd);
		if (!(*line))
			return (NULL);
		get_text_type(line, fd);
	}
	copy = ft_strdup(&(*line)[i]);
	if (!copy)
		ft_error("[func : skip_start_space] malloc failed.");
	return (copy);
}

int	ft_skip(const char *str, int *i)
{
	while (is_space(str[*i]) == TRUE)
		(*i)++;
	return (0);
}
