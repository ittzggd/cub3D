/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <hejang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 15:48:41 by yukim             #+#    #+#             */
/*   Updated: 2022/10/10 13:54:00 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	surrounded_wall(char **map, int y, int x);
static int	first_last_line(char *row, char **map, int y);
static int	check_first_and_last_char(char **maps, int y);
static int	save_end_x(int *end_x, char **maps, int y, int *i);

int	is_valid_map(t_map *map)
{
	char	**maps;
	int		x;
	int		y;

	x = 0;
	y = 0;
	maps = map->maps;
	while (y < map->max_height)
	{
		if (y == 0 || y == (map->max_height - 1))
		{
			if (first_last_line(maps[y], maps, y) == ERROR)
				return (ERROR);
		}
		else 
		{
			if (check_first_and_last_char(maps, y) == ERROR)
				return (ERROR);
		}
		y++;
	}
	return (TRUE);
}

static int	check_first_and_last_char(char **maps, int y)
{
	int		end_x;
	int		i;

	i = 0;
	ft_skip(maps[y], &i);
	if (is_wall(maps[y][i]) == FALSE)
		return (ERROR);
	else
		save_end_x(&end_x, maps, y, &i);
	while (maps[y][i])
	{
		if (is_space(maps[y][i] == TRUE))
		{
			if (surrounded_wall(maps, y, i) == ERROR)
				return (ERROR);
			i++;
		}
		else
			save_end_x(&end_x, maps, y, &i);
	}
	if (end_x != '1')
		return (ERROR);
	return (TRUE);
}

static int	save_end_x(int *end_x, char **maps, int y, int *i)
{
	*end_x = maps[y][*i];
	(*i)++;
	return (0);
}

static int	first_last_line(char *row, char **map, int y)
{
	int	i;

	i = 0;
	while (row[i])
	{
		if ((is_wall(row[i]) != TRUE) && (is_space(row[i]) != TRUE))
			return (ERROR);
		if (is_space(row[i]) == TRUE)
		{
			if (y == 0 \
				&& (is_wall(map[y + 1][i]) == FALSE || is_space(map[y + 1][i])\
				== FALSE))
				return (ERROR);
			if (y != 0 \
				&& (is_wall(map[y - 1][i]) == FALSE || is_space(map[y - 1][i])\
				== FALSE))
				return (ERROR);
		}
		i++;
	}
	return(TRUE);
}

static int	surrounded_wall(char **map, int y, int x)
{
	if (is_wall(map[y][x - 1]) != TRUE && is_space(map[y][x - 1]) != TRUE)
		return (ERROR);
	if (is_wall(map[y][x + 1]) != TRUE && is_space(map[y][x + 1]) != TRUE)
		return (ERROR);
	if (is_wall(map[y - 1][x]) != TRUE && is_space(map[y - 1][x]) != TRUE)
		return (ERROR);
	if (is_wall(map[y + 1][x]) != TRUE && is_space(map[y + 1][x]) != TRUE)
		return (ERROR);
	return (TRUE);
}