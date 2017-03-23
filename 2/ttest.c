#include <stdio.h>

int main( )
{

  
  int num=25;
  long int **ptr = &num;
  printf("num = %d\n",num);
  printf("ptr = %p\n",ptr);
  return 0;
}