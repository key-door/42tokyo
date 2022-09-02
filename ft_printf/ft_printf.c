/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoda <kyoda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 12:20:52 by kyoda             #+#    #+#             */
/*   Updated: 2022/09/03 05:09:40 by kyoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

static int	selection_percent(va_list ap, const char *format)
{
	int	len;

	len = 1;
	if (*format == 'c')
		ft_putchar_fd((char)va_arg(ap, int), 1);
	else if (*format == 's')
		return (ft_str_print(ap));
	else if (*format == 'p')
		return (ft_putptr(ap));
	else if (*format == 'd')
		return (ft_itoa_u_int(va_arg(ap, int)));
	else if (*format == 'i')
		return (ft_itoa_u_int(va_arg(ap, int)));
	else if (*format == 'u')
		return (ft_itoa_u_int(va_arg(ap, unsigned int)));
	else if (*format == 'x')
		return (ft_itoa_six_base(va_arg(ap, unsigned int), 1));
	else if (*format == 'X')
		return (ft_itoa_six_base(va_arg(ap, unsigned int), 2));
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
			ft_putchar_fd(*format++, 1);
			re_ans += 1;
		}
	}
	va_end(ap);
	return (re_ans);
}
