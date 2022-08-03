/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jm <jm@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:23:35 by jcoelho-          #+#    #+#             */
/*   Updated: 2022/07/22 14:54:29 by jm               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_wall(t_data *data, int i, int j)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->wall.mlx_img, j * IMG_RES, i * IMG_RES);
}

void	render_player(t_data *data, int i, int j)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->floor.mlx_img, j * IMG_RES, i * IMG_RES);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->player.sprite.mlx_img, j * IMG_RES, i * IMG_RES);
}

void	render_money(t_data *data, int i, int j)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->floor.mlx_img, j * IMG_RES, i * IMG_RES);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->money.mlx_img, j * IMG_RES, i * IMG_RES);
}

void	render_floor(t_data *data, int i, int j)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->floor.mlx_img, j * IMG_RES, i * IMG_RES);
}

void	render(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i <= data->map.height - 1)
	{
		j = -1;
		while (++j < (int)ft_strlen(data->map.map[i]))
		{
			if (data->map.map[i][j] == '1')
				render_wall(data, i, j);
			if (data->map.map[i][j] == 'P')
				render_player(data, i, j);
			if (data->map.map[i][j] == '0')
				render_floor(data, i, j);
			if (data->map.map[i][j] == 'C')
				render_money(data, i, j);
			if (data->map.map[i][j] == 'E' &&
				data->money_count == data->max_money_count)
				render_exito(data, i, j);
			else if (data->map.map[i][j] == 'E')
				render_exitc(data, i, j);
		}
	}
}
