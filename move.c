/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jm <jm@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:21:35 by jcoelho-          #+#    #+#             */
/*   Updated: 2022/07/22 13:50:03 by jm               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move(t_data *data, int new_x, int new_y)
{
	if (data->map.map[new_y][new_x] != '1')
	{
		if (data->map.map[new_y][new_x] == 'E' &&
				data->money_count == data->max_money_count)
		{
			finish(data);
		}
		if (data->map.map[new_y][new_x] == '0' ||
				data->map.map[new_y][new_x] == 'C')
		{
			data->map.map[data->player.y][data->player.x] = '0';
			data->player.y = new_y;
			data->player.x = new_x;
			data->player.step += 1;
			if (data->map.map[new_y][new_x] == 'C')
				data->money_count += 1;
			data->map.map[new_y][new_x] = 'P';
			render (data);
		}
		else
			ft_printf ("Exit not open!\n");
	}
	else
		ft_printf ("There is a wall bitch!\n");
}
