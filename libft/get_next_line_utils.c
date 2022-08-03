/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoelho- <jcoelho-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 10:28:19 by jcoelho-          #+#    #+#             */
/*   Updated: 2022/07/14 11:11:48 by jcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	find_n(char *str)
{
	size_t	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i] != '\0')
// 		i++;
// 	return (i);
// }

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	int		i;
// 	int		j;
// 	char	*join;

// 	join = malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char) + 1);
// 	if (!join)
// 		return (NULL);
// 	i = 0;
// 	j = 0;
// 	while (s1[i])
// 	{
// 		join[i] = s1[i];
// 		i++;
// 	}
// 	while (s2[j])
// 	{
// 		join[i] = s2[j];
// 		i++;
// 		j++;
// 	}
// 	join[i] = '\0';
// 	return (join);
// }

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	size_t	i;
// 	char	*sub;

// 	i = 0;
// 	if ((ft_strlen(s) - start) < len)
// 		len = ft_strlen(s) - start;
// 	if (start > ft_strlen(s))
// 		start = ft_strlen(s);
// 	while (s[start + i] && i < len)
// 		i++;
// 	sub = malloc(i * sizeof(char) + 1);
// 	if (!sub)
// 		return (NULL);
// 	i = 0;
// 	while (i < len && start < ft_strlen(s) && s[i])
// 	{
// 		sub[i] = s[start + i];
// 		i++;
// 	}
// 	sub[i] = '\0';
// 	return (sub);
// }
