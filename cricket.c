#include<stdio.h>
#include<stdlib.h>

#define num 5

struct cricket{
    int code;
    int avg;
    char name[30];
    char team_name[20];
};

int main()
{
    struct cricket a[num];

    printf("Enter the player details :-\n");
    for(int i = 0; i<num; i++)
    {
        printf("Player %d Name: ",i+1);
        scanf("%s", a[i].name);
        printf("Player %d Code: ",i+1);
        scanf("%d", &a[i].code);
        printf("Player %d AVG: ",i+1);
        scanf("%d", &a[i].avg);
        printf("Player %d Team: ",i+1);
        scanf("%s", a[i].team_name);
    }

    for(int j =0; j<num; j++)
    {
        printf("Player %d : %s - %d - %d - %s",j,a[0].name,a[0].code,a[0].avg,a[0].team_name);
    }

    return 0;

}