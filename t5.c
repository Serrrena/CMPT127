#include <stdio.h>
#include <math.h>

int main( void )
{
	int b;
	int c;
	int d;
	float a;
	int k;
	k=scanf( "%f", &a );
	while ( a!=EOF )
	{
	  	if (k==1)
		{
			b= floor(a);
		    c= round(a);
			d = ceil(a);
			printf("%d %d %d\n",b,c,d);	
		}  	
		else
		{

		}

		k=scanf("%f", &a);
	}
	printf("Done.\n");
	
	return 0;
}
