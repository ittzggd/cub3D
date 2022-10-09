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

int	main(int argc, char **argv)
{	
	int		fd;
	t_game	game;

	check_argument(argc, argv);
	fd = open(argv[1], O_RDWR);
	if (fd < 0)
		ft_error("open file failed");
	ft_bzero(&game, sizeof(t_game));
	init_info(fd, &info);
	init_cub3d(&game);
	close(fd);
//	print_data(&data);
	mlx_hook(game.window.win, X_EVENT_KEY_PRESS, 0, &key_press, &game);
	mlx_hook(game.window.win, X_EVENT_EXIT, 0, &exit_game, &game);
	mlx_loop_hook(mmlx->mlx, &main_loop_ray, game);
	mlx_loop(mmlx->mlx);	
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

int	main_loop_ray(t_game *game)
{
	int		is_update;

	is_update = key_action(game);
	if (is_update == TRUE)
	{
		raycast(game);
		draw(game)
	}
	return (0);
}

