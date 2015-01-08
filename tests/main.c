#include "../ft_printf.h"
#include <stdio.h>



#define TEST(format, ...)						\
	PRINTF_TEST("format = |");					\
	if (IMMEDIATE_PRINTING)						\
		{ ft_putstr(format); } else { printf("%s", format); }	\
	PRINTF_TEST("|::|");						\
	ret = PRINTF_TEST(format, ##__VA_ARGS__);	\
	PRINTF_TEST("| ret = ");					\
	if (IMMEDIATE_PRINTING)						\
		{ ft_putnbr(ret); } else { printf("%d", ret); } \
	PRINTF_TEST("\n");

// %[flags][width][.precision][length]specifier

void				test_width_number(int ret, int num)
{
	TEST("width = %1d", num);
	TEST("width = %2d", num);
	TEST("width = %3d", num);
	TEST("width = %4d", num);
	TEST("width = %7d", num);
	TEST("width = %10d", num);
	TEST("width = %78d", num);
	TEST("width = %1234d", num);
}

void				test_width(int ret)
{
	test_width_number(ret, 0);
	test_width_number(ret, 1);
	test_width_number(ret, -1);
	test_width_number(ret, 2);
	test_width_number(ret, -2);
	test_width_number(ret, 42);
	test_width_number(ret, 42);
	test_width_number(ret, 123);
}

void				test_d(int ret)
{
	TEST("three = %d", 3);
	TEST("four = %d", 4);
	TEST("zero = %d", 0);
	TEST("fourty two = %d", 42);
	TEST("int max - 1 = %d", INT_MAX - 1);
	TEST("int max = %d", INT_MAX);
	TEST("minus one = %d", -1);
	TEST("minus three = %d", -3);
	TEST("minus fourty two = %d", -42);
	TEST("int min + 1 = %d", INT_MIN + 1);
	TEST("int min = %d", INT_MIN);
	TEST("long max = %lld", LLONG_MAX);
}

void				test_i(int ret)
{
	TEST("three = %i", 3);
	TEST("four = %i", 4);
	TEST("zero = %i", 0);
	TEST("fourty two = %i", 42);
	TEST("int max - 1 = %i", INT_MAX - 1);
	TEST("int max = %i", INT_MAX);
	TEST("minus one = %i", -1);
	TEST("minus three = %i", -3);
	TEST("minus fourty two = %i", -42);
	TEST("int min + 1 = %i", INT_MIN + 1);
	TEST("int min = %i", INT_MIN);
}

void				test_precision_number(int ret, int num)
{
	TEST("precision = %.d", num);
	TEST("precision = %.0d", num);
	TEST("precision = %.1d", num);
	TEST("precision = %.2d", num);
	TEST("precision = %.3d", num);
	TEST("precision = %.4d", num);
	TEST("precision = %.5d", num);
	TEST("precision = %.7d", num);
	TEST("precision = %.10d", num);
	TEST("precision = %.17d", num);
}

void				test_precision(int ret)
{
	test_precision_number(ret, 1);
	test_precision_number(ret, 3);
	test_precision_number(ret, 10);
	test_precision_number(ret, 40);
	test_precision_number(ret, 1003);
	test_precision_number(ret, -1);
	test_precision_number(ret, -42);
	test_precision_number(ret, 0);
}

void				test_zero_flag_number(int ret, int num)
{
	TEST("zero flag = %013d", num);
	TEST("zero flag = %0.13d", num);
	TEST("zero flag = %07.13d", num);
	TEST("zero flag = %013.7d", num);
}

void				test_space_flag_number(int ret, int num)
{
	TEST("space flag = % d", num);
	TEST("space flag = % 13d", num);
	TEST("space flag = % .13d", num);
	TEST("space flag = % 7.13d", num);
	TEST("space flag = % 13.7d", num);
}

int					main(void)
{
	int				ret; // return value

	if (IMMEDIATE_PRINTING)
		ft_putstr("mine is first\n");
	else
		printf("theirs is second\n");
	TEST("Hello World!");
	TEST("This is the second test.");
	TEST("%d", 18);
	TEST("%+d", 18);
	test_d(ret);
	test_i(ret);
	test_width(ret);
	test_precision(ret);
	test_zero_flag_number(ret, 42);
	test_zero_flag_number(ret, 0);
	test_zero_flag_number(ret, -42);
	test_zero_flag_number(ret, -1);
	test_zero_flag_number(ret, 1);
	test_space_flag_number(ret, 1);
	//test_space_flag_number(ret, 1);
	//test_space_flag_number(ret, 1);
	/* TEST("  width 5 = %5d", -42); */
	//	TEST("0 width 5 = %05d", -42);
	return (0);
}
