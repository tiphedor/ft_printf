# include "ft_printf.h"
#include <locale.h>
# include <stdio.h>

int main()
{
	setlocale(LC_ALL, "");

	int a = 0, b = 0;

	a =    printf("|%02.d|%02.0d|\n", 0, 0);
	b = ft_printf("|%02.d|%02.0d|\n", 0, 0);

	printf("\n%d %d\n", a, b);

}
