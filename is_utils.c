/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <hejang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 13:47:01 by yukim             #+#    #+#             */
/*   Updated: 2022/09/24 20:49:02 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"

int	is_space(char c) // space character only whitespace? or need check more space character? 
{
	// c == ' ' || (c >= 9 && c <= 13)
	return (c == '\t' || c == ' ');
}

void	is_map_last(t_info *info)
{
	int	i;

	i = 0;
	if(!(info->north_texture) || !(info->south_texture) || !(info->west_texture) || !(info->east_texture))
		ft_error("the map content always has to be the last!!!!!!!!!!!!!");
	while(i < 3)
	{
		if(info->ceiling_color[i] == -999 || info->floor_color[i] == -999)
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
	while(i < 3)
	{
		if(info->ceiling_color[i] < 0 || info->ceiling_color[i] > 255
			|| info->floor_color[i] < 0 || info->floor_color[i] > 255)
			ft_error("R,G,B colors in range [0,255]"); 
		i++;
	}
}