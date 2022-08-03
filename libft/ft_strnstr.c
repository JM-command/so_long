/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoelho- <jcoelho-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 21:18:06 by jcoelho-          #+#    #+#             */
/*   Updated: 2021/11/10 07:46:07 by jcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (haystack[i] != 0 && i < len)
	{
		if (len >= i + ft_strlen(needle))
			if (ft_strncmp(haystack + i, needle, ft_strlen(needle)) == 0)
				return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
