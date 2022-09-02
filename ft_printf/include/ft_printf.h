/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoda <kyoda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:13:28 by kyoda             #+#    #+#             */
/*   Updated: 2022/09/03 06:25:10 by kyoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

int		ft_printf(const char *format, ...);
char	*ft_itoarray(unsigned long n, char *str, unsigned long base, int flagx);
int		ft_itoa_u_int(long n);
int		ft_itoa_six_base(unsigned int n, int flagx);
int		ft_putptr(va_list ap);
int		ft_str_print(va_list ap);

#endif
