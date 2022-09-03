/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoda <kyoda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 10:23:50 by kyoda             #+#    #+#             */
/*   Updated: 2022/09/03 10:27:53 by kyoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

static int	put(unsigned int n, int len)
{
	char	ans;

	if (n >= 10)
	{
		len = put(n / 10, len);
		len = put(n % 10, len);
	}
	else
	{
		ans = n + '0';
		len += write(1, &ans, 1);
	}
	return (len);
}

int	ft_putnbr_ui(unsigned int n)
{
	int	len;

	len = 0;
	if (n== 0)
        return write(1,"0",1);
	len += put(n, len);
	return (len);
}
