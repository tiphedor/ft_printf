# include "ft_printf.h"
#include <locale.h>
# include <stdio.h>

int main()
{
	setlocale(LC_ALL, "");

	int a = 0, b = 0;

	a =    printf("%-8s;\n", 0);
	b = ft_printf("%-8s;\n", 0);
	printf("\n%d\n", b);










}
