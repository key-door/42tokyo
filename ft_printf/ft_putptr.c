/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoda <kyoda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 08:43:02 by kyoda             #+#    #+#             */
/*   Updated: 2022/09/03 11:41:35 by kyoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

static int	put(uintptr_t n, int len)
{
	char	ans;

	if (n >= 16)
	{
		len = put(n / 16, len);
		len = put(n % 16, len);
	}
	else
	{
		if (n <= 9)
		{
			ans = n + '0';
			len += write(1, &ans, 1);
		}
		else
		{
			ans = n + 'W';
			len += write(1, &ans, 1);
		}
	}
	return (len);
}


int	ft_put_ptr(uintptr_t ptr)
{
	int	len;

	len = 0;
	len += write(1, "0x", 2);
	if (!ptr)
		len += write(1, "0", 1);
	else
		len += put(ptr, 0);
	return (len);
}
