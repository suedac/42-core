/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgahrama <zgahrama@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 11:36:18 by zgahrama          #+#    #+#             */
/*   Updated: 2025/06/16 15:23:12 by zgahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;
	char	*s;

	i = 0;
	src_len = 0;
	s = (char *)src;
	while (s[src_len] != '\0')
	{
		src_len++;
	}
	if (size == 0)
	{
		return (src_len);
	}
	while (i < size - 1 && s[i] != '\0')
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

int	print_hex_lower_case(unsigned int n)
{
	char	hex_digits[17];
	char	buf[9];
	int		i;
	int		count;

	ft_strlcpy(hex_digits, "0123456789abcdef", 17);
	i = 8;
	buf[i] = '\0';
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (n > 0)
	{
		buf[--i] = hex_digits[n % 16];
		n /= 16;
	}
	count = 8 - i;
	write(1, &buf[i], count);
	return (count);
}

int	print_hex_upper_case(unsigned int n)
{
	char	hex_digits[17];
	char	buf[9];
	int		i;
	int		count;

	ft_strlcpy(hex_digits, "0123456789ABCDEF", 17);
	i = 8;
	buf[i] = '\0';
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (n > 0)
	{
		buf[--i] = hex_digits[n % 16];
		n /= 16;
	}
	count = 8 - i;
	write(1, &buf[i], count);
	return (count);
}

int	print_number(int n)
{
	int		count;
	char	c;

	count = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		count += 1;
		n = -n;
	}
	if (n >= 10)
		count += print_number(n / 10);
	c = '0' + (n % 10);
	write(1, &c, 1);
	count += 1;
	return (count);
}

int	print_unsigned(unsigned int n)
{
	int		count;
	char	c;

	count = 0;
	if (n >= 10)
		count += print_unsigned(n / 10);
	c = '0' + (n % 10);
	write(1, &c, 1);
	count += 1;
	return (count);
}
