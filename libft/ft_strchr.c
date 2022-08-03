/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoelho- <jcoelho-@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:31:05 by jcoelho-          #+#    #+#             */
/*   Updated: 2021/11/02 08:25:41 by jcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*s1;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
		{
			s1 = (char *)s;
			return (&s1[i]);
		}
		i++;
		if (s[i] == (unsigned char)c)
		{
			s1 = (char *)s;
			return (&s1[i]);
		}
	}
	return (NULL);
}
