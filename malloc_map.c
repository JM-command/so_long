/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jm <jm@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:56:53 by jcoelho-          #+#    #+#             */
/*   Updated: 2022/08/03 17:04:14 by jm               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	malloc_map(t_data *data, char *path)
{
	int		fd;
	char	*buffer;

	data->map.height = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0 || read(fd, NULL, 0) == -1)
		send_error(data, "Argument not map (please use <example>.ber).");
	buffer = get_next_line(fd);
	if (buffer == NULL)
		send_error(data, "Map empty.");
	data->map.width = ft_strlen(buffer);
	while (buffer)
	{
		if (data->map.width != (int)ft_strlen(buffer)
			&& ft_strchr(buffer, '\n') != NULL)
			send_error(data, "\\n missing in last line map.");
		if (data->map.width - 1 != (int)ft_strlen(buffer)
			&& ft_strchr(buffer, '\n') == NULL)
			send_error(data, "The map not rectangular.");
		free(buffer);
		buffer = get_next_line(fd);
		data->map.height += 1;
	}
	close(fd);
	return (parse_map(data, path));
}
