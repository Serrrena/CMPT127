#include <stdio.h>


int main( void)

{
	int i=0;
	int j=1;
	int a;	
	int b;
	int h;	
	
	scanf("%d", &a);
	scanf("%d", &h);
	scanf("%d", &b);
	for (i=0;i<=a-1;i++)
	{
		printf("#");
		
	}
	printf("\n");
	i=0;
		
	for  (j=1;j<h-1;j++)
	{
		 
		for (i=0;i<=a-1;i++)
		
		{
				
			
				printf("#");
				
				for (i=1;i<=a-2;i++)
				{
					printf(".");
				}
				if (i=a-1)
				{
					printf("#");	
				}		
		}		
		printf("\n");
		i=0;		
	}		
	if (j=h-1)
	{
		for (i=0;i<=a-1;i++)
		{
			printf("#");
			
		}
		printf("\n");
	}	
  	return 0;
}