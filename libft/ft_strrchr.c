/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoelho- <jcoelho-@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 21:18:01 by jcoelho-          #+#    #+#             */
/*   Updated: 2021/11/02 10:40:39 by jcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*s1;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (unsigned char)c)
		{
			s1 = (char *)s;
			return (&s1[i]);
		}
		i--;
		if (s[i] == (unsigned char)c)
		{
			s1 = (char *)s;
			return (&s1[i]);
		}
	}
	return (NULL);
}
