/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jm <jm@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:22:51 by jcoelho-          #+#    #+#             */
/*   Updated: 2022/07/21 17:35:14 by jm               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_texture(t_data *data)
{
	int	img_res;

	img_res = IMG_RES;
	data->floor.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr,
			"./xpm_file/floor.xpm", &img_res, &img_res);
	data->wall.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr,
			"./xpm_file/wall.xpm", &img_res, &img_res);
	data->money.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr,
			"./xpm_file/money.xpm", &img_res, &img_res);
	data->player.sprite.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr,
			"./xpm_file/jpeg.xpm", &img_res, &img_res);
	data->exitc.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr,
			"./xpm_file/exitc.xpm", &img_res, &img_res);
	data->exito.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr,
			"./xpm_file/exito.xpm", &img_res, &img_res);
}
