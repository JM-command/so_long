/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoelho- <jcoelho-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 21:18:25 by jcoelho-          #+#    #+#             */
/*   Updated: 2021/11/05 10:47:44 by jcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	c;
	size_t	p;

	if (dstsize <= ft_strlen(dst))
		return (dstsize + ft_strlen(src));
	c = ft_strlen(dst);
	p = 0;
	while (src[p] != '\0' && c + 1 < dstsize)
	{
		dst[c] = src[p];
		c++;
		p++;
	}
	dst[c] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[p]));
}
