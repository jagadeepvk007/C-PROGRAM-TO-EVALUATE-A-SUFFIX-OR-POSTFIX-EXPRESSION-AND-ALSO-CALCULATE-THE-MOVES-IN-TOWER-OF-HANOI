#include<stdio.h>
#include<conio.h>
#include<math.h>
int count=0, top=-1;
   int operate(char symb, int op1, int op2)
        {
            switch(symb)
              {
                case '+':return(op1+op2);
                case '-':return(op1-op2);
                case '/':return(op1/op2);
                case '*':return(op1*op2);
                case '%':return(op1%op2);
                case '^':return(pow(op1,op2));
              }
        }
    void push(int stack[],int d)
         {
            stack[++top]=d;
         }
    int pop(int stack[])
      {
        return(stack[top--]);
      }
  void tower( int n,char src, char intr, char des)
    {
      if(n)
        {
          tower(n-1,src,des,intr);
          printf("disk %d moved from %c to %c\n",n,src,des);
          count++;
          tower(n-1,intr,src,des);
        }
    }
void main()
  {
    int n, choice,i,op1,op2,ans,stack[50],top=-1;
    char expr[20],symb;
    while(1)
      {
        printf("\n1. evaluate suffix expression\n 2.Tower of hanoi\n 3.Exit\n ");
        printf("\nenter the choice\n");
        scanf("%d",&choice);
          switch(choice)
            {
              case 1: printf("enter the suffix expression\n");
              scanf("%s",expr);
              for(i=0;expr[i]!='\0';i++)
                {
                  symb=expr[i];
                  if(symb>='0'&&symb<='9')
                   push(stack,symb-'0');
                  else
                    {
                      op2=pop(stack);
                      op1=pop(stack);
                      ans=operate(symb,op1,op2);
                      push(stack,ans);
                    }
                }
                      ans=pop(stack);
                        printf("The result of the suffix expression is %d",ans);
               break;
        case 2: printf("enter the number of disks\n");
                scanf("%d",&n);
                tower(n,'a','b','c');
                printf("number of moves taken to move disks from source to destination %d",count);
                  count=0;
               break;
              case 3:exit(0);
              }
          }
    }
