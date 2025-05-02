
#include "tester_macro.h"
#include "../libft/libft.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>



int main(void)
{
	printf("++++++++++++ft_strlen++++++++++++\n");
	TEST_SIZETCMP(ft_strlen("helooooo"), strlen("helooooo"), "ft_strlen(\"helooooo\")");
	TEST_SIZETCMP(ft_strlen(""), strlen(""), "ft_strlen(\"\")");
	TEST_SIZETCMP(ft_strlen("a\0bcd"), strlen("a\0bcd"), "ft_strlen(\"a\\0bcd\")");
	
	printf("++++++++++++ft_strlcpy++++++++++++\n");
	char buf[10];
	ft_strlcpy(buf, "hello", sizeof(buf));
	TEST_STRCMP(strdup(buf), "hello", "ft_strlcpy(buf, \"hello\", 10)");
	ft_strlcpy(buf, "world", 3);
	TEST_STRCMP(strdup(buf), "wo", "ft_strlcpy(buf, \"world\", 3)");
	ft_strlcpy(buf, "", sizeof(buf));
	TEST_STRCMP(strdup(buf), "", "ft_strlcpy(buf, \"\", 10)");
	ft_strlcpy(buf, "abcde", 1);
	TEST_STRCMP(strdup(buf), "", "ft_strlcpy(buf, \"abcde\", 1)");

	printf("++++++++++++ft_strlcat++++++++++++\n");
	char buf1[10] = "foo";
	ft_strlcat(buf1, "bar", sizeof(buf1));
	TEST_STRCMP(strdup(buf1), "foobar", "ft_strlcat(buf1, \"bar\", 10)");
	char buf2[5] = "";
	ft_strlcat(buf2, "baz", sizeof(buf2));
	TEST_STRCMP(strdup(buf2), "baz", "ft_strlcat(buf2, \"baz\", 5)");
	char buf3[5] = "xy";
	ft_strlcat(buf3, "", sizeof(buf3));
	TEST_STRCMP(strdup(buf3), "xy", "ft_strlcat(buf3, \"\", 5)");
	char buf4[1] = "";
	ft_strlcat(buf4, "foo", sizeof(buf4));
	TEST_STRCMP(strdup(buf4), "", "ft_strlcat(buf4, \"foo\", 1)");
	
	printf("++++++++++++ft_strchr++++++++++++\n");
	char dst[100];
	ft_strlcpy(dst, "ABCDEABCDE", 10);
	TEST_PTRCMP(ft_strchr(dst, 'A'), strchr(dst, 'A'), "ft_strchr(dst, 'A')");
	TEST_PTRCMP(ft_strchr(dst, 'Z'), strchr(dst, 'Z'), "ft_strchr(dst, 'Z')");
	TEST_PTRCMP(ft_strchr(dst, '\0'), strchr(dst, '\0'), "ft_strchr(dst, '\\0')");
	ft_strlcpy(dst, "\0", 1);
	TEST_PTRCMP(ft_strchr(dst, '\0'), strchr(dst, '\0'), "ft_strchr(dst, '\\0')");
	TEST_PTRCMP(ft_strchr(dst, 'A'), strchr(dst, 'A'), "ft_strchr(dst, 'A')");

	printf("++++++++++++ft_strrchr++++++++++++\n");
	ft_strlcpy(dst, "ABCDEABCDE", 10);
	TEST_PTRCMP(ft_strrchr(dst, 'A'), strrchr(dst, 'A'), "ft_strrchr(dst, 'A')");
	TEST_PTRCMP(ft_strrchr(dst, 'Z'), strrchr(dst, 'Z'), "ft_strrchr(dst, 'Z')");
	TEST_PTRCMP(ft_strrchr(dst, '\0'), strrchr(dst, '\0'), "ft_strrchr(dst, '\\0')");
	ft_strlcpy(dst, "\0", 1);
	TEST_PTRCMP(ft_strrchr(dst, '\0'), strrchr(dst, '\0'), "ft_strrchr(dst, '\\0')");
	TEST_PTRCMP(ft_strrchr(dst, 'A'), strrchr(dst, 'A'), "ft_strrchr(dst, 'A')");
	
	printf("++++++++++++ft_strncmp++++++++++++\n");
	TEST_INTCMP(ft_strncmp("abc", "abc", 3), strncmp("abc", "abc", 3), "ft_strncmp(\"abc\", \"abc\", 3)");
	TEST_INTCMP(ft_strncmp("abc", "abd", 2), strncmp("abc", "abd", 2), "ft_strncmp(\"abc\", \"abd\", 2)");
	TEST_INTCMP(ft_strncmp("abc", "abd", 3), strncmp("abc", "abd", 3), "ft_strncmp(\"abc\", \"abd\", 3)");
	TEST_INTCMP(ft_strncmp("ab", "abc", 3), strncmp("ab", "abc", 3), "ft_strncmp(\"ab\", \"abc\", 3)");
	TEST_INTCMP(ft_strncmp("abc", "ab", 3), strncmp("abc", "ab", 3), "ft_strncmp(\"abc\", \"ab\", 3)");
	TEST_INTCMP(ft_strncmp("abc", "abc", 0), strncmp("abc", "abc", 0), "ft_strncmp(\"abc\", \"abc\", 0)");
	TEST_INTCMP(ft_strncmp("abc", "ABC", 3), strncmp("abc", "ABC", 3), "ft_strncmp(\"abc\", \"ABC\", 3");
	TEST_INTCMP(ft_strncmp("abc\0xyz", "abc\0xyz", 7), strncmp("abc\0xyz", "abc\0xyz", 7), "ft_strncmp(\"abc\\0xyz\", \"abc\\0xyz\", 7)");

	printf("++++++++++++ft_strnstr++++++++++++\n");
	ft_strlcpy(dst, "hello world", 100);
	TEST_BYTECMP(*ft_strnstr(dst, "world", 11), 'w', "ft_strnstr(\"hello world\", \"world\", 11)");
	TEST_PTRCMP(ft_strnstr(dst, "world", 5), NULL, "ft_strnstr(\"hello world\", \"world\", 5)");
	TEST_BYTECMP(*ft_strnstr(dst, "", 50), 'h', "ft_strnstr(\"hello world\", \"\", 50)");
	ft_strlcpy(dst, "", 100);
	TEST_BYTECMP(*ft_strnstr(dst, "", 50), '\0', "ft_strnstr(\"\", \"\", 50)");
	TEST_PTRCMP(ft_strnstr(dst, "abc", 50), NULL, "ft_strnstr(\"\", \"abc\", 50)");
	ft_strlcpy(dst, "abcabcabc", 100);
	TEST_BYTECMP(*ft_strnstr(dst, "cab", 6), 'c', "ft_strnstr(\"\", \"cab\", 6)");
	
	printf("++++++++++++ft_strdup++++++++++++\n");
	char cpy[] = "hello";
	char *cpyofcpy = ft_strdup(cpy);
	TEST_MEMCMP(cpyofcpy, cpy, 6, "ft_strdup(\"hello\")");
	free(cpyofcpy);
	ft_strlcpy(cpy, "", 100);
	cpyofcpy = ft_strdup(cpy);
	TEST_MEMCMP(cpyofcpy, cpy, 1, "ft_strdup(\"\")");
	free(cpyofcpy);
	ft_strlcpy(cpy, "a\0bcd", 100);
	cpyofcpy = ft_strdup(cpy);
	TEST_MEMCMP(cpyofcpy, cpy, 1, "ft_strdup(\"\")");
	free(cpyofcpy);

	printf("++++++++++++ft_substr++++++++++++\n");
	// if failing, could mean not enough memory -> malloc fail NULL check include then
	TEST_STRCMP(ft_substr("hello world", 0, 5), "hello", "ft_substr(\"hello world\", 0, 5)");
	TEST_STRCMP(ft_substr("hello world", 6, 5), "world", "ft_substr(\"hello world\", 6, 5)");
	TEST_STRCMP(ft_substr("hello world", 1, 3), "ell", "ft_substr(\"hello world\", 1, 3)");
	TEST_STRCMP(ft_substr("hello world", 0, 0), "", "ft_substr(\"hello world\", 0, 0)");
	TEST_STRCMP(ft_substr("hello world", 0, 100), "hello world", "ft_substr(\"hello world\", 0, 100)");
	TEST_STRCMP(ft_substr("hello", 5, 10), "", "ft_substr(\"hello\", 5, 10)");
	TEST_STRCMP(ft_substr("hello", 6, 1), "", "ft_substr(\"hello\", 6, 1)");
	TEST_STRCMP(ft_substr("", 0, 0), "", "ft_substr(\"\", 0, 0)");
	TEST_STRCMP(ft_substr("abc\0def", 0, 7), "abc", "ft_substr(\"abc\\0def\", 0, 7)");
	
	printf("++++++++++++ft_strjoin++++++++++++\n");
	TEST_STRCMP(ft_strjoin("Hello", "World"), "HelloWorld", "ft_substr(\"Hello\", \"World\")");
	TEST_STRCMP(ft_strjoin("", "World"), "World", "ft_substr(\"\", \"World\")");
	TEST_STRCMP(ft_strjoin("", ""), "", "ft_substr(\"\", \"\")");
	TEST_STRCMP(ft_strjoin("A", "B"), "AB", "ft_substr(\"A\", \"B\")");

	printf("++++++++++++ft_strtrim++++++++++++\n");
	TEST_STRCMP(ft_strtrim(" hello ", " "), "hello", "ft_strtrim(\" Hello \", \" \")");
	TEST_STRCMP(ft_strtrim("$$$hello$$$", "$"), "hello", "ft_strtrim(\"$$$hello$$$\", \"$\")");
	TEST_STRCMP(ft_strtrim("..abc..", "."), "abc", "ft_strtrim(\"..abc..\", \".\")");
	TEST_STRCMP(ft_strtrim("xyzabcxyz", "xyz"), "abc", "ft_strtrim(\"xyzabcxyz\", \"abc\")");
	TEST_STRCMP(ft_strtrim("xyzabczyx", "zyx"), "abc", "ft_strtrim(\"xyzabczyx\", \"abc\")");
	TEST_STRCMP(ft_strtrim("xyzabczyxbb", "zyx"), "abczyxbb", "ft_strtrim(\"xyzabczyxbb\", \"abc\")");
	TEST_STRCMP(ft_strtrim("hello", "zyx"), "hello", "ft_strtrim(\"hello\", \"zyx\")");
	TEST_STRCMP(ft_strtrim(".....", "."), "", "ft_strtrim(\".....\", \".\")");
	TEST_STRCMP(ft_strtrim("", "abc"), "", "ft_strtrim(\"\", \"abc\")");
	TEST_STRCMP(ft_strtrim(" ", " "), "", "ft_strtrim(\" \", \" \")");
}
