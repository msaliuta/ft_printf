#include "inc/ft_printf.h"
#include <stdio.h>
#define STR "%q", 50
int main(){
	int ret1;
	int ret2;

	char	*s;
	int d;

	d = -10899798;
	s = "Hello";
	ret1 = ft_printf(STR);
	// ret2 = printf(STR);
	// printf("\n MY: %d | OR: %d\n", ret1, ret2 );
	system("leaks -q a.out");
	return (0);
}
