#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main( int argc, char *argv[] )
{
    char *s;
    char *a = argv[1];
    char *b = argv[2];    
    s = strstr(a, b);
    
    if (s != NULL)
    {
    	printf("true\n");
    }
    else 

    {
    	printf("false\n");
    }
    
    return 0;
}