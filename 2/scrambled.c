int scrambled( unsigned int a[], unsigned int b[], unsigned int len )
{
	unsigned int i=0;
	unsigned int j=0;
	if (len==0)
	{
		return 1;
	}
	for (i=0;i<=len-1;i++)
	{
		j=0;
		for (j=0;j<=len-1;j++)
		{
			if (a[i]==b[j])
			{
				b[j]=100;
				break;
			}
		}
		
	}
	i=0;	
	for (i=0;i<=len-1;i++)
	{
			if (b[i]!=100)
			return 0;
	}
	return 1;
}