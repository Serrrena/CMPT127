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
	if (k==1)
	{
	  	b= floor(a);
	    c= round(a);
		d = ceil(a);
		printf("%d %d %d\n",b,c,d);	
	}
    else
    {
    	printf("scanf error: (%d)\n",k);
    }
	
	return 0;
}
