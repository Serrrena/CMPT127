#include <stdio.h>
#include <math.h>

int main( void)
{
	float a;
	float b;
	float small;
	float big;
	float mean;
	float sum;
	int count;
	
	mean=0;
	
	int k=scanf("%f",&a);


	small=a;
	sum=a;
	big=a;
	count=1;
	while ( scanf("%f", &a)!=-1)
	{
    
	    if ( a>=big )
	    {
	    	big=a;	
	    	    			    	
	    }   
	    else if ( a<=small )
	    {
	    	small=a;
	    	  
	    }
	    
	    count=count+1;
	   
	          
	    sum=sum+a;		    
	}
	
	mean=sum/count;
	printf("%.2f %.2f %.2f\n",small,big,mean);
		
  	return 0;
}

