#include <stdio.h>
#include <math.h>

int main( void )

{
	int i=0;
	int j=1;
	int w;	
	int b;
	int h;
	


	int left;
	
	
	
	scanf("%d", &w);
	scanf("%d", &b);
	scanf("%d", &h);	
 	
	left=floor((w*h-w*j)/(2*h));
 	
	for(i=0;i<=left-1;i++)
	{
		printf(" ");
	}
	
	for (i=left;i<=w-left-1;i++)
	{

		printf("#");		
	}
	printf("\n");
	
	j=2;
	
	for  (j=2;j<=h-1;j++)
	{
		left=floor((w*h-w*j)/(2*h));
		
		i=0;
		for(i=0;i<=left-1;i++)
		{
			printf(" ");
		}
						
		printf("#");
		i=1;
		for (i=1;i<=w-2*left-2;i++)
		{
			printf(".");
		}
				
		printf("#");	
										
		printf("\n");
				
	}
			
	if (h>1)
	{
		i=1;
		for (i=1;i<=w;i++)
		{
			printf("#");
			
		}
		printf("\n");
	}	
	
  	return 0;
}
