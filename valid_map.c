/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jm <jm@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 10:30:14 by jm                #+#    #+#             */
/*   Updated: 2022/07/25 11:50:14 by jm               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	valid_player(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i <= data->map.height - 1)
	{
		j = -1;
		while (++j < (int)ft_strlen(data->map.map[i]))
		{
			if (data->map.map[i][j] == 'P')
			{
				data->player.x = j;
				data->player.y = i;
				data->player.count += 1;
			}
		}
	}
}

void	valid_money(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i <= data->map.height - 1)
	{
		j = -1;
		while (++j < (int)ft_strlen(data->map.map[i]))
		{
			if (data->map.map[i][j] == 'C')
				data->max_money_count += 1;
		}
	}
}

int	content_map(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i <= data->map.height - 1)
	{
		j = -1;
		if (data->map.map[i][0] != '1')
			return (1);
		if (data->map.map[i][data->map.width - 2] != '1')
			return (1);
		while (++j <= data->map.width - 2)
		{
			if (data->map.map[i][j] != '1' &&
				data->map.map[i][j] != '0' &&
				data->map.map[i][j] != 'C' &&
				data->map.map[i][j] != 'E' &&
				data->map.map[i][j] != 'P')
				return (1);
		}
	}
	return (0);
}

void	valid_map(t_data *data)
{
	valid_player(data);
	valid_money(data);
	valid_exit(data);
	if (content_map(data) != 0)
		send_error(data, "The map is incorrect.");
	if (first_last(data) != 0)
		send_error(data, "The map is incorrect.");
	if (data->player.count > 1)
		send_error(data, "To many player.");
	if (data->player.count < 1)
		send_error(data, "Not enough player.");
	if (data->max_money_count < 1)
		send_error(data, "Not enough item.");
	if (data->map.exit > 1)
		send_error(data, "To many exit.");
	if (data->map.exit < 1)
		send_error(data, "Not enough exit.");
}
