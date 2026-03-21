#include<stdio.h>
int main()
{
    int x,y;
    char op;
    printf("Enter two number:");
    scanf("%d %d",&x,&y);
    printf("Enter a operator(+,-,*,/)");
    scanf(" %c",&op);
       
       if(op=='+')
       {
       printf("Result=%d",x+y);
       }
          else if(op=='-')
          {
            printf("Result=%d",x-y);
          }
            else if(op=='*')
            {
                printf("Result=%d",x*y);
            }
                else if(op=='/')
                {
                    printf("Result=%d",x/y);
                }
                  else
                  {
                    printf("invalid");
                  }
                    return 0;
         

}