/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoda <kyoda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 20:42:38 by kyoda             #+#    #+#             */
/*   Updated: 2022/08/30 09:21:23 by kyoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	c;
	size_t	tmp_len;

	c = *needle;
	tmp_len = ft_strlen(needle);
	if (*needle != '\0')
	{
		if (tmp_len > len)
			return (NULL);
		while (1)
		{
			while (*(haystack++) != c)
			{
				if (len-- < 1 || *(haystack - 1) == '\0')
					return (NULL);
			}
			if (tmp_len > len--)
				return (NULL);
			if (ft_strncmp((haystack - 1), needle, tmp_len) == 0)
				break ;
		}
		haystack--;
	}
	return ((char *)haystack);
}
