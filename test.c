# include "ft_printf.h"
#include <locale.h>
# include <stdio.h>

int main()
{
	setlocale(LC_ALL, "");

	int a = 0, b = 0;

	a =    printf("%8C et coco %C titi %lc|\n", 3250, 0x11ffff, 'a');
	b = ft_printf("%8C et coco %C titi %lc|\n", 3250, 0x11ffff, 'a');

	printf("\n\nOG = %d; FT = %d\n", a, b);



}
