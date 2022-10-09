/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <hejang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 13:48:40 by hejang            #+#    #+#             */
/*   Updated: 2022/09/30 14:03:43 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
// #include "./include/definecub3d.h"

void	save_dir_vector(t_game *game, char dir);

int	init_map(t_game *game, t_map *map, t_info *info)
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
				save_dir_vector(game, map->maps[y][x]);
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
//	is_valid_map(map);
}

void	save_dir_vector(t_game *game, char dir)
{
	if(dir == 'W')
	{
		game->ray.dir_x = -1;
		game->ray.dir_y = 0;
	}
	else if(dir == 'E')
	{
		game->ray.dir_x = 1;
		game->ray.dir_y = 0;
	}
	else if(dir == 'N')
	{
		game->ray.dir_x = 0;
		game->ray.dir_y = -1;
	}
	else if(dir == 'S')
	{
		game->ray.dir_x = 0;
		game->ray.dir_y = 1;
	}
	game->ray.x_dir_x = game->ray.dir_y;
	game->ray.x_dir_y = -(game->ray.dir_x);
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

