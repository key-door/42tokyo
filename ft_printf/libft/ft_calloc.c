/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoda <kyoda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 19:36:32 by kyoda             #+#    #+#             */
/*   Updated: 2022/09/01 12:51:29 by kyoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	if ((SIZE_T_MAX / (long double)count) < (long double)size)
		return (NULL);
	if (count == 0 || size == 0)
		return (ft_calloc(1, 1));
	p = malloc(count * size);
	if (p == NULL)
		return (NULL);
	else
		ft_bzero(p, count * size);
	return (p);
}
