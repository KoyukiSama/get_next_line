
#include "tester_macro.h"
#include "../libft/libft.h"
#include "../libft/libft_bonus.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

static void ft_touppercase(unsigned int i, char *c)
{
	(void) i;
	*c = (char) ft_toupper((int) *c);
}

void f1(void *content)
{
	char *s = (char *) content;
	ft_striteri(s, ft_touppercase);
}

static char ft_touppercase_char(unsigned int i, char c)
{
	(void) i;
	return((char) ft_toupper((int) c));
}

void *f1_mapi(void *content)
{
	char *s = (char *) content;
	return(ft_strmapi(s, ft_touppercase_char));
}

static void ft_tolowercase(unsigned int i, char *c)
{
	(void) i;
	*c = (char) ft_tolower((int) *c);
}

void f2(void *content)
{
	char *s = (char *) content;
	ft_striteri(s, ft_tolowercase);
}

// void *f2_mapi(void *content)
// {
// 	char *s = (char *) content;
// 	return(ft_strmapi(s, ft_tolowercase));
// }

int main(void)
{
	t_list *lst;

	lst = ft_lstnew(ft_strdup("START"));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("hii")));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("I")));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("SHOULD")));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("REALLY see front (^-. -^)S")));
	ft_lstadd_front(&lst, ft_lstnew(ft_strdup("TAKE")));
	ft_lstadd_front(&lst, ft_lstnew(ft_strdup("A")));
	ft_lstadd_front(&lst, ft_lstnew(ft_strdup("... break ... I'm hungry :<")));
	printf(GREEN"[PASS] "RESET"ft_lst## new() && add_front() && add_back()\n"); lst_printer(lst);
	
	printf(GREEN"[PASS] "RESET"ft_lstsize() "); printf("%i\n", ft_lstsize(lst));
	printf(GREEN"[PASS] "RESET"ft_lstlast() "); printf("LAST: [ %s ]\n", (char *) ft_lstlast(lst)->content);
	ft_lstiter(lst, f1);
	lst_printer(lst);
	ft_lstiter(lst, f2);
	lst_printer(lst);
	printf(GREEN"[PASS] "RESET"ft_lstiter(UPPER, LOWER) \n");
	t_list *prev = lst->next->next;
	t_list *to_del = prev->next;
	prev->next = to_del->next;
	ft_lstdelone(to_del, free);
	printf(GREEN"[PASS] "RESET"ft_lstdelone( node [ \"start\" ] ) \n"); lst_printer(lst);
	t_list *LIST2_YAYYY = ft_lstmap(lst, f1_mapi, free);
	printf(GREEN"[PASS] "RESET"ft_lstmapi(UPPER) \n"); lst_printer(LIST2_YAYYY);
	ft_lstclear(&lst, free);
	ft_lstclear(&LIST2_YAYYY, free);
	printf(GREEN"[PASS] "RESET"ft_lstclear(lst and mapped lst) \n"); lst_printer(lst); lst_printer(LIST2_YAYYY);
}


