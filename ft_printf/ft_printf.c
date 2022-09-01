/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoda <kyoda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 12:20:52 by kyoda             #+#    #+#             */
/*   Updated: 2022/09/01 16:42:58 by kyoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

void	ft_sixteen_base(unsigned int n, int flag)
{
	char	*str;
	int		i;
	char	*p;

	i = 10;
	if ((str = ft_calloc(11, 1)) == NULL)
		return ;
	while (n)
	{
		if (n % 16 < 10)
			str[--i] = n % 16 + '0x30';
		else
			str[--i] = n % 16 + '0x37';
		n /= 16;
	}
	ft_putstr_fd(&str[i], 1);
	free(str);
}

void	ft_uitoa(unsigned int n)
{
	char	*str;
	int		i;
	char	*p;

	i = 10;
	if ((str = ft_calloc(11, 1)) == NULL)
		return ;
	while (n)
	{
		str[--i] = n % 10 + '0';
		n /= 10;
	}
	ft_putstr_fd(&str[i], 1);
	free(str);
}

static void	selection_percent(va_list ap, const char *format, int *re_ans)
{
	if (*format == 'c')
		ft_putchar_fd((char)va_arg(ap, int), 1);
	else if (*format == 's')
		ft_putstr_fd(va_arg(ap, char *), 1);
	else if (*format == 'p')
		return ;
	else if (*format == 'd' || *format == 'i')
		ft_putnbr_fd(va_arg(ap, int), 1);
	else if (*format == 'u')
		ft_uitoa(va_arg(ap, unsigned int));
	else if (*format == 'x')
		ft_sixteen_base(va_arg(ap, unsigned int), 0);
	else if (*format == 'X')
		ft_sixteen_base(va_arg(ap, unsigned int), 1);
	else if (*format == '%')
		return ;
}

static int	selection_reverse_solidus(void)
{
	return (1);
}

int	ft_printf(const char *format, ...)
{
	int		*re_ans;
	va_list	ap;
	va_list	argc;
	char	*day;

	*re_ans = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			selection_percent(ap, ++format, re_ans);
			format++;
		}
		else
		{
			while (*format != '%' && *format)
			{
				ft_putchar_fd(*format, 1);
				format++;
			}
		}
	}
	va_end(ap);
	return (*re_ans);
}

int	main(void)
{
	ft_printf("c = (%c)\ns = (%s)\nd = (%d)\ni = (%i)\nu = (%u)\nx = (%x)\n",
				'1',
				"1234",
				1234567,
				-1234,
				4294967295,
				256);
	// ft_printf("s\n%c\nd\n%s\njafs", '1','12345');s
	// char *p;
	// p = ft_sixteen_base_min(1000);
	// printf("%s\n", p);

	// unsigned int n;
	// char a;

	// n = 15 % 16 + 0x00;
	// printf("%u", n);
	// a = (char)n;
	// printf("\n\n\n%c", 0x41-10);
	return (0);
}