//T8:
if (cols%2!=0)
  {
    cols=cols-1;
  }
  else if (rows%2!=0)
  {
    rows=rows-1;
  }
  int i,j,a,b;
  int k=0,sum=0;
  
  uint8_t* new=malloc(sizeof(uint8_t)*(cols/2)*(rows/2));
  for (i=0;i<cols-1;i+=2)
  {
    for (j=0;j<rows-1;j+=2)
    {

      for (a=0;a<2;a++)
      {
        for (b=0;b<2;b++)
        {
          sum+=array[(i+a)*cols+j+b];
        }
      }
      new[k]=round(sum/(float)4);
      k++;
      sum=0;
    }
  }
  return new;
//T9:
void region_set( uint8_t array[], 
         unsigned int cols, 
         unsigned int rows,
         unsigned int left,
         unsigned int top,
         unsigned int right,
         unsigned int bottom,
         uint8_t color )
{
    // your code here
  int i,j;
  for (i=0;i<rows;i++)
  {
    for (j=0;j<cols;j++)
    {
      if (i>=top-1 && i<bottom-1)
      {
        if (j>=left-1 && j<right-1)
        {
          array[i*cols+j]=color;
        }
      }
    }
  }
}

//T10:
int i,j,sum;
  for (i=0;i<rows;i++)
  {
  	if (left==right || top==bottom)
    {
      
      sum=0;
      break;
    }
    for (j=0;j<cols;j++)
    {
      if (i>=top-1 && i<bottom-1)
      {
        if (j>=left-1 && j<right-1)
        {
          sum+=array[i*cols+j];
        }
      }
    }
  }
  return sum;

  //T11
  int i,k=0;
  uint8_t* regcopy=malloc( sizeof(uint8_t)*(right-left)*(bottom-top));
  if (regcopy == NULL)
  {
    return NULL;
  }
  
  else 
  {
    for (i=0;i<rows;i++)
    {
      for (j=0;j<cols;j++)
      {
        if (i>=top-1 && i<bottom-1 )
        {
          if (j>=left-1 && j<right-1 )
          {
            regcopy[k]=array[i*cols+j];
            k++;
          }
        }
      }
    }
    
    return regcopy;
  }
