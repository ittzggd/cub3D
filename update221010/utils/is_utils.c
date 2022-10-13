/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <hejang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 13:47:01 by yukim             #+#    #+#             */
/*   Updated: 2022/10/13 20:01:25 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	is_space(char c)
{
	return ( c == ' ' || c == '\t');
}

void	is_map_last(t_info *info)
{
	int	i;

	i = 0;
	if (!(info->north_texture) || !(info->south_texture) \
			|| !(info->west_texture) || !(info->east_texture))
		ft_error("the map content always has to be the last!!!!!!!!!!!!!");
	while (i < 3)
	{
		if (info->ceiling_color[i] == -999 || info->floor_color[i] == -999)
		{
			printf("array is not initialized\n");
			ft_error("the map content always has to be the last");
		}
		i++;
	}
}

void	is_valid_element_color(t_info *info)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (info->ceiling_color[i] < 0 || info->ceiling_color[i] > 255
			|| info->floor_color[i] < 0 || info->floor_color[i] > 255)
			ft_error("R,G,B colors in range [0,255]");
		i++;
	}
}

int	is_wall(char c)
{
	return (c == '1');
}

void	is_valid_texture_color(t_info *info)
{
	int	i;

	i = 0;
	if(!(info->north_texture) || !(info->south_texture) || !(info->west_texture) || !(info->east_texture))
		ft_error("no texture info");
	while(i < 3)
	{
		if(info->ceiling_color[i] == -999 || info->floor_color[i] == -999)
			ft_error("no color info");
		i++;
	}
}
