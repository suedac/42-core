/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgahrama <zgahrama@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:17:54 by zgahrama          #+#    #+#             */
/*   Updated: 2025/06/16 11:41:28 by zgahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>

int ft_printf(const char *format, ...);
void check_arg(const char format, va_list args);
void print_hex(unsigned int n);
void	print_number(int n);
void	print_hex_upper_case(unsigned int n);
void	print_hex_lower_case(unsigned int n);
void	print_unsigned(unsigned int n);

#endif