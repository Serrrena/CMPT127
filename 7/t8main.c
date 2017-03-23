#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include "list.h"

int main( int argc, char* argv[] )
{
  list_t* list = list_create();
  list_append(list,4);
  list_append(list,9);
  list_append(list,3);
  list_append(list,5);
  list_prepend(list,7);
  list_print(list);
  list_sort(list);
  list_print(list);
  return 0;






}