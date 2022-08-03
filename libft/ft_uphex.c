/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uphex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoelho- <jcoelho-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 11:25:26 by jcoelho-          #+#    #+#             */
/*   Updated: 2021/12/10 13:45:27 by jcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_uphex(unsigned long nb)
{
	char	*base;
	int		len;

	len = 0;
	base = "0123456789ABCDEF";
	if (nb >= 16)
	{
		len += ft_uphex(nb / 16);
		len += ft_uphex(nb % 16);
	}
	else
	{
		len += ft_putchar_len(base[nb]);
	}
	return (len);
}
