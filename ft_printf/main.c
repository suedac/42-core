// ...existing code...

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char c = 'A';
	char *s = "Hello";
	int i = 42;
	unsigned int u = 123456;
	void *p = &i;

	// Edge case variables
	char empty_str[] = "";
	char *null_str = NULL;
	int min_int = -2147483648;
	int max_int = 2147483647;
	unsigned int zero_u = 0;
	unsigned int max_u = 4294967295U;
	void *null_ptr = NULL;
	char percent = '%';

	void ft_printf_one(const char format, ...)
	{
		va_list args;
		va_start(args, format);
		check_arg(format, args);
		va_end(args);
	}

	printf("Standard printf:\n");
	printf("char: %c\n", c);
	printf("string: %s\n", s);
	printf("pointer: %p\n", p);
	printf("int: %d\n", i);
	printf("unsigned: %u\n", u);
	printf("hex lower: %x\n", u);
	printf("hex upper: %X\n", u);
	printf("percent: %%\n");

	// Edge cases
	printf("empty string: '%s'\n", empty_str);
	printf("null string: '%s'\n", null_str);
	printf("min int: %d\n", min_int);
	printf("max int: %d\n", max_int);
	printf("zero unsigned: %u\n", zero_u);
	printf("max unsigned: %u\n", max_u);
	printf("null pointer: %p\n", null_ptr);
	printf("negative hex: %x\n", -42);
	printf("negative unsigned: %u\n", -42);

	write(1, "\nYour ft_printf_one:\n", 20);
	write(1, "char: ", 6);
	ft_printf_one('c', c);
	write(1, "\n", 1);
	write(1, "string: ", 8);
	ft_printf_one('s', s);
	write(1, "\n", 1);
	write(1, "pointer: ", 9);
	ft_printf_one('p', p);
	write(1, "\n", 1);
	write(1, "int: ", 5);
	ft_printf_one('i', i);
	write(1, "\n", 1);
	write(1, "unsigned: ", 10);
	ft_printf_one('u', u);
	write(1, "\n", 1);
	write(1, "hex lower: ", 11);
	ft_printf_one('x', u);
	write(1, "\n", 1);
	write(1, "hex upper: ", 11);
	ft_printf_one('X', u);
	write(1, "\n", 1);
	write(1, "percent: ", 9);
	ft_printf_one('%');
	write(1, "\n", 1);

	// Edge cases
	write(1, "empty string: '", 15);
	ft_printf_one('s', empty_str);
	write(1, "'\n", 2);
	write(1, "null string: '", 14);
	ft_printf_one('s', null_str);
	write(1, "'\n", 2);
	write(1, "min int: ", 9);
	ft_printf_one('d', min_int);
	write(1, "\n", 1);
	write(1, "max int: ", 9);
	ft_printf_one('d', max_int);
	write(1, "\n", 1);
	write(1, "zero unsigned: ", 15);
	ft_printf_one('u', zero_u);
	write(1, "\n", 1);
	write(1, "max unsigned: ", 14);
	ft_printf_one('u', max_u);
	write(1, "\n", 1);
	write(1, "null pointer: ", 14);
	ft_printf_one('p', null_ptr);
	write(1, "\n", 1);
	write(1, "negative hex: ", 14);
	ft_printf_one('x', -42);
	write(1, "\n", 1);
	write(1, "negative unsigned: ", 19);
	ft_printf_one('u', -42);
	write(1, "\n", 1);

	return (0);
}