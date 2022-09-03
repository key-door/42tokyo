/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoda <kyoda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 04:39:11 by kyoda             #+#    #+#             */
/*   Updated: 2022/09/03 07:31:31 by kyoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

char	*ft_itoarray(unsigned long n, char *str, unsigned long base, int flagx)
{
	int	i;

	i = 11;
	if (n == 0)
		str[--i] = '0';
	while (n)
	{
		if (flagx == 0)
			str[--i] = n % base + '0';
		else if (n % base < 10)
			str[--i] = n % base + '0';
		else
		{
			str[--i] = n % base + '7';
			if (flagx == 1)
				str[i] = ft_tolower(str[i]);
		}
		n /= base;
	}
	return (&str[i]);
}

int	ft_itoa_u_int(long n)
{
	char	*str;
	int		len;
	char	*tmp;

	str = ft_calloc(12, 1);
	if (str == NULL)
		return (-1);
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		n *= -1;
		len = 1;
	}
	else
		len = 0;
	tmp = ft_itoarray(n, str, 10, 0);
	ft_putstr_fd(tmp, 1);
	len += (int)ft_strlen(tmp);
	free(str);
	return (len);
}

int	ft_itoa_six_base(unsigned int n, int flagx)
{
	char	*str;
	char	*tmp;
	int		len;

	str = ft_calloc(12, 1);
	if (str == NULL)
		return (-1);
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		n *= -1;
		len = 1;
	}
	else
		len = 0;
	tmp = ft_itoarray(n, str, 16, flagx);
	ft_putstr_fd(tmp, 1);
	len += (int)ft_strlen(tmp);
	free(str);
	return (len);
}

int	ft_putptr(va_list ap)
{
	char			*str;
	char			*tmp;
	unsigned long	n;
	int				len;

	len = 0;
	n = (unsigned long)va_arg(ap, void *);
	str = ft_calloc(11, 1);
	if (str == NULL)
		return (-1);
	ft_putchar_fd('0', 1);
	ft_putchar_fd('x', 1);
	tmp = ft_itoarray(n, str, 16, 1);
	ft_putstr_fd(tmp, 1);
	len += (int)ft_strlen(tmp) + 2;
	free(str);
	return (len);
}

int	ft_str_print(va_list ap)
{
	char	*p;

	p = va_arg(ap, char *);
	if (p == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(p, 1);
	return (ft_strlen(p));
}
