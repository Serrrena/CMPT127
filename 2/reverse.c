
void reverse( int a[], unsigned int len )
{
  int tmp;

  int i=0;
  
  int j=1;

  //this is for even number values in array

  if (len%2==0)
  {
    for(i=0; i<len/2; i++ )

    {
        tmp=a[i];

        a[i]=a[len-j];

        a[len-j]=tmp;

        j=j+1;
    }

  }

  else    //this is for odd number values in array 

  {

    for( i=0; i<(len-1)/2; i++ )

    {
        tmp=a[i];

        a[i]=a[len-j];

        a[len-j]=tmp;

        j=j+1;

    }

  }
}

