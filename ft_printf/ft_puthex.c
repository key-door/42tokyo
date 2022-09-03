/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoda <kyoda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 09:41:51 by kyoda             #+#    #+#             */
/*   Updated: 2022/09/03 11:19:42 by kyoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

static int	put(unsigned int n, int len, int flag)
{
	char	ans;
	char	c;

	if (flag == 0)
		c = 'W';
	else
		c = '7';
	if (n >= 16)
	{
		len = put(n / 16, len, flag);
		len = put(n % 16, len, flag);
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
			ans = n + c;
			len += write(1, &ans, 1);
		}
	}
	return (len);
}

int	ft_puthex(unsigned int n, int flag)
{
	int	len;

	len = 0;
	if (n==0)
		return write(1, "0", 1);
	len += put(n, 0, flag);
	return (len);
}
