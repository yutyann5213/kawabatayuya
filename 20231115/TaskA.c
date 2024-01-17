#include<stdio.h>
#include<time.h>

int main()
{
    int data[] = {0,1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(data)/sizeof(data[0]);
    for (int i = n -1 ; i > 0 ; i--)
    {
        int j = rand() % (i + 1);

        int temp = data[i];
        data[i] = data[j];
        data[j] = temp;
    }
    for(int i=0;i<=data[i];++i)
    {
        int result=-1;
        int target=5;
        if(data[i]==target)
        {
            result=i;
        }
    }
     printf("index of target is result");
    return 0;
}