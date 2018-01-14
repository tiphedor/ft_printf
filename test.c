# include "ft_printf.h"
#include <locale.h>
# include <stdio.h>

int main()
{
	setlocale(LC_ALL, "");

	ft_printf("|%c|", '\0');
	ft_printf("|%c|", '\0');
}
