
#include <stdio.h>
int main( )
{
    char c;
    unsigned long int charcount=0;
	unsigned long int wordcount=0;
  	unsigned long int linecount=0;
    int word=1;
    while( (c=getchar())!= EOF )  //从控制台流中读取字符，直到按回车键结束
    {    
    	charcount=charcount+1;
    	if (c=='\n')
    	{
    		linecount=linecount+1;
        	word=1;
    	}
    	
    	else if ((c>='a' && c<='z')||(c>='A' && c<='Z')||c=='\'')
    	{
    		
    		if (word==1)
    		{
    			wordcount=wordcount+1;
    			word=0;
    		}
    		
    	}
		else
		{
			word=1;
		}
    	
    }	
    printf( "%lu %lu %lu\n", charcount, wordcount, linecount ); 
    return 0; 		
}		
