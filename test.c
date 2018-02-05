# include "ft_printf.h"
#include <locale.h>
# include <stdio.h>

int main()
{
	setlocale(LC_ALL, "");

	int a = 0;

	a = ft_printf("%#b", 42);
	printf("\n\n%d\n", a);


}
