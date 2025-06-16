/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgahrama <zgahrama@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:21:55 by zgahrama          #+#    #+#             */
/*   Updated: 2025/06/16 11:41:34 by zgahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(va_list args)
{
    char	c = (char)va_arg(args, int);
    write(1, &c, 1);
}

void	print_str(va_list args)
{
    char	*s = va_arg(args, char *);
    int		i = 0;

    if (!s)
        write(1, "(null)", 6);
    else
    {
        while (s[i])
        {
            write(1, &s[i], 1);
            i++;
        }
    }
}

void	print_ptr(va_list args)
{
    void			*p = va_arg(args, void *);
    unsigned long	addr = (unsigned long)p;
    char			hex[17];
    int				i = 16;

    write(1, "0x", 2);
    hex[i] = '\0';
    if (addr == 0)
        write(1, "0", 1);
    else
    {
        while (addr > 0)
        {
            hex[--i] = "0123456789abcdef"[addr % 16];
            addr /= 16;
        }
        write(1, &hex[i], 16 - i);
    }
}

void	print_percent(void)
{
    char	m = '%';
    write(1, &m, 1);
}

void	check_arg(const char format, va_list args)
{
    if (format == 'c')
        print_char(args);
    else if (format == 's')
        print_str(args);
    else if (format == 'p')
        print_ptr(args);
    else if (format == 'i' || format == 'd')
        print_number(va_arg(args, int));
    else if (format == 'u')
        print_unsigned(va_arg(args, unsigned int));
    else if (format == 'x')
        print_hex_lower_case(va_arg(args, unsigned int));
    else if (format == 'X')
        print_hex_upper_case(va_arg(args, unsigned int));
    else if (format == '%')
        print_percent();
}