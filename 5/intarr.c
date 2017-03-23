#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
//#include "intarr.h"
typedef struct {
  int* data;
  unsigned int len;
} intarr_t;

// A type for returning status codes 
typedef enum {
  INTARR_OK,
  INTARR_BADARRAY,
  INTARR_BADINDEX,
  INTARR_BADALLOC,
  INTARR_NOTFOUND
} intarr_result_t;

//task 1
// Create a new intarr_t with initial size len.  If successful
// (i.e. memory allocation succeeds), returns a pointer to a
// newly-allocated intarr_t.  If unsuccessful, returns a null pointer.
intarr_t* intarr_create( unsigned int len )
{    
    intarr_t *arr=malloc(sizeof(intarr_t));
    if (arr == NULL)
    {
        return NULL;
    }
    arr->len=len;
    arr->data=malloc(sizeof(int)*arr->len);
    return arr;
    
}

// frees all memory allocated for ia. If the pointer is null, do
// nothing. If the ia->data is null, do not attempt to free it.
void intarr_destroy( intarr_t* ia )
{
    if (ia != NULL)
    {
        free(ia);
    }
}

/* LAB 5 TASK 2 */

// If index is valid, set the value at ia->data[index] to val and return
// INTARR_OK. Otherwise, leave the array unmodified and return
// INTARR_BADINDEX. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_set( intarr_t* ia,
                           unsigned int index,
                           int val )
{
    if (ia == NULL)
    {
        return INTARR_BADARRAY;
    }
    else if (index < ia->len)
    {
        ia->data[index] = val;
        return INTARR_OK;
    }
    else
    {
        return INTARR_BADINDEX;
    }
}

// If index is valid and i is non-null, set *i to ia->data[index] and return
// INTARR_OK. Otherwise no not modify *i and return
// INTARR_BADINDEX. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_get( const intarr_t* ia,
                           unsigned int index,
                           int* i )
{
    if (ia == NULL)
    {
        return INTARR_BADARRAY;
    }
    else if (index<ia->len && i != NULL)
    {
        *i = ia->data[index];
        return INTARR_OK;
    }
    else
    {
        return INTARR_BADINDEX;
    }
}



/* LAB 5 TASK 3 */

// Return a duplicate of ia, allocating new storage for the duplicate
// data (we call this a "deep copy"). If unsuccessful (i.e. memory
// allocation for the copy fails, or ia is null), return a null pointer.
intarr_t* intarr_copy( const intarr_t* ia )
{
    intarr_t *duplicate=malloc(sizeof(intarr_t));
    if (duplicate==NULL)
    {
        return NULL;
    }
    duplicate->len=ia->len;
    duplicate->data=malloc(sizeof(int)*duplicate->len);
    //memcpy(duplicate->data, ia->data, ia->len*sizeof(int));
    int i;
    for (i=0;i<ia->len;i++)
    {
        duplicate->data[i]=ia->data[i];
    }
    return duplicate;
}


/* LAB 5 TASK 4 */

// sort ia by value smallest-to-largest, so that data[i] < data[i+1]
// for all valid i, then return INTARR_OK. Works in-place: contents of
// ia are sorted on return. If ia is null, return
// INTARR_BADARRAY.
intarr_result_t intarr_sort( intarr_t* ia )
{
    if (ia==NULL)
    {
        return INTARR_BADARRAY;
    }
    else
    {
        int i,k,min,minpos,tmp;
        min=ia->data[0];
        for (i=0;i<ia->len;i++)
        {
            min = ia->data[i];
            for (k=i;k<ia->len;k++)
            {
                if (ia->data[k]<=min)
                {
                    min=ia->data[k];
                    minpos=k;
                }
            }
            tmp=ia->data[i];
            ia->data[i]=min;
            ia->data[minpos]=tmp;
        }
        return INTARR_OK;
    }
}


/* LAB 5 TASK 5 */

