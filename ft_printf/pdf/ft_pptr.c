/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pptr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoda <kyoda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 08:01:49 by kyoda             #+#    #+#             */
/*   Updated: 2022/09/03 08:01:51 by kyoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int    lenptr(uintptr_t num)
{
    int    len;

    len = 0;
    while (num != 0)
    {
        len++;
        num = num / 16;
    }
    return (len);
}

void    outptr(uintptr_t num)
{
    if (num >= 16)
    {
        outptr(num / 16);
        outptr(num % 16);
    }
    else
    {
        if (num <= 9)
            putchar_int(num + '0');
        else
            putchar_int(num - 10 + 'a');
    }
}

int    put_ptr(uintptr_t ptr)
{
    int    len;

    len = 0;
    len += write(1, "0x", 2);
    if (!ptr)
        len += write(1, "0", 1);
    else
    {
        outptr(ptr);
        len += lenptr(ptr);
    }
    return (len);
}