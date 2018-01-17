# include "ft_printf.h"
#include <locale.h>
# include <stdio.h>

int main()
{
	setlocale(LC_ALL, "");

	int a = 0, b = 0;

	a =    printf("%ll#d\n", 9223372036854775807);
	b = ft_printf("%ll#d\n", 9223372036854775807);

	printf("\n%d %d\n", a, b);

}
