/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoda <kyoda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 08:52:37 by kyoda             #+#    #+#             */
/*   Updated: 2022/09/03 10:56:02 by kyoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

static int	put(long n, int len)
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

int	ft_putnbr(int n)
{
	int		len;
	long	nbr;

	nbr = n;
	len = 0;
	if (nbr < 0)
	{
		len += write(1, "-", 1);
		nbr *= -1;
	}
	else if (nbr == 0)
	{
		len += write(1, "0", 1);
		return (len);
	}
	len += put(nbr, 0);
	return (len);
}
