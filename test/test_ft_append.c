
#include "tester_macro.h"
#include "../get_next_line.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char	*ft_stash_append(char *stash_old, const char *buff);

int main(void)
{
	printf(STRING_DISPLAY("ft_stash_append"));

	char	*stash = NULL;
	char	buff1[] = "hi";
	char	buff2[] = ", ";
	char	buff3[] = "my name ";
	char	buff4[] = "is casper ";
	char	buff5[] = "het spook ";
	char	buff6[] = "en ik kom ";
	char	buff7[] = "van de ";
	char	buff8[] = "ghost schoooooooool ";
	char	buff9[] = "";

	char	corr1[] = "hi";
	char	corr2[] = "hi, ";
	char	corr3[] = "hi, my name ";
	char	corr4[] = "hi, my name is casper ";
	char	corr5[] = "hi, my name is casper het spook ";
	char	corr6[] = "hi, my name is casper het spook "\
						"en ik kom ";
	char	corr7[] = "hi, my name is casper het spook "\
						"en ik kom van de ";
	char	corr8[] = "hi, my name is casper het spook "\
						"en ik kom van de ghost schoooooooool ";
	char	corr9[] = "hi, my name is casper het spook "\
						"en ik kom van de ghost schoooooooool ";
	stash = ft_stash_append(stash, buff1);
	TEST_STRCMP_NOFREE(stash, corr1, "");
	stash = ft_stash_append(stash, buff2);
	TEST_STRCMP_NOFREE(stash, corr2, "");
	stash = ft_stash_append(stash, buff3);
	TEST_STRCMP_NOFREE(stash, corr3, "");
	stash = ft_stash_append(stash, buff4);
	TEST_STRCMP_NOFREE(stash, corr4, "");
	stash = ft_stash_append(stash, buff5);
	TEST_STRCMP_NOFREE(stash, corr5, "");
	stash = ft_stash_append(stash, buff6);
	TEST_STRCMP_NOFREE(stash, corr6, "");
	stash = ft_stash_append(stash, buff7);
	TEST_STRCMP_NOFREE(stash, corr7, "");
	stash = ft_stash_append(stash, buff8);
	TEST_STRCMP_NOFREE(stash, corr8, "");
	stash = ft_stash_append(stash, buff9);
	TEST_STRCMP_NOFREE(stash, corr9, "hi, my name is casper het spook "\
						"en ik kom van de ghost schoooooooool ");
	free(stash);
}
