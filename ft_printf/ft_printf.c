/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgahrama <zgahrama@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:12:38 by zgahrama          #+#    #+#             */
/*   Updated: 2025/06/16 15:14:49 by zgahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf_loop(const char *format, va_list args, int i, int count)
{
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			count += check_arg(format[i], args);
		}
		else if (format[i] == '%' && !format[i + 1])
		{
			write(1, "%", 1);
			count++;
			i++;
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = ft_printf_loop(format, args, 0, 0);
	va_end(args);
	return (count);
}
