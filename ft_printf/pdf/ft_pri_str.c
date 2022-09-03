/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pri_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoda <kyoda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 04:39:11 by kyoda             #+#    #+#             */
/*   Updated: 2022/09/03 09:22:36 by kyoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int	ft_itoarray(unsigned long n, unsigned long base, int flagx)
{
	int	len;

	len = 0;
	if (n == 0)
		len += ft_putchar('0');
	while (n)
	{
		if (flagx == 0)
			len += ft_putchar(n % base + '0');
		else if (n % base < 10)
			len += ft_putchar(n % base + '0');
		else if (flagx == 2)
			len += ft_putchar(n % base + '7');
		else
			len += ft_putchar(n % base + 'W');
		n /= base;
	}
	return (len);
}

int	ft_itoa_u_int(long n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len += ft_putchar('-');
		n *= -1;
	}
	len += ft_itoarray(n, 10, 0);
	return (len);
}

int	ft_itoa_six_base(unsigned int n, int flagx)
{
	int	len;

	len = ft_itoarray(n, 16, flagx);
	return (len);
}

int	ft_putptr(va_list ap)
{
	unsigned long	n;
	int				len;

	len = 0;
	n = (unsigned long)va_arg(ap, void *);
	len += ft_putchar('0');
		len += ft_putchar('x');
		len += ft_itoarray(n, 16, 1);
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

int main(void)
{
	ft_printf("%d",10);
	return (0);
}