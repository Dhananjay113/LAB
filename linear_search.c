#include<stdio.h>

#define num 3

int main()
{
    int a[num], to_ser, i;

    printf("Enter the array :-\n");
    for (i = 0; i < num; i++)
    {
        scanf("%d",&a[i]);
    }

    printf("Enter the number to search : ");
    scanf("%d",&to_ser);

    for(i=0;i<num;i++)
    {
        if(to_ser == a[i])
        {
            printf("%d is found in index %d",to_ser,i);
        }
    }
    return 0;
}