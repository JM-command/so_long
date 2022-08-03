/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jm <jm@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:22:08 by jcoelho-          #+#    #+#             */
/*   Updated: 2022/07/22 13:54:54 by jm               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	deal_key(int key, void *param)
{
	t_data	*data;

	data = param;
	if (key == K_W || key == K_UP)
		move(data, data->player.x, data->player.y - 1);
	else if (key == K_S || key == K_DOWN)
		move(data, data->player.x, data->player.y + 1);
	else if (key == K_D || key == K_RIGHT)
		move(data, data->player.x + 1, data->player.y);
	else if (key == K_A || key == K_LEFT)
		move(data, data->player.x -1, data->player.y);
	else if (key == K_ESC)
	{
		send_error(data, "Game not finish.");
	}
	ft_printf("Money: %d/%d\n", data->money_count, data->max_money_count);
	ft_printf("Step: %d\n", data->player.step);
	return (1);
}
