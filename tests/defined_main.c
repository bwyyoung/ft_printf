#define PRINTF_TEST ft_printf
#define IMMEDIATE_PRINTING 1
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
	TEST("int max = %d", INT_MAX);
	TEST("int min - 1 = %ld", ((long)INT_MIN) - 1);
	/* TEST("long min = %ld", LONG_MIN); */
	/* TEST("long min + 1 = %ld", LONG_MIN + 1); */
	/* TEST("long max - 1 = %ld", LONG_MAX - INT_MAX); */
	/* TEST("long max = %ld", LONG_MAX); */
	/* TEST("long long max = %lld", LLONG_MAX); */
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
}

void				test_space_flag_number(int ret, int num)
{
	TEST("space flag = % d", num);
	TEST("space flag = % 13d", num);
	TEST("space flag = % .13d", num);
	TEST("space flag = % 7.13d", num);
	TEST("space flag = % 13.7d", num);
}

void				do_not_compile(int ret)
{
	TEST("d with z length = %zd", (size_t)8);
}

void				tests(int ret)
{
		TEST("Hello World!");
	TEST("This is the second test.");
	TEST("%d", 18);
	TEST("%+d", 18);
	TEST("% d", 18);
	TEST("%ld", ((long)INT_MAX) + 2);
	test_d(ret);
	test_width(ret);
	test_precision(ret);
	test_zero_flag_number(ret, 42);
	test_zero_flag_number(ret, 0);
	test_zero_flag_number(ret, -42);
	test_zero_flag_number(ret, -1);
	test_zero_flag_number(ret, 1);
	test_space_flag_number(ret, 1);
	test_space_flag_number(ret, -1);
	test_space_flag_number(ret, 0);
	test_space_flag_number(ret, -1);
	TEST("%3.*i\n", 0, 18);
	TEST("%s", "abc");

	/* TEST("%.*d", -1, 3); */
	/* TEST("%.*d", -5, 0); causes errors printed by mine*/
	/* TEST("%.*d", -5, 1); */
	TEST("%.d", 1);
	TEST("%.d", 0);
	TEST("%.0d", 1);
	TEST("%.0d", 0);
	TEST("%lo, %lo", (unsigned long)0, ULONG_MAX);
	
	/* TEST("%u", UINT_MAX - 1); */
	/* TEST("%u", UINT_MAX); */
	/* TEST("%x", 42); */
	/* TEST("%x, %x", 0, UINT_MAX); */
	//TEST("%llO", USHRT_MAX);
	//TEST("{%-15Z}", 123);
	//	TEST("%.*d", -5, 0);
	//	TEST("%ll# 2.3hd", 356565655);
}

int					main(void)
{
	int				ret; // return value

	if (IMMEDIATE_PRINTING)
		ft_putstr("mine is first\n");
	else
		printf("theirs is second\n");
	ret = 0;
	tests(ret);

	/*
	** add stuff here
	*/
	/* TEST("%s", "woohoo!"); */
	/* TEST("%10Z", "asdf"); */
	/* TEST("%s", "whatever"); */
	/* TEST("%", "asdf"); */
	/* TEST("%05. hello", "asdf"); */
	/* TEST("%lD", LONG_MAX); */
	TEST("%llO", USHRT_MAX);
	
	return (0);
}
