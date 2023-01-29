#include<stdio.h>

int main()
{
    int a,b,c;

    while(1)
    {
        printf("\n");

        printf("Enter value a: ");
        scanf("%d",&a);

        printf("Enter value b: ");
        scanf("%d",&b);

        printf("Enter the operation to purform \n1.ADD\n2.SUB\n3.MUL\n4.DIV\nChoice : ");
        scanf("%d",&c);

        switch (c)
        {
        case 1:
            printf("%d",a+b);
            break;
        case 2:
            printf("%d",a-b);
            break;
        case 3:
            printf("%d",a*b);
            break;
        case 4:
            printf("%d",a/b);
            break;    
        default:
            printf("YOU ARE TREMINATED");
            return 0;
        }
        
    }
}