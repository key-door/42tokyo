/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoda <kyoda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 20:03:05 by kyoda             #+#    #+#             */
/*   Updated: 2022/08/30 05:44:43 by kyoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*p;

	if (s1 == NULL)
		return (NULL);
	len = ft_strlen(s1);
	p = malloc(len + 1);
	if (p == NULL)
		return (NULL);
	else
		ft_memcpy(p, s1, len);
	p[len] = '\0';
	return (p);
}
