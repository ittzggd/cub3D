/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <hejang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 01:26:09 by hejang            #+#    #+#             */
/*   Updated: 2022/09/24 20:31:06 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"
#include "./include/definecub3d.h"

void print_data(t_info *info, t_map *map);
void	check_argument(int argc, char **argv);

int main(int argc, char **argv)
{	
	int	fd;
	t_info	info;
	t_map	map;

	check_argument(argc, argv);
	fd = open(argv[1], O_RDWR);
	if (fd < 0)
		ft_error("open file failed");
	init_info(fd, &info);
	init_map(&info, &map);
	print_data(&info, &map);
}

void print_data(t_info *info, t_map *map)
{
	printf("N : %s\n", info->north_texture);
	printf("S : %s\n", info->north_texture);
	printf("W : %s\n", info->north_texture);
	printf("E : %s\n", info->north_texture);
	printf("floor_color %d, %d, %d\n", info->floor_color[0], info->floor_color[1], info->floor_color[2]);
	printf("ceiling_color %d, %d, %d\n", info->ceiling_color[0], info->ceiling_color[1], info->ceiling_color[2]);
	for(int i = 0; i < info->height; i++)
	{
		printf("%s\n", map->maps[i]);
	}
}


void	check_argument(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("./cub3D [mapfile.map]");
		exit(1);
	}
	if (ft_filecmp(argv[1]) == FALSE)
	{
		printf("the argument needs to be a map in format *.cub");
		exit(1);
	}
}

