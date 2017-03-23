#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void draw_rectangle( uint8_t array[], 
	  unsigned int cols, 
	  unsigned int rows, 
	  int x,
	  int y,
	  int rect_width,
	  int rect_height,
	  uint8_t color )
{
	int i,p,q;
	if (rect_width==0 || rect_height==0 )
	{
		exit(0);
	}
	else if (x<rows && x+rect_width< rows && y< cols &&y+rect_height< cols)
	{
		for (i=0;i<rows*cols;i++)
		{
				if (i==x+cols*y && rect_width >0 && rect_height >0)
				{
					for (p=0;p<rect_height;p++)
					{
						if(p==0)
						{
							for (q=0;q<rect_width;q++)
							{
								array[x+q+cols*(y+p)]=color;
							}
						}
						else if (p==rect_height-1)
						{
							for (q=0;q<rect_width;q++)
							{
								array[x+q+cols*(y+p)]=color;
							}
						}
						else
						{
							array[x+cols*(y+p)]=color;
							array[x+rect_width-1+cols*(y+p)]=color;
						}
						
					}
					break;
				}
				else if (i==x+cols*y && rect_width >0 && rect_height <0)
				{
					for (p=0;p>rect_height;p--)
					{
						if(p==0)
						{
							for (q=0;q<rect_width;q++)
							{
								array[x+q+cols*(y+p)]=color;
							}
						}
						else if (p==rect_height+1)
						{
							for (q=0;q<rect_width;q++)
							{
								array[x+q+cols*(y+p)]=color;
							}
						}
						else
						{
							array[x+cols*(y+p)]=color;
							array[x+rect_width+1+cols*(y+p)]=color;
						}
						
					}
					break;
				}
				else if (i==x+cols*y && rect_width <0 && rect_height >0)
				{
					for (p=0;p<rect_height;p++)
					{
						if(p==0)
						{
							for (q=0;q>rect_width;q--)
							{
								array[x+q+cols*(y+p)]=color;
							}
						}
						else if (p==rect_height-1)
						{
							for (q=0;q>rect_width;q--)
							{
								array[x+q+cols*(y+p)]=color;
							}
						}
						else
						{
							array[x+cols*(y+p)]=color;
							array[x+rect_width-1+cols*(y+p)]=color;
						}
						
					}
					break;
				}
				else if (i==x+cols*y && rect_width <0 && rect_height <0)
				{
					for (p=0;p>rect_height;p--)
					{
						if(p==0)
						{
							for (q=0;q>rect_width;q--)
							{
								array[x+q+cols*(y+p)]=color;
							}
						}
						else if (p==rect_height+1)
						{
							for (q=0;q>rect_width;q--)
							{
								array[x+q+cols*(y+p)]=color;
							}
						}
						else
						{
							array[x+cols*(y+p)]=color;
							array[x+rect_width-1+cols*(y+p)]=color;
						}
						
					}
					break;
				}
		}
	}
	else{
		exit(0);
	}
	
	

}