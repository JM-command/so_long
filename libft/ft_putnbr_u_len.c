/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u_len.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoelho- <jcoelho-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:32:44 by jcoelho-          #+#    #+#             */
/*   Updated: 2021/12/10 13:43:33 by jcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_u_len(unsigned int nb)
{
	unsigned int	nbr;
	int				len;

	len = 0;
	nbr = (unsigned int)nb;
	if (nbr >= 10)
		len += ft_putnbr_len(nbr / 10);
	len += ft_putchar_len((char)(nbr % 10 + 48));
	return (len);
}
