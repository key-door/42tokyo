/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoda <kyoda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 01:50:06 by kyoda             #+#    #+#             */
/*   Updated: 2022/09/03 02:06:52 by kyoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

// int	ft_itoa_u_int(long n)
// {
// 	char	*str;
// 	int		i;
// 	int		len;
// 	int		flag;

// 	if (n < 0)
// 	{
// 		flag = 1;
// 		n *= -1;
// 	}
// 	i = 11;
// 	if ((str = calloc(12, 1)) == NULL)
// 		return (-1);
// 	while (n)
// 	{
// 		str[--i] = n % 10 + '0';
// 		n /= 10;
// 	}
// 	if (flag == 1)
// 		str[--i] = '-';
// 	while (str[i])
// 	{
// 		printf("%c", str[i]);
// 		i++;
// 	}
// 	// ft_putstr_fd(&str[i], 1);
// 	// len = (int)ft_strlen(&str[i]);
// 	free(str);
// 	return (len);
// }

int	ft_itoa_u_int(long n)
{
	char	*str;
	int		i;
	int		len;
	int		flag;

	if (n < 0)
	{
		flag = 1;
		n *= -1;
	}
	i = 11;
	// if ((str = ft_calloc(12, 1)) == NULL)
	if ((str = calloc(12, 1)) == NULL)
		return (-1);
	while (n)
	{
		str[--i] = n % 10 + '0';
		n /= 10;
	}
	if (flag == 1)
		str[--i] = '-';
	while (str[i])
	{
		printf("%c", str[i]);
		i++;
	}
		printf("\n");
	// ft_putstr_fd(&str[i], 1);
	// len = (int)ft_strlen(&str[i]);
	free(str);
	return (len);
}

int	main(void)
{
	ft_itoa_u_int(-12345);
	return (0);
}