/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoelho- <jcoelho-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 10:49:00 by jcoelho-          #+#    #+#             */
/*   Updated: 2022/08/03 15:57:58 by jcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*next_line(char **save, char *buffer)
{
	char	*line;
	char	*in_line;

	if (!*save)
	{
		*save = ft_substr(buffer, find_n(buffer) + 1,
				BUFFER_SIZE - find_n(buffer));
		line = ft_substr(buffer, 0, find_n(buffer) + 1);
	}
	else
	{
		in_line = ft_substr(buffer, 0, find_n(buffer) + 1);
		line = ft_strjoin(*save, in_line);
		free(*save);
		*save = ft_substr(buffer, find_n(buffer) + 1,
				BUFFER_SIZE - find_n(buffer));
		free(in_line);
	}
	return (line);
}

void	ft_save(char **save, char *buffer)
{
	char	*tmp;

	if (*save)
	{	
		tmp = ft_strjoin(*save, buffer);
		free(*save);
		*save = tmp;
	}
	else
		*save = ft_substr(buffer, 0, BUFFER_SIZE);
}

char	*find_n_save(char **save, int end)
{
	char	*line;
	char	*tmp;

	if (end == -1)
	{
		line = ft_substr(*save, 0, ft_strlen(*save));
		if (*save != NULL)
		{
			free(*save);
			*save = NULL;
		}
	}
	else
	{
		line = ft_substr(*save, 0, find_n(*save) + 1);
		tmp = ft_substr(*save, find_n(*save) + 1,
				BUFFER_SIZE - find_n(*save));
		free(*save);
		*save = tmp;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*save;
	int			nread;

	nread = 1;
	if (fd < 0 || BUFFER_SIZE == 0)
		return (NULL);
	while (nread != 0 && find_n(save) == -1)
	{
		nread = read(fd, buffer, BUFFER_SIZE);
		if (nread == -1)
			return (NULL);
		buffer[nread] = '\0';
		if (find_n(buffer) != -1)
			return (next_line(&save, buffer));
		else
			ft_save(&save, buffer);
	}
	if (find_n(save) != -1)
		return (find_n_save(&save, 0));
	if (ft_strlen(save) > 0)
		return (find_n_save(&save, -1));
	free(save);
	save = NULL;
	return (NULL);
}

// int	main(void)
// {
// 	int		i;
// 	int		fd;
// 	char	*abc;

// 	fd = open("gnlTester/files/41_with_nl", O_RDONLY);
// 	i = 0;
// 	while (i < 5)
// 	{
// 		abc = get_next_line(fd);
// 		printf("_%s_\n", abc);
// 		i++;
// 	}
// }
