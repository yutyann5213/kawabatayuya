#include<stdio.h>
#include <stdlib.h>

int main()
{
    int data[100];
    for(int i=0;i<100;i++)
    {
        data[i] = rand( ) % 99 + 1 ;
    }

    for(int i=0;i<data[i];++i)
    {
        for(int j=data[i]-1;j>=i+1;--j);
        {
            int valueA=data[i];
            int valueB=data[i+1];

            if(valueA>valueB)
            {
                int max=valueA;
                int min=valueB;
            }
        }
    }

    return 0;
}