
#include "tester_macro.h"
#include "../libft/libft.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	printf("++++++++++++ft_atoi++++++++++++\n");
	TEST_INTCMP(ft_atoi("42"), atoi("42"), "ft_atoi(\"42\")");
	TEST_INTCMP(ft_atoi("   -123"), atoi("   -123"), "ft_atoi(\"   -123\")");
	TEST_INTCMP(ft_atoi("+99"), atoi("+99"), "ft_atoi(\"+99\")");
	TEST_INTCMP(ft_atoi("abc"), atoi("abc"), "ft_atoi(\"abc\")");
	TEST_INTCMP(ft_atoi("123abc"), atoi("123abc"), "ft_atoi(\"123abc\")");
	TEST_INTCMP(ft_atoi("   +00000"), atoi("   +00000"), "ft_atoi(\"   +00000\")");
	TEST_INTCMP(ft_atoi("2147483647"), atoi("2147483647"), "ft_atoi(\"2147483647\")");
	TEST_INTCMP(ft_atoi("-2147483648"), atoi("-2147483648"), "ft_atoi(\"-2147483648\")");
	TEST_INTCMP(ft_atoi("  ++-4404"), atoi("  ++-4404"), "ft_atoi(\"  ++-4404\")");
	TEST_INTCMP(ft_atoi("  +-+4404"), atoi("  +-+4404"), "ft_atoi(\"  +-+4404\")");
	TEST_INTCMP(ft_atoi("  -+-4404"), atoi("  -+-4404"), "ft_atoi(\"  -+-4404\")");
	
	printf("++++++++++++ft_itoa++++++++++++\n");
	TEST_STRCMP(ft_itoa(0), "0", "ft_itoa(0)");
	TEST_STRCMP(ft_itoa(1), "1", "ft_itoa(1)");
	TEST_STRCMP(ft_itoa(-0), "0", "ft_itoa(0)");
	TEST_STRCMP(ft_itoa(-100), "-100", "ft_itoa(-100)");
	TEST_STRCMP(ft_itoa(-259029), "-259029", "ft_itoa(-259029)");
	TEST_STRCMP(ft_itoa(100), "100", "ft_itoa(100)");
	
}


