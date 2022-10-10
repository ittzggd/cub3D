/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukim <yukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 01:26:09 by hejang            #+#    #+#             */
/*   Updated: 2022/10/10 16:27:51 by yukim            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"

int	main(int argc, char **argv)
{	
	int		fd;
	t_game	game;

	check_argument(argc, argv);
	fd = open(argv[1], O_RDWR);
	if (fd < 0)
		ft_error("open file failed");
	ft_bzero(&game, sizeof(t_game));
	init_info(fd, &(game.info));
	init_cub3d(&game);
	close(fd);
	mlx_hook(game.mlx.mlx_win, X_EVENT_KEY_PRESS, 0, &key_press, &game);
	mlx_hook(game.mlx.mlx_win, X_EVENT_EXIT, 0, &exit_game, &game);
	mlx_loop_hook(game.mlx.mlx, &main_loop_ray, &game);
	mlx_loop(game.mlx.mlx);
}

int	main_loop_ray(t_game *game)
{
	raycast(game);
	draw(game);
	return (0);
}
