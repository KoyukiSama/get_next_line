
#include "tester_macro.h"
#include "../get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>

int main(void)
{
	int fd = open("file.txt", O_RDONLY);

	char *line;

	for (int i = 0; i < 7; i++)
	{
		line = get_next_line(0);
		printf("\nread: %s\n", line);
		free(line);

		line = get_next_line(fd);
		printf("\nread: %s\n", line);
		free(line);
	}
}
