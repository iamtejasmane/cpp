#include<stdio.h>

namespace na
{
	int num1 = 10;
	int num3 = 30;
}
namespace nb
{
	int num2 = 20;
	int num3 = 40;
}
int main( void )
{
	printf("Num1	:	%d\n", na::num1);
	printf("Num3	:	%d\n", na::num3);

	printf("Num2	:	%d\n", nb::num2);
	printf("Num3	:	%d\n", nb::num3);
	return 0;
}
