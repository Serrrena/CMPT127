#include <stdio.h>
#include <math.h>

int main( void)
{
	float a;
	int b;
	int c;
	int d;
	int k;
	while ( scanf("%f", &a)!=-1)
	{
	       
               b= floor(a);
               c= round(a);
               d = ceil(a);
               printf("%d %d %d\n",b,c,d);
	        	      
         
	}
	printf("Done.\n");

	return 0;
}
	

	

