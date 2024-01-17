#include <stdio.h>
#include <stdlib.h>
int main ( )
{
  int deta[10] ;
  for  ( int i = 0;i < 10;i ++)  
  {
    deta[i] = rand( ) % 9 + 1 ;
  }
  for  ( int i = 9;i >= 0;i--)  
  {
    printf ("%d\n",deta[i]);
  }
   return 0;
}