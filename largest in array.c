#include<stdio.h>
#include<stdlib.h>

#define num 3


int main()
{
    int a[num];

    printf("Enter the numbers to array:-\n");
    for (int i =0 ; i < num ; i++)
    {
        scanf("%d",&a[i]);
    }

    int temp =a[0];

    for (int j=0; j<=num;j++)
    {
        if(temp<a[j])
        {
            temp =a[j];
        }
    }

    printf("The largest number = %d",temp);

    return 0;
    
}

