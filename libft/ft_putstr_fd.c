/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoda <kyoda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 20:41:57 by kyoda             #+#    #+#             */
/*   Updated: 2022/08/30 08:30:54 by kyoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	len;
	char	*tmp;

	len = 0;
	if (!s)
		return ;
	tmp = s;
	while (*(tmp++))
		len++;
	if (len <= INT_MAX)
		write(fd, s, len);
	else
	{
		while (len > INT_MAX)
		{
			len -= INT_MAX;
			s += INT_MAX;
			write(fd, s, INT_MAX);
		}
		s += INT_MAX;
		write(fd, s, len);
	}
}
