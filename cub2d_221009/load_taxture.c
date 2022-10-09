/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_taxture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukim <yukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:14:59 by yukim             #+#    #+#             */
/*   Updated: 2022/10/05 19:14:59 by yukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"

static int load_img_malloc(t_game *game, char *xpm_path, t_img *iimg, int i);

void	load_texture(t_game *game)
{
	int		i;
	t_img	iimg;

	game->tex[0].tex_data = load_img_malloc(game, game->info.north_texture, &iimg, 0);
	game->tex[1].tex_data = load_img_malloc(game, game->info.south_texture, &iimg, 1);
	game->tex[2].tex_data = load_img_malloc(game, game->info.west_texture, &iimg, 2);
	game->tex[3].tex_data = load_img_malloc(game, game->info.east_texture, &iimg, 3);
}

static int load_img_malloc(t_game *game, char *xpm_path, t_img *iimg, int i)
{
	int col_x;
	int row_y;
	int *tex_data;

	iimg->img_ptr = mlx_xpm_file_to_image(game->mlx.mlx, xpm_path, &(iimg->width), &(iimg->height));
	if (iimg->img_ptr == NULL)
		ft_error("Wrong Texture Image");
	
	game->tex[i].tex_xpm_width = iimg->width;
	game->tex[i].tex_xpm_height = iimg->height;

	iimg->data = (int *)mlx_get_data_addr(iimg->img_ptr, &(iimg->bpp), &(iimg->size_line), &(iimg->endian));
	tex_data = (int *)malloc(sizeof(int) * (iimg->width * iimg->height));

	row_y = 0;
	while (row_y < iimg->height)
	{
		col_x = 0;
		while (col_x < iimg->width)
		{
			tex_data[(row_y * iimg->width) + col_x] = iimg->data[(row_y * iimg->width) + col_x];
			col_x++;
		}
		row_y++;
	}

	mlx_destroy_image(game->mlx.mlx, iimg->img_ptr);
	return (tex_data);
}