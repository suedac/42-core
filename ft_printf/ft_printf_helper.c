/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgahrama <zgahrama@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:21:55 by zgahrama          #+#    #+#             */
/*   Updated: 2025/06/11 17:43:01 by zgahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void print_hex_lower_case(unsigned int n)
{
    char hex_digits[] = "0123456789abcdef";
    char buf[9];
    int i = 8;
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
void print_hex_upper_case(unsigned int n)
{
    char hex_digits[] = "0123456789ABCDEF";
    char buf[9];
    int i = 8;
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
void check_arg(const char format, va_list args)
{
    int i;
    if(format == 'c')
    {
        char c = (char)va_arg(args, int);
        write(1, &c, 1);
    }
    else if(format == 's')
    {
        i = 0;
        char *s = va_arg(args, char*);
        while(s[i])
        {
            write(1, &s[i], 1);
            i++;
        }
    }
    else if(format == 'p')
    {
        void *p = va_arg(args, int*);
        write(1, p, sizeof(void*));
    }
    else if(format == 'd')
    {
        double d = va_arg(args, double);
        write(1, &d, sizeof(double));
    }
    else if(format == 'i')
    {
        int i = va_arg(args, int);
        write(1, &i, sizeof(int));
    }
     else if(format == 'u')
    {
       double u = va_arg(args, double);
       if(u < 0)
       {
            u = u * -1;
       }
        write(1, &u, sizeof(double));
    }
    else if (format == 'x')
    {
        unsigned int x = va_arg(args, unsigned int);
        print_hex_lower_case(x);
    }
    else if (format == 'X')
    {
        unsigned int x = va_arg(args, unsigned int);
        print_hex_upper_case(x);
    }
    else if(format == '%')
    {
        char m = '%';
        write(1, &m, 1);
    }
}