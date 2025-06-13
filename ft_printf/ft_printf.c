/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgahrama <zgahrama@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:17:42 by zgahrama          #+#    #+#             */
/*   Updated: 2025/06/11 17:44:05 by zgahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
int ft_printf(const char *format, ...)
{   va_list args;
    va_start(args, format);
    int i;
    i = 0;
    while(format[i])
    {
        if(format[i] == '%')
        {
            i++;
            check_arg(format[i], args);
        }
        write(1, &format[i], 1);
        i++; 
    }
}