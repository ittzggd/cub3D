/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_text_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukim <yukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 13:38:36 by yukim             #+#    #+#             */
/*   Updated: 2022/09/24 13:38:36 by yukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"

static int	is_type_identifier(char *skipped_copyline);
static int	is_type_map(char *skipped_copyline);

int get_text_type(char **line, int fd)
{
	char	*copy;
	int		type;


	copy = get_skipped_copy_line(line, fd);
	if (!copy)
		return (0);
	type = is_type_identifier(copy);
	if (type == FALSE)
		type = is_type_map(copy);
	// FREE
	// don't free line here
	// to get second info 
	free(copy);
	if (type == FALSE)
		return (ERROR);
	return (type);
}

int	extract_first_info_textlen(char *line)
{
	// pos = 1 == First Position
	int	len;

	len = 0;
	while (line[len] && is_space(line[len]) == FALSE)
		len++;
	return (len);
}

static int is_type_identifier(char *skipped_copyline)
{
	int	info_len;

	info_len = extract_first_info_textlen(skipped_copyline);
	if (ft_strncmp("NO", skipped_copyline, info_len) == TRUE)
		return (TEXTURE_NO);
	if (ft_strncmp("SO", skipped_copyline, info_len) == TRUE)
		return (TEXTURE_SO);
	if (ft_strncmp("WE", skipped_copyline, info_len) == TRUE)
		return (TEXTURE_WE);
	if (ft_strncmp("EA", skipped_copyline, info_len) == TRUE)
		return (TEXTURE_EA);
	if (ft_strncmp("F", skipped_copyline, info_len) == TRUE)
		return (FLOOR);
	if (ft_strncmp("C", skipped_copyline, info_len) == TRUE)
		return (CEILLING);
	return (FALSE);
}

static int	is_type_map(char *skipped_copyline)
{
	int	i;

	i = 0;
	if (skipped_copyline[i] == '0' || skipped_copyline[i] == '1' || \
		skipped_copyline[i] == 'N' || skipped_copyline[i] == 'S' || \
		skipped_copyline[i] == 'E' || skipped_copyline[i] == 'W')
		return (MAP_CHARACTER);
	return (FALSE);
}
