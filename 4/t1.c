#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void draw_circle( uint8_t img[], 
    unsigned int cols,
    unsigned int rows,
    int x,
	int y,
	int r,
	uint8_t color )
{
	int i,j;
	
	if (r=0)
	{
		exit(0);	
	}
	else if ( x>0 && y>0 && x<cols && y<rows)
	{
		for (i=0;i<rows;i++)
		{		
			for (j=0;j<cols;j++)
			{
				if(round((float)sqrt((x-j)*(x-j)+(y-i)*(y-i)))<r )
				{
					img[i*cols+j]=color;
				}
			}
		}		
	}
	else
	{
		exit(0);
	}	
	
}