int identical( int a[], int b[], unsigned int len )
{	
	unsigned int i=0;
	if (len==0)
    {
    	return 1;
    }
    for( unsigned int i=0; i<len; i++ )
    {
      
      if( a[i]!=b[i] )
      {
		return 0;
      }
    }
    if (i=len)
    {
    	if (a[len-1]==b[len-1])
    	{
    		return 1;
    	}
    }
    return 0;
}

