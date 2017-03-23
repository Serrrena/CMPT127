#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> 
#include <string.h>
#include <math.h>
int fxy(int k,int limit)          // use this function to determin the location of the nearby pixels of image.
                                  //(else if used to find the border pixels)
{    
	if (k>=0 && k<=limit-1)
	{
		return k;
	}
	else if (k<0)
	{
		return limit-1;
	}
	else if (k>limit-1)
	{
		return 0;
	}
}

void life( uint8_t array[], 
     unsigned int cols, 
     unsigned int rows )
{
	int i,count,m,n,x,y;
	int checkarr[rows*cols];     //create a new array to store the num of count.
	int a[3]={-1,0,1};
	for(i=0;i<rows*cols;i++)
	{
		count=0;
		for (m=0;m<3;m++)
		{
			x=fxy(i%cols+a[m],cols);
			for (n=0;n<3;n++)
			{
				y=fxy(i/cols+a[n],rows);
				if (array[y*cols+x]==255)
				{
					count++;
				}
			}
		}
		checkarr[i]=count;
		
	}
	for(i=0;i<rows*cols;i++)
	{
		if(array[i]==255)
		{
			if (checkarr[i]!=3 && checkarr[i]!=4)  // As the rule required a livel pixel got 2 or 3 live pixel.
			{                                          // we use 3 or 4 as the count counted array[i] itself, so +1
				array[i]=0;
			}			
		}
		else 
		{
			if (checkarr[i]==3)
			{
				array[i]=255;
			}
		}
	}
	
}
	