// Find the first occurance of the target in the array, searching from
// index 0. If the target is found and i is non-null, set *i to the
// location index and return INTARR_OK. If target does not occur in
// the array, leave *i unmodified and return INTARR_NOTFOUND. If ia is
// null, return INTARR_BADARRAY.
intarr_result_t intarr_find( intarr_t* ia, int target, int* i )
{
    if (ia == NULL)
    {
        return INTARR_BADARRAY;
    }
    int k;
    for (k = 0;k < ia->len;k++)
    {
        if (ia->data[k] == target && i != NULL)
        {
            *i = k;
            //printf("value of location index %d\n",k);
            //printf("value of new i %d\n",*i);
            return INTARR_OK;
        }
    }
    return INTARR_NOTFOUND;
}

/* LAB 5 TASK 6 */

// Append val to the end of ia (allocating space for it). If
// successful, return INTARR_OK, otherwise return
// INTARR_BADALLOC. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_push( intarr_t* ia, int val )
{
    if (ia==NULL)
    {
        return INTARR_BADARRAY;
    }
    int tmp_len = ia->len+1;
    ia->len = tmp_len;
    //郊区
    //    int *new_data = malloc(sizeof(int)*ia->len);
    //市中心
    int *new_data = realloc(ia->data, sizeof(int)*ia->len);
    if(new_data){
        //        int k;
        //        for (k=0;k<tmp_len-1;k++)
        //        {
        //            new_data[k]=ia->data[k];
        //        }
        new_data[tmp_len-1] = val;
        ia->data = new_data;
        return INTARR_OK;
    }else{
        return INTARR_BADALLOC;
    }
}

// If the array is not empty, remove the value with the highest index
// from the array, and, if i is non-null, set *i to the removed value,
// then return INTARR_OK. If the array is empty, leave *i unmodified
// and return INTARR_BADINDEX. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_pop( intarr_t* ia, int* i )
{
    if (ia == NULL)
    {
        return INTARR_BADARRAY;
    }
    
    if (ia->data[0] == 0 && ia->len == 0)
    {
        return INTARR_BADINDEX;
    }
    // IF i IS NULL, LEAVE i unchanged
    if (i!=NULL ){
        *i = ia->data[ia->len-1];
        ia->data[ia->len-1] = 0;
        ia->len = ia->len-1;
        return INTARR_OK;
    }
    return INTARR_BADINDEX;
}

/* LAB 5 TASK 7 */

// Resize ia to contain newlen values. If newlen is less than the
// original array length, the end of the array is discarded. If newlen
// is greater than the original array length, intialize all the new
// integers to zero. If the allocation is successful, return
// INTARR_OK, otherwise return INTARR_BADALLOC. If ia is null, return
// INTARR_BADARRAY.
intarr_result_t intarr_resize( intarr_t* ia, unsigned int newlen )
{
    if (ia == NULL)
    {
        return INTARR_BADARRAY;
    }
    int i,original_len;
    //printf("%d",ia->len);
    original_len = ia->len;
    if (newlen >= 0)
    {
        int *new_resize_data = realloc(ia->data,sizeof(int)*newlen);
        ia->len = newlen;
        ia->data = new_resize_data;
        if (new_resize_data)
        {
            //printf("before3\n");
            if (newlen>original_len)
            {
                for (i = original_len;i < newlen;i++)
                {
                    ia->data[i] = 0;
                }
            }
            //printf("before4\n");
        }        
        return INTARR_OK;
    }
    return INTARR_BADALLOC;
}


/* LAB 5 TASK 8 */

// Get a deep copy of a portion of ia from index first to index last
// inclusive. If successful, return a pointer to a newly-allocated
// intarr_t containing a copy of the specfied section. If an error
// occurs, i.e. ia is null, first or last are out of bounds, last <
// first, or memory allocation fails, return a null pointer.
intarr_t* intarr_copy_subarray( intarr_t* ia,
                               unsigned int first,
                               unsigned int last )
{
    if (ia == NULL || first > ia->len || last > ia->len || last < first)
    {
        return NULL;
    }
    intarr_t *duplicate_subarray = malloc(sizeof(intarr_t));
    if (duplicate_subarray == NULL)
    {
        return NULL;
    }
    if (first <= last && duplicate_subarray != NULL )
    {
        int i,k = 0,newlen = last-first+1;
        duplicate_subarray->len = newlen;
        duplicate_subarray->data = malloc(sizeof(int)*newlen);
        for (i = first;i <= last;i++)
        {
            duplicate_subarray->data[k] = ia->data[i];
            k++;
        }
        return duplicate_subarray;
    }
    return NULL;    
}
