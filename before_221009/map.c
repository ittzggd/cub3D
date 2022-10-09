/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <hejang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 13:48:40 by hejang            #+#    #+#             */
/*   Updated: 2022/09/24 20:51:37 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"
#include "./include/definecub3d.h"

int	init_map(t_info *info, t_map *map)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	i = 0;
	map->max_height = info->height;
	map->max_width = info->width;
	map->maps = (char **)malloc(sizeof(char *) * (map->max_height + 1));
	if(!map->maps)
		return (ERROR);
	while (y < map->max_height)
	{
		x = 0;
		map->maps[y] = (char *)malloc(sizeof(char) * (map->max_width + 1));
		if(!(map->maps[y]))
			return (ERROR);
		while (x < map->max_width  && (*(info->backup) != '\n' && *(info->backup) != '\0'))
		{
			map->maps[y][x] = *(info->backup);
			if(map->maps[y][x] == 'W' || map->maps[y][x] == 'E' || map->maps[y][x] == 'N'
				|| map->maps[y][x] == 'S')
			{
				map->sp_x = x;
				map->sp_y = y;
			}
			(info->backup)++;
			x++;
		}
		while(x < map->max_width)
		{
			map->maps[y][x] = ' ';
			x++;
		}
		(info->backup)++;
		map->maps[y][x] = '\0';
		y++;
	}
	map->maps[y] = NULL;
}


int	check_map_element(char *line)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while(line[i] != '\0')
	{
		if(line[i] != '0' && line[i] != '1' && line[i] != 'N' && line[i] != '\n'
			&& line[i] != 'S' && line[i] != 'E' && line[i] != 'W' && line[i] != ' ')
				ft_error("The map must be composed of only 6 possible characters");
		if(line[i] == 'N' || line[i] == 'S' || line[i] == 'E' || line[i] == 'W')
			cnt++;
		i++;
	}
	return (cnt);
}

