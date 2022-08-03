/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoelho- <jcoelho-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:52:38 by jcoelho-          #+#    #+#             */
/*   Updated: 2022/07/13 16:40:00 by jcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ma_list(va_list list, char c)
{
	int	ret;

	ret = 0;
	if (c == 's')
		ret += ft_putstr_len(va_arg(list, char *));
	else if (c == 'c')
		ret += ft_putchar_len(va_arg(list, int));
	else if (c == 'd' || c == 'i')
		ret += ft_putnbr_len(va_arg(list, int));
	else if (c == 'u')
		ret += ft_putnbr_u_len(va_arg(list, int));
	else if (c == 'x')
		ret += ft_hex(va_arg(list, unsigned int));
	else if (c == 'X')
		ret += ft_uphex(va_arg(list, unsigned int));
	else if (c == 'p')
		ret += ft_printptr(va_arg(list, unsigned long));
	else if (c == '%')
		ret += ft_putchar_len('%');
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	va_list			list;
	unsigned int	nbr;
	int				i;

	i = 0;
	va_start(list, format);
	nbr = 0;
	while (format[i])
	{
		if (format[i] == '%')
			nbr += ma_list(list, format[++i]);
		else
			nbr += ft_putchar_len(format[i]);
		i++;
	}
	va_end(list);
	return (nbr);
}

/*
** 
** int	main(void)
** {
** 	char	*str;
** 	char	c;
** 	int		d;
** 	int		i;
** 	int		u;
** 	int		x;
** 	int		X;
** 	int		*p;
** 	char 	*n1;
** 	int 	retour1;
** 	int		retour2;
** 	str = "salut";
** 	c = 'A';
** 	d = '4';
** 	i = 16;
** 	u = 32;
** 	x = 64;
** 	X = 128;
** 	p = &i;
** 	retour1 = 0;
** 	retour2 = 0;
** 	n1 = NULL;
** 	retour2 = printf("%s, %c, %d, %i, %u, %x, %X, %p, %s, %p \n",
** 		str, c, d, i, u, x, X, p, n1, n1);
** 	retour1 = ft_printf("%s, %c, %d, %i, %u, %x, %X, %p, %s, %p \n",
** 		str, c, d, i, u, x, X, p, n1, n1);
** 	printf("\nPrintf : %d \nFt_Printf : %d", retour2, retour1);
** 	return (0);
** }
** 
*/
