#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include "list.h"

int main( int argc, char* argv[] )
{
  list_t* list = list_create();
  list_t* l1=list_create();
  list_t* l2=list_create();
  element_t* n1=list_index(l1,1);
  if (n1!=NULL)     //t1
  {
    return 1;
  }

  for( int i=0; i<5; i++ )    
    list_append( list, i );
  
  for( int i=-1; i>-5; i-- )
    list_prepend( list, i );
  
  list_print( list );

  list_prepend(l2,5);      //t4
  if(l2->tail->val!=5)
  {
    return 1;
  }
  //printf("1\n");

  int index = 2;
  int k = 0;//t3
  element_t* el = list_index( list, index );
  element_t* n3 = list_index( list, k );   //t3
  //printf("2\n");     
  element_t* n6 = list_index( list, 11);     //t6
  //printf("3\n");
  if( el == NULL )
    {
      printf( "index %d not found\n", index );
      return 1; // fail
    }
  if (n3->val!=-4)      //t3 check for list_index when index=0
  {
    return 1;
  }
  if (n6!=NULL)      // t6 check when index for list_index > than list
  {
    return 1;
  }
  printf( "value at index %d is %d\n", index, el->val );
  element_t *n2=element_create(5);      // t2
  free(n2); 
  element_t *nn2=element_create(2);
  printf("%d\n",n2->val);
  if (n2==nn2)
  {
    return 4;
  }
  /*n2->next=nn2;
  free(n2); 
  n2=element_create(5);  
  if (n2->next != NULL)
  {
    return 1;
  }*/

  if( el->val != -2 ) 
    return 1;
  
  list_destroy( list );
  list_destroy( l1 );
  return 0; // tests pass
}
