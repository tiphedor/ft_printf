# include "ft_printf.h"
#include <locale.h>
# include <stdio.h>

int main()
{
	//setlocale(LC_ALL, "");

	int pointer = 42;

	int ft, og;
	og =    printf("{%c}", '\0');
	printf("\n");
	ft = ft_printf("{%c}", '\0');
	printf("\n");

	printf("OG = %d; FT = %d\n", og, ft);
}
