/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jm <jm@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 10:31:00 by jm                #+#    #+#             */
/*   Updated: 2022/08/03 17:06:09 by jm               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	parse_map(t_data *data, char *path)
{
	int		fd;
	int		h;
	char	*buffer;

	data->map.map = (char **)ft_calloc(data->map.height, sizeof(char *));
	if (data->map.map == NULL)
		return (MLX_ERROR);
	h = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (MLX_ERROR);
	buffer = get_next_line(fd);
	while ((h < data->map.height + 1) && (buffer))
	{
		data->map.map[h] = buffer;
		if (ft_strchr(buffer, '\n') != NULL)
			data->map.map[h][ft_strlen(buffer) - 1] = '\0';
		buffer = get_next_line(fd);
		h++;
	}
	valid_map(data);
	close(fd);
	return (MLX_SSUCCESS);
}
