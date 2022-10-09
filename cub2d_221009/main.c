/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <hejang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 01:26:09 by hejang            #+#    #+#             */
/*   Updated: 2022/09/30 14:03:40 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"
#include "./include/definecub3d.h"

void print_data(t_game *game);
void	check_argument(int argc, char **argv);

void	init_struct(t_game *game, t_info *info, t_map *map, t_img *img, t_mlx *mlx);

int main(int argc, char **argv)
{	
	int	fd;
	t_game	game;
	t_info	info;
	t_map	map;
	t_img	img;
	t_mlx	mlx;

	check_argument(argc, argv);
	fd = open(argv[1], O_RDWR);
	if (fd < 0)
		ft_error("open file failed");
	init_info(fd, &info);
	init_map(&game, &map, &info);
	init_struct(&game, &info, &map, &img, &mlx);
//	print_data(&data);
	load_window(&game);
	load_texture(game);

	mlx_hook(game.window.win, X_EVENT_KEY_PRESS, 0, &key_press, &game); // Flag ON
	// mlx_hook(game.window.win, X_EVENT_KEY_RELEASE, 0, &key_release, &game); // Flag OFF
	mlx_hook(game.window.win, X_EVENT_EXIT, 0, &exit_game, &game); // Exit (free and Exit)
	mlx_loop_hook(mmlx->mlx, &main_loop_ray, game);
	mlx_loop(mmlx->mlx);	
}

void	init_struct(t_game *game, t_info *info, t_map *map, t_img *img, t_mlx *mlx)
{
	game->img = img;
	game->info = info;
	game->map = map;
	game->mlx = mlx;
	game->mlx->window_height = map->max_height;
	game->mlx->window_width = map->max_width;
}

// void print_data(t_game *game)
// {
// 	t_info *info;
// 	t_map *map;

// 	info = game->info;
// 	map = game->map;
// 	printf("N : %s\n", info->north_texture);
// 	printf("S : %s\n", info->north_texture);
// 	printf("W : %s\n", info->north_texture);
// 	printf("E : %s\n", info->north_texture);
// 	printf("floor_color %d, %d, %d\n", info->floor_color[0], info->floor_color[1], info->floor_color[2]);
// 	printf("ceiling_color %d, %d, %d\n", info->ceiling_color[0], info->ceiling_color[1], info->ceiling_color[2]);
// 	for(int i = 0; i < info->height; i++)
// 	{
// 		printf("%s\n", map->maps[i]);
// 	}
// }


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

