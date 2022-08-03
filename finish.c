/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jm <jm@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:20:36 by jcoelho-          #+#    #+#             */
/*   Updated: 2022/07/22 14:26:57 by jm               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	finish(t_data *data)
{
	int	i;

	i = -1;
	ft_printf("WINNER !!!\n");
	if (data != NULL)
	{
		if (data->map.map != NULL)
		{
			while (++i < data->map.height)
			{
				if (data->map.map[i] != NULL)
					free(data->map.map[i]);
			}
			free(data->map.map);
		}
	}
	exit(1);
}
