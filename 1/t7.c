#include <stdio.h>
#include <string.h>

int main( void)

{
	int i=1;
	int j=0;
	int row=0;	
	int logo[1000];
	int a;	
	
	while ( scanf("%d", &a)!=-1)

	{
		logo[row]=a;
		row = row+1;
	}
		
	for  (j=0;j<row;j++)
	{
		for (i=0;i<logo[j];i++)
		
		{
				printf("#");

		}		
		printf("\n");		
	}		
	
  	return 0;
}