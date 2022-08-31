/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoda <kyoda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 17:24:45 by kyoda             #+#    #+#             */
/*   Updated: 2022/08/31 18:25:36 by kyoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static int	check(const char *format)
{
	if (*format == 'c')
		return ;
	else if (*format == 's')
		return ;
	else if (*format == 'p')
		return ;
	else if (*format == 'd')
		return ;
	else if (*format == 'i')
		return ;
	else if (*format == 'u')
		return ;
	else if (*format == 'x')
		return ;
	else if (*format == 'X')
		return ;
	else if (*format == '%')
		return ;
}

int	ft_printf(const char *format, ...)
{
	va_list args;
	va_list argc;
	char *day;
	va_start(args, format);
	va_copy(argc, args);
	while (*format != '\0')
	{

	}
	va_end(args);
	va_end(argc);
}