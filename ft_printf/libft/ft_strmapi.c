/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoda <kyoda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 12:44:49 by keys              #+#    #+#             */
/*   Updated: 2022/09/01 13:00:00 by kyoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	char	*p;
	size_t	i;
	char	*tmp;

	if (!s || !f)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	p = malloc(len + 1);
	if (p == NULL)
		return (NULL);
	tmp = p;
	while (i < len)
	{
		*p = f(i, *s);
		p++;
		i++;
		s++;
	}
	*p = '\0';
	return (tmp);
}
