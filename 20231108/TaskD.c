#include<stdio.h>

int main()
{
    int i;
    for(i=0;i<=100;++i)
    {
        int FizzBuzz = i % 15;
        int Fizz = i % 3;
        int Buzz = i % 5;

        if(FizzBuzz == 0 && i != 0)
        {
            printf("FizzBuzz: %d\n",i);
        }
        else if (Fizz == 0 && i != 0)
        {
            printf("Fizz: %d\n",i);      
        }
        else if(Buzz == 0 && i != 0)
        {
            printf("Buzz: %d\n",i);
        }
    }
}