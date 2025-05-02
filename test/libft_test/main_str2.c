
#include "tester_macro.h"
#include "../libft/libft.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// strmapi
static char trans_same(unsigned int i, char c)
{
	(void)i;
	return c;
}
static char trans_upper(unsigned int i, char c)
{
	(void)i;
	return (char)ft_toupper((unsigned char)c);
}
static char trans_shifti(unsigned int i, char c)
{
	return (char)(c + i);
}
static char trans_digiti(unsigned int i, char c)
{
	(void)c;
	return (char)('0' + (i % 10));
}

// striteri
static void trans_upper_it(unsigned int i, char *c)
{
    (void)i;
    *c = ft_toupper(*c);
}
static void trans_shifti_it(unsigned int i, char *c)
{
    *c = *c + i;
}
static void trans_digiti_it(unsigned int i, char *c)
{
    *c = '0' + i;
}

int main(void)
{
	printf("++++++++++++ft_split++++++++++++\n");
	char *arr[] = {NULL};
	char *arr1[] = {"a", NULL};
	char *arr2[] = {"a", "b", NULL};
	char *arr3[] = {"a", "b", "c", NULL};
	TEST_STRSCMP(ft_split("", ','), arr, "ft_split(\"\", ',') -> [NULL]");
	TEST_STRSCMP(ft_split("a", ','), arr1, "ft_split(\"a\", ',') -> [\"a\", NULL]");
	TEST_STRSCMP(ft_split(",", ','), arr, "ft_split(\",\", ',') -> [NULL]");
	TEST_STRSCMP(ft_split(",,", ','), arr, "ft_split(\",,\", ',') -> [NULL]");
	TEST_STRSCMP(ft_split(",a,", ','), arr1, "ft_split(\",a,\", ',') -> [\"a\", NULL]");
	TEST_STRSCMP(ft_split("a,b", ','), arr2, "ft_split(\"a,b\", ',') -> [\"a\", \"b\", NULL]");
	TEST_STRSCMP(ft_split("a,,b", ','), arr2, "ft_split(\"a,,b\", ',') -> [\"a\", \"b\", NULL]");
	TEST_STRSCMP(ft_split("a b c", ' '), arr3, "ft_split(\"a b c\", ' ') -> [\"a\", \"b\", \"c\", NULL]");

	printf("++++++++++++ft_strmapi++++++++++++\n");
	TEST_STRCMP(ft_strmapi("", trans_same), "", "ft_strmapi(\"\", trans_same)");
	TEST_STRCMP(ft_strmapi("Hello, World!", trans_same), "Hello, World!", "ft_strmapi(\"Hello, World!\", trans_same)");
	TEST_STRCMP(ft_strmapi("Hello, World!", trans_upper), "HELLO, WORLD!", "ft_strmapi(\"Hello, World!\", trans_upper)");
	TEST_STRCMP(ft_strmapi("abcd", trans_shifti), "aceg", "ft_strmapi(\"abcd\", trans_shifti)");
	TEST_STRCMP(ft_strmapi("xxxxxx", trans_digiti), "012345", "ft_strmapi(\"\", trans_digiti)");

	printf("++++++++++++ft_striteri++++++++++++\n");
    char s3[] = "Hello, World!";
    ft_striteri(s3, trans_upper_it);
    TEST_STRCMP_NOFREE(s3, "HELLO, WORLD!", "ft_striteri(\"Hello, World!\", trans_upper_it)");
    char s4[] = "abcd";
    ft_striteri(s4, trans_shifti_it);
    TEST_STRCMP_NOFREE(s4, "aceg", "ft_striteri(\"abcd\", trans_shifti_it)");
    char s5[] = "xxxxxx";
    ft_striteri(s5, trans_digiti_it);
    TEST_STRCMP_NOFREE(s5, "012345", "ft_striteri(\"xxxxxx\", trans_digiti_it)");
}
