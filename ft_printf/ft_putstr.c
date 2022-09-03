/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoda <kyoda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 09:19:46 by kyoda             #+#    #+#             */
/*   Updated: 2022/09/03 11:29:36 by kyoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int	ft_putstr(char *p)
{
	if (p == NULL)
		return (write(1, "(null)", 6));
	ft_putstr_fd(p, 1);
	return (int)ft_strlen(p);
}
