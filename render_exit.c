/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jm <jm@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:23:35 by jcoelho-          #+#    #+#             */
/*   Updated: 2022/07/21 10:46:58 by jm               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_exito(t_data *data, int i, int j)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->floor.mlx_img, j * IMG_RES, i * IMG_RES);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->exito.mlx_img, j * IMG_RES, i * IMG_RES);
}

void	render_exitc(t_data *data, int i, int j)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->floor.mlx_img, j * IMG_RES, i * IMG_RES);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->exitc.mlx_img, j * IMG_RES, i * IMG_RES);
}
