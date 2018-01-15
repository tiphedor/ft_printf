# include "ft_printf.h"
#include <locale.h>
# include <stdio.h>

int main()
{

	wchar_t	s[4];

	s[0] = 0x53;
	s[1] = 0x3abc;
	s[2] = 0x81000;
	s[3] = '\0';



	setlocale(LC_ALL, "");

	int a = 0, b = 0;

	a =    printf("%7.9S|\n", 0);
	b = ft_printf("%7.9S|\n", 0);

	printf("\n%d %d\n", a, b);










}
