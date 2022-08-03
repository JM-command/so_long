/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoelho- <jcoelho-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 14:01:49 by jcoelho-          #+#    #+#             */
/*   Updated: 2021/11/05 14:49:54 by jcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_n(int n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*new_str(char *str, long nb, long leng, long j)
{
	str[leng] = '\0';
	while (leng > 0)
	{
		str[--leng] = nb % 10 + '0';
		nb = nb / 10;
	}
	if (j < 0)
		str[leng++] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	leng;
	long	nb;
	long	j;

	nb = n;
	j = 1;
	leng = (long)len_n(nb);
	if (nb == 0)
		return (ft_strdup("0"));
	if (nb == -2147483648)
		return (ft_strdup("-2147483648"));
	if (nb < 0)
	{
		nb = -nb;
		j = -j;
	}
	str = (char *)malloc(sizeof(char) * (leng + 1));
	if (!str)
		return (NULL);
	str = new_str(str, nb, leng, j);
	return (str);
}
