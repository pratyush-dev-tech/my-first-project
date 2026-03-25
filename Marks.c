#include<stdio.h>
int main()
{
    char sub1, sub2;
    int marks;

    printf("Choose subject 1 (m for math, s for science): ");
    scanf(" %c", &sub1);

    printf("Choose subject 2 (m for math, s for science): ");
    scanf(" %c", &sub2);

    if((sub1=='m' && sub2=='s') || (sub1=='s' && sub2=='m'))
    {
        marks = 45;
    }
    else if(sub1=='m' || sub2=='m')
    {
        marks = 30;
    }
    else if(sub1=='s' || sub2=='s')
    {
        marks = 20;
    }
    else
    {
        marks = 0;
    }

    printf("Marks = %d\n", marks);

    return 0;
}