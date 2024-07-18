#include <limits.h>
#include <stdio.h>
#include "ft_printf.h"

void test_text(void)
{
	printf("::: %d\n", ft_printf("%c, %c, %c", 'a', '\n', '%'));
	printf("::: %d\n", printf("%c, %c, %c", 'a', '\n', '%'));
	printf("::: %d\n", ft_printf("\n"));
	printf("::: %d\n", printf("\n"));
	printf("::: %d\n", ft_printf("%s, %s, %s", "a", "\n", "%"));
	printf("::: %d\n", printf("%s, %s, %s", "a", "\n", "%"));
	printf("::: %d\n", ft_printf("\n"));
	printf("::: %d\n", printf("\n"));
	printf("::: %d\n", ft_printf("%s, %s, %s", "asdaf", "jump\njumped", "hello%"));
	printf("::: %d\n", printf("%s, %s, %s", "asdaf", "jump\njumped", "hello%"));
	printf("::: %d\n", ft_printf("\n"));
	printf("::: %d\n", printf("\n"));
	printf("::: %d\n", ft_printf("%s, %s, %s", "cut\0ed", (char *) NULL, "\0"));
	printf("::: %d\n", printf("%s, %s, %s", "cut\0ed", (char *) NULL, "\0"));
	printf("::: %d\n", ft_printf("\n"));
	printf("::: %d\n", printf("\n"));
}

void test_numbers(void)
{
	printf("::: %d\n", ft_printf("%d, %d, %d \n", 42, 0, -42));
	printf("::: %d\n", printf("%d, %d, %d \n", 42, 0, -42));
	printf("::: %d\n", ft_printf("%d, %d\n", INT_MAX, INT_MIN));
	printf("::: %d\n", printf("%d, %d\n", INT_MAX, INT_MIN));
	printf("::: %d\n", ft_printf("%u, %u\n", INT_MAX, INT_MIN ));
	printf("::: %d\n", printf("%u, %u\n", INT_MAX, INT_MIN ));
	//printf("%u, %u\n", INT_MAX, INT_MIN );
	//jft_printf("%u\n", UINT_MAX);
	//jprintf("%u\n", UINT_MAX);
	//jft_printf("%d\n", UINT_MAX -2);
	//jprintf("%d\n", UINT_MAX -2);
}

void test_ex(void)
{
	int x = 3;
	(void) x;
	ft_printf("%x %x %X", 123, 567,12136);
//	printf("%d\n", ft_printf("%X, %X, %X , %X, %X, %X, %X, %X\n", 255, 1, 2, 4, 8, 16, 32, 64));
	//printf("%d\n", ft_printf("%p \n", &x));
	//printf("%d\n", ft_printf("%p \n", NULL));
}
//0x602000000030
int main(void)
{
//	test_text();
//	test_numbers();
	test_ex();
/*	int a;
	int b;
	a = ft_printf("%10s awdawd %d asd %x", "patata", 14, 3);
	b = printf("%p", NULL);
	printf("retorno de ft es: %d\n", a);
	printf("retorno de original es: %d\n", b);
*/}
