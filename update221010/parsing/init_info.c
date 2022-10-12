/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <hejang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 14:45:10 by hejang            #+#    #+#             */
/*   Updated: 2022/10/12 18:58:08 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	init_info_texture_color(t_info *info, int type, char *tmp);
static void	read_map(int fd, t_info *info, char *tmp);
static void	init_rgb_array(t_info *info);
static void	case_mapchar(int fd, t_info *info, char *tmp);

void	init_info(int fd, t_info *info)
{
	int		type;
	char	*tmp;

	init_rgb_array(info);
	tmp = get_next_line(fd);
	while (tmp)
	{
		type = get_text_type(&tmp, fd);
		if (type != MAP_CHARACTER)
			init_info_texture_color(info, type, tmp);
		else if (type == MAP_CHARACTER)
		{
			case_mapchar(fd, info, tmp);
			break ;
		}
		else if (type == ERROR)
			ft_error(".cub file format error");
		if (tmp)
			free(tmp);
		tmp = get_next_line(fd);
	}
	is_valid_element_color(info);
}

static void	init_rgb_array(t_info *info)
{
	int		i;

	i = 0;
	while (i < 3)
	{
		info->ceiling_color[i] = -999;
		info->floor_color[i] = -999;
		i++;
	}
}

static void	case_mapchar(int fd, t_info *info, char *tmp)
{
	is_map_last(info);
	read_map(fd, info, tmp);
}

static void	init_info_texture_color(t_info *info, int type, char *tmp)
{
	if (type == TEXTURE_NO)
		info->north_texture = get_texture_filepath(&tmp);
	else if (type == TEXTURE_SO)
		info->south_texture = get_texture_filepath(&tmp);
	else if (type == TEXTURE_WE)
		info->west_texture = get_texture_filepath(&tmp);
	else if (type == TEXTURE_EA)
		info->east_texture = get_texture_filepath(&tmp);
	else if (type == FLOOR)
		get_rgb_array(&tmp, info->floor_color);
	else if (type == CEILLING)
		get_rgb_array(&tmp, info->ceiling_color);
}

static void	read_map(int fd, t_info *info, char *tmp)
{
	int		sp_cnt;
	char	*bb;
	int		len;

	sp_cnt = 0;
	info->width = -1;
	info->height = 0;
	info->backup = ft_strdup("");
	while (tmp)
	{
		len = ft_strlen(tmp);
		if ((info->width) < len)
			info->width = ft_strlen(tmp);
		sp_cnt += check_map_element(tmp);
		bb = info->backup;
		info->backup = ft_strjoin(bb, tmp);
		free(tmp);
		free(bb);
		tmp = get_next_line(fd);
		info->height++;
	}
	if (sp_cnt > 1)
		ft_error("too many start point");
}
