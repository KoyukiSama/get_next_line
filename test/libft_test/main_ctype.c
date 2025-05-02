
#include "tester_macro.h"
#include "../libft/libft.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define GREEN "\x1b[32m"
#define RED "\x1b[31m"
#define RESET "\x1b[0m"

#define TEST(res1, res2, printf_type, input, name, pass_count)			\
	do {																\
		char fail = 0;													\
		if (res1 != res2)												\
		{																\
			fail = 1;													\
			printf(RED "[FAIL] " RESET "%s(%lu)\n", name, input);		\
			printf("MINE:  = %"printf_type"\n", res1);					\
			printf("CORR:  = %"printf_type"\n", res2);					\
		}																\
		if (i == pass_count && !fail)									\
			printf(GREEN "[PASS] " RESET "%s()\n", name); 				\
	} while (0);														\

int main(void)
{
	size_t pass_count = 255;

	for (size_t i = 0; i <= pass_count; i++)
	{
		TEST((ft_isalpha(i) > 0), (isalpha(i) > 0), "i", i, "ft_isalpha", pass_count);
		TEST((ft_isdigit(i) > 0), (isdigit(i) > 0), "i", i, "ft_isdigit", pass_count);
		TEST((ft_isalnum(i) > 0), (isalnum(i) > 0), "i", i, "ft_isalnum", pass_count);
		TEST((ft_isascii(i) > 0), (isascii(i) > 0), "i", i, "ft_isascii", pass_count);
		TEST((ft_isprint(i) > 0), (isprint(i) > 0), "i", i, "ft_isprint", pass_count);
		TEST((ft_isspace(i) > 0), (isspace(i) > 0), "i", i, "ft_isspace", pass_count);

		TEST(ft_toupper(i), toupper(i), "i", i, "ft_toupper", pass_count);
		TEST(ft_tolower(i), tolower(i), "i", i, "ft_tolower", pass_count);
	}
	
}
