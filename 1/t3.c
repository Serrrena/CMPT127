#include <stdio.h>
#include <math.h>

int main( void )
{
	int b;
	int c;
	int d;
	float a;

	scanf( "%f", &a );
	b= floor(a);
	c= round(a);
	d = ceil(a);
	printf("%d %d %d\n",b,c,d);
	return 0;
}

