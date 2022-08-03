/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoelho- <jcoelho-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 11:32:18 by jcoelho-          #+#    #+#             */
/*   Updated: 2021/12/10 13:46:06 by jcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printptr(unsigned long p)
{
	int		len;

	len = 0;
	if (!p)
		len += ft_putstr_len("0x0");
	else
	{
		len += ft_putstr_len("0x");
		len += ft_hex(p);
	}
	return (len);
}
