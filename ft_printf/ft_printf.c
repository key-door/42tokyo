/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoda <kyoda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 12:20:52 by kyoda             #+#    #+#             */
/*   Updated: 2022/09/03 03:17:04 by kyoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int	ft_itoa_u_int(long n)
{
	char	*str;
	int		i;
	int		len;
	int		flag;

	flag = 0;
	if (n == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	if (n < 0)
	{
		flag = 1;
		n *= -1;
	}
	i = 11;
	if ((str = ft_calloc(12, 1)) == NULL)
		return (-1);
	while (n)
	{
		str[--i] = n % 10 + '0';
		n /= 10;
	}
	if (flag == 1)
		str[--i] = '-';
	ft_putstr_fd(&str[i], 1);
	len = (int)ft_strlen(&str[i]);
	free(str);
	return (len);
}

int	ft_itoa_six_base(unsigned int n, int flag)
{
	char	*str;
	int		i;
	int		len;

	i = 10;
	if (n == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	if ((str = ft_calloc(11, 1)) == NULL)
		return (-1);
	while (n)
	{
		if (n % 16 < 10)
			str[--i] = n % 16 + '0';
		else
		{
			str[--i] = n % 16 + '7';
			if (flag == 0)
				str[i] = ft_tolower(str[i]);
		}
		n /= 16;
	}
	ft_putstr_fd(&str[i], 1);
	len = (int)ft_strlen(&str[i]);
	free(str);
	return (len);
}

int	ft_putptr(va_list ap)
{
	char				*str;
	unsigned long int	n;
	int					i;
	int					len;

	n = (unsigned long int)va_arg(ap, void *);
	i = 10;
	if ((str = ft_calloc(11, 1)) == NULL)
		return (-1);
	if (n != 0)
	{
		while (n)
		{
			if (n % 16 < 10)
				str[--i] = n % 16 + '0';
			else
				str[--i] = ft_tolower(n % 16 + '7');
			n /= 16;
		}
	}
	else
		str[--i] = '0';
	str[--i] = 'x';
	str[--i] = '0';
	ft_putstr_fd(&str[i], 1);
	len = (int)ft_strlen(&str[i]);
	free(str);
	return (len);
}

static int	selection_percent(va_list ap, const char *format)
{
	char	*p;
	int		len;

	len = 1;
	if (*format == 'c')
		ft_putchar_fd((char)va_arg(ap, int), 1);
	else if (*format == 's')
	{
		p = va_arg(ap, char *);
		if (p == NULL)
		{
			ft_putstr_fd("(null)", 1);
			return 6;
		}
		ft_putstr_fd(p, 1);
		return (ft_strlen(p));
	}
	else if (*format == 'p')
		return (ft_putptr(ap));
	else if (*format == 'd')
		return (ft_itoa_u_int(va_arg(ap, int)));
	else if (*format == 'i')
		return (ft_itoa_u_int(va_arg(ap, int)));
	else if (*format == 'u')
		return (ft_itoa_u_int(va_arg(ap, unsigned int)));
	else if (*format == 'x')
		return (ft_itoa_six_base(va_arg(ap, unsigned int), 0));
	else if (*format == 'X')
		return (ft_itoa_six_base(va_arg(ap, unsigned int), 1));
	else if (*format == '%')
		ft_putchar_fd('%', 1);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		re_ans;
	int		check;
	va_list	ap;

	re_ans = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			check = selection_percent(ap, ++format);
			if (check == -1)
				return (0);
			else
				re_ans += check;
			format++;
		}
		else
		{
			while (*format != '%' && *format)
			{
				ft_putchar_fd(*format, 1);
				format++;
				re_ans += 1;
			}
		}
	}
	va_end(ap);
	return (re_ans);
}

// int	main(void)
// {
// 	ft_printf(" NULL %s NULL ", NULL);
// 	ft_printf("\n");
// 	printf(" NULL %s NULL ", NULL);
// 	return (0);
// }