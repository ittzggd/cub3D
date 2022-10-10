/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <hejang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 13:48:40 by hejang            #+#    #+#             */
/*   Updated: 2022/10/10 00:50:19 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	init_map_init_var(int *y, int *i, t_map *map, t_info *info);
static void	save_mapx_and_startpos(t_game *game, t_map *map, t_info *info, int y);
static void	fill_space(int *x, int y, t_map *map);

int	check_map_element(char *line)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != '\n' \
			&& line[i] != 'N' && line[i] != 'S' \
			&& line[i] != 'E' && line[i] != 'W' && line[i] != ' ')
		{
			ft_error("The map must be composed of \"0,1,N,S,E,W\".");
		}
		if (line[i] == 'N' || line[i] == 'S' \
			|| line[i] == 'E' || line[i] == 'W')
			cnt++;
		i++;
	}
	return (cnt);
}

int	init_map(t_game *game, t_map *map, t_info *info)
{
	int	x;
	int	y;
	int	i;

	init_map_init_var(&y, &i, map, info);
	while (y < map->max_height)
	{
		map->maps[y] = (char *)malloc(sizeof(char) * (map->max_width + 1));
		if(!(map->maps[y]))
			ft_error("[ERROR 2] init map malloc failed.");
		save_mapx_and_startpos(game, map, info, y);
		fill_space(&x, y, map);
		(info->backup)++;
		y++;
	}
	map->maps[y] = NULL;
}

static void	save_mapx_and_startpos(t_game *game, t_map *map, t_info *info, int y)
{
	int	x;

	x = 0;
	while (x < map->max_width \
				&& (*(info->backup) != '\n' && *(info->backup) != '\0'))
	{
		map->maps[y][x] = *(info->backup);
		if (map->maps[y][x] == 'W' || map->maps[y][x] == 'E' \
			|| map->maps[y][x] == 'N' || map->maps[y][x] == 'S')
		{
			map->sp_x = x;
			map->sp_y = y;
			save_dir_vector(game, map->maps[y][x]);
		}
		(info->backup)++;
		x++;
	}
}

static void		init_map_init_var(int *y, int *i, t_map *map, t_info *info)
{
	*y = 0;
	*i = 0;
	map->max_height = info->height;
	map->max_width = info->width;
	map->maps = (char **)malloc(sizeof(char *) * (map->max_height + 1));
	if (map->maps == NULL)
		ft_error("[ERROR 1] init map malloc failed.");
}

static void		fill_space(int *x, int y, t_map *map)
{
	while(*x < map->max_width)
	{
		map->maps[y][*x] = ' ';
		(*x)++;
	}
	map->maps[y][*x] = '\0';
}
