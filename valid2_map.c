/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid2_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jm <jm@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:57:15 by jm                #+#    #+#             */
/*   Updated: 2022/07/22 14:54:02 by jm               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	valid_exit(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i <= data->map.height - 1)
	{
		j = -1;
		while (++j < (int)ft_strlen(data->map.map[i]))
		{
			if (data->map.map[i][j] == 'E')
				data->map.exit += 1;
		}
	}
}

int	first_last(t_data *data)
{
	int	j;

	j = 0;
	while (j < data->map.width - 1)
	{
		if (data->map.map[0][j] != '1')
			return (1);
		j++;
	}	
	j = 0;
	while (j < data->map.width - 1)
	{
		if (data->map.map[data->map.height - 1][j] != '1')
			return (1);
		j++;
	}
	return (0);
}
