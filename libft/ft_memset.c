/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoda <kyoda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:36:47 by keys              #+#    #+#             */
/*   Updated: 2022/08/24 20:24:32 by kyoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	void	*tmp;

	tmp = s;
	while (n-- != 0)
	{
		*(unsigned char *)s = (unsigned char)c;
		s++;
	}
	return (tmp);
}
