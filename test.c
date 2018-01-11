# include "ft_printf.h"
#include <locale.h>
# include <stdio.h>

int main()
{
	//setlocale(LC_ALL, "");

	int pointer = 42;

	int ft, og;
	og =    printf("|%5.x %5.0x|", 0, 0);
	printf("\n");
	ft = ft_printf("|%5.x %5.0x|", 0, 0);
	printf("\n");

	printf("OG = %d; FT = %d\n", og, ft);
}
