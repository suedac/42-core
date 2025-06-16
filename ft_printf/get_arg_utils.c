/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgahrama <zgahrama@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 11:36:18 by zgahrama          #+#    #+#             */
/*   Updated: 2025/06/16 11:41:43 by zgahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hex_lower_case(unsigned int n)
{
    char	hex_digits[] = "0123456789abcdef";
    char	buf[9];
    int		i = 8;

    buf[i] = '\0';
    if (n == 0)
        write(1, "0", 1);
    else
    {
        while (n > 0)
        {
            buf[--i] = hex_digits[n % 16];
            n /= 16;
        }
        write(1, &buf[i], 8 - i);
    }
}

void	print_hex_upper_case(unsigned int n)
{
    char	hex_digits[] = "0123456789ABCDEF";
    char	buf[9];
    int		i = 8;

    buf[i] = '\0';
    if (n == 0)
        write(1, "0", 1);
    else
    {
        while (n > 0)
        {
            buf[--i] = hex_digits[n % 16];
            n /= 16;
        }
        write(1, &buf[i], 8 - i);
    }
}

void	print_number(int n)
{
    char	c;

    if (n == -2147483648)
    {
        write(1, "-2147483648", 11);
        return ;
    }
    if (n < 0)
    {
        write(1, "-", 1);
        n = -n;
    }
    if (n >= 10)
        print_number(n / 10);
    c = '0' + (n % 10);
    write(1, &c, 1);
}

void	print_unsigned(unsigned int n)
{
    char	c;

    if (n >= 10)
        print_unsigned(n / 10);
    c = '0' + (n % 10);
    write(1, &c, 1);
}
