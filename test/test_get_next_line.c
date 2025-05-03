
#include "tester_macro.h"
#include "../get_next_line.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	char *line = get_next_line(0);
	printf("read: ", line);
	
	free(line);
}
