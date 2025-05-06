
#include "tester_macro.h"
#include "../get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>

int main(void)
{
	int fd1 = open("test1.txt", O_RDONLY);
	int fd2 = open("test2.txt", O_RDONLY);
	int fd3 = open("test3.txt", O_RDONLY);
	int fd4 = open("test4.txt", O_RDONLY);
	char *line;

	printf("0----------test1.txt | simple test----------0\n");
	for (int i = 0; i < 4; i++)
	{
		line = get_next_line(fd1);
		printf("%s", line);
		free(line);
	}

	printf("\n0----------test2.txt | no '\\n' at end----------0\n");
	for (int i = 0; i < 4; i++)
	{
		line = get_next_line(fd2);
		printf("%s", line);
		free(line);
	}

	printf("\n0----------test3.txt | multiple '\\n'----------0\n");
	for (int i = 0; i < 6; i++)
	{
		line = get_next_line(fd3);
		printf("%s", line);
		free(line);
	}

	printf("\n0----------test4.txt | one BIG line----------0\n");
	for (int i = 0; i < 1; i++)
	{
		line = get_next_line(fd4);
		printf("%s", line);
		free(line);
	}
}
