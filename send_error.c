/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jm <jm@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:03:28 by jm                #+#    #+#             */
/*   Updated: 2022/07/22 14:27:09 by jm               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	send_error(t_data *data, char *message)
{	
	int	i;

	i = -1;
	ft_printf("ERROR: %s \n", message);
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
		free(data);
	}
	exit(1);
}
