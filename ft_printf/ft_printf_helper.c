/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgahrama <zgahrama@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:21:55 by zgahrama          #+#    #+#             */
/*   Updated: 2025/06/16 15:16:01 by zgahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(va_list args)
{
	char	c;

	c = (char)va_arg(args, int);
	write(1, &c, 1);
	return (1);
}

int	print_str(va_list args)
{
	char	*s;
	int		i;

	s = va_arg(args, char *);
	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else
	{
		while (s[i])
		{
			write(1, &s[i], 1);
			i++;
		}
	}
	return (i);
}

int	print_ptr(va_list args)
{
	void			*p;
	unsigned long	addr;
	char			hex[17];
	int				i;
	int				len;

	i = 0;
	len = 0;
	p = va_arg(args, void *);
	if (!p)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	addr = (unsigned long)p;
	write(1, "0x", 2);
	len += 2;
	while (addr)
	{
		hex[i++] = "0123456789abcdef"[addr % 16];
		addr /= 16;
	}
	while (i--)
		len += write(1, &hex[i], 1);
	return (len);
}

int	print_percent(void)
{
	char	m;

	m = '%';
	write(1, &m, 1);
	return (1);
}

int	check_arg(const char format, va_list args)
{
	if (format == 'c')
		return (print_char(args));
	else if (format == 's')
		return (print_str(args));
	else if (format == 'p')
		return (print_ptr(args));
	else if (format == 'i' || format == 'd')
		return (print_number(va_arg(args, int)));
	else if (format == 'u')
		return (print_unsigned(va_arg(args, unsigned int)));
	else if (format == 'x')
		return (print_hex_lower_case((unsigned int)va_arg(args, int)));
	else if (format == 'X')
		return (print_hex_upper_case((unsigned int)va_arg(args, int)));
	else if (format == '%')
		return (print_percent());
	return (0);
}
