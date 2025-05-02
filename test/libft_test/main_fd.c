
#include "tester_macro.h"
#include "../libft/libft.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
	ft_putstr_fd("++++++++++++ft_putchar_fd++++++++++++\n", 1);
	ft_putstr_fd(GREEN" [PASS]"RESET" ft_putchar_fd('c', 1) : ", 1); ft_putchar_fd('c', 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("++++++++++++ft_putstr_fd++++++++++++\n", 1);
	ft_putstr_fd(GREEN" [PASS]"RESET" ft_putstr_fd(\"hello\", 1) : ", 1); ft_putstr_fd("hello", 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("++++++++++++ft_putendl_fd++++++++++++\n", 1);
	ft_putstr_fd(GREEN" [PASS]"RESET" ft_putendl_fd(\"hello\", 1) : ", 1); ft_putendl_fd("hello", 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("++++++++++++ft_putnbr_fd++++++++++++\n", 1);
	ft_putstr_fd(GREEN" [PASS]"RESET" ft_putnbr_fd(-54920, 1) : ", 1); ft_putnbr_fd(-54920, 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd(GREEN" [PASS]"RESET" ft_putnbr_fd(54920, 1) : ", 1); ft_putnbr_fd(54920, 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd(GREEN" [PASS]"RESET" ft_putnbr_fd(-0, 1) : ", 1); ft_putnbr_fd(0, 1);
	ft_putchar_fd('\n', 1);
}