/*
 ============================================================================
 Name        : начало.c
 Author      : shegida tup пыр
 Version     : 1 .0 beta
 Copyright   : NONe
 Description : kinda a calculator in c
 ============================================================================
 */
// u checked this
#include <stdio.h>
#include <stdlib.h>


float plus_print ()
{
    float a ;
    float b ;
    float ret ;
    printf("enter first number\n");// input data
    ret = scanf("%f",&a);
    if (0 != ret)
    {
        printf("OK\n");
    }
    else
    {
        printf("invalid-not a number(or not)");
        return 0;
    }
    printf("enter second number\n");
    ret = scanf("%f",&b);
    if (0 != ret)
    {
        printf("OK\n");
    }
    else
    {
        printf("invalid-not a number(or not)");
        return 0;
    }
    a = a + b;//calculating
    printf("%f\n",a);//release answer
    return 0;
}


float min_print()
{
    float a ;
    float b ;
    float ret ;
    printf("enter first number\n");
    ret = scanf("%f",&a);
    if (0 != ret)
    {
        printf("OK\n");
    }
    else
    {
        printf("invalid-not a number(or not)");
        return 0 ;
    }
    printf("enter second number\n");
    ret = scanf("%f",&b);
    if (0 != ret)
    {
        printf("OK\n");
    }
    else
    {
        printf("invalid-not a number(or not)");
        return 0;
    }
    a = a - b;//calculating
    printf("%f\n",a);//release answer
    return 0;
}


unsigned int fact_print()
{
    unsigned int ret;
    unsigned int a ;
    unsigned int b = 1;
    printf("enter fact number\n");// input data
    ret = scanf("%u",&a);
    if (0 != ret)
    {
        printf("OK\n");
    }
    else
    {
        printf("invalid-not a number(or not)");
        return 0;
    }
    for (int i = 1;i<=a;i++)//calculating
    {
        b=b*i;
    }
    printf("%u\n",b);//release answer
    return 0;
}


float multiplication_print()
{
    float a;
    float b;
    float ret ;
    printf("enter first number\n");// input data
    ret = scanf("%f",&a);
    if (0 != ret)
    {
        printf("OK\n");
    }
    else
    {
        printf("invalid-not a number(or not)");
        return 0;
    }
    printf("enter second number\n");
    ret = scanf("%f",&b);
    if (0 != ret)
    {
        printf("OK\n");
    }
    else
    {
        printf("invalid-not a number(or not)");
        return 0;
    }
    a= a*b;//calculating
    printf("%f\n",b);//release answer
    return 0;}

float division_print()
{
    float ret ;
    float a;
    float b;
    printf("enter first number\n");// input data
    ret = scanf("%f",&a);
    if (0 != ret)
    {
        printf("OK\n");
    }
    else
    {
        printf("invalid-not a number(or not)");
        return 0;
    }
    printf("enter second number\n");
    ret = scanf("%f",&b);
    if (0 != ret)
    {
        printf("OK\n");
    }
    else
    {
        printf("invalid-not a number(or not)");
        return 0;
    }
    a= a/b;//calculating
    printf("%f\n",a);//release answer
    return 0;
}


int power_print()
{
    int ret ;
    int a;
    int b;
    printf("enter  number\n");// input data
    ret = scanf("%i",&a);
    if (0 != ret)
    {
        printf("OK\n");
    }
    else
    {
        printf("invalid-not a number(or not)");
        return 0;
    }
    printf("enter his power\n");
    ret = scanf("%i",&b);
    if (0 != ret)
    {
        printf("OK\n");
    }
    else
    {
        printf("invalid-not a number(or not)");
        return 0;
    }
    for (int i = 1;i<b;i++)
    {
        a=a*a;
    }
    printf("%i\n",a);//release answer
    return 0;
}


int main()
{
    char Y = 'Y';
    int ok = 0;
    int q = 34;
    char ch ='p';
    puts("do u need a list of commandsY/N");//asking for a list of commands
    scanf("%c",&ch);
    if (ch==Y) puts("+_f^");
    puts("enter a command");//asking for a command
    while (ok!=1)//loop for repeating
    {
            scanf("%c",&ch);//scan  command
            switch(ch)
            {
                case '+' :
                     plus_print() ; //in case + doing summ and asking for repeat
                     puts("do u want to repeat 0-no/1-no continue");
                     scanf("%i",&q);
                     if (q==0)
                     {
                         ok+=1;
                         break;
                     }
                     else break;
                case '-' :
                     min_print();
                     puts("do u want to repeat0-no/1-no continue");
                     scanf("%i",&q);//in case - doing subtracting and asking for repeat
                     if (q==0)
                     {
                         ok+=1;
                         break;
                     }
                     else break;
                case 'f' :
                     fact_print();
                     puts("do u want to repeat0-no/1-no continue");
                     scanf("%i",&q);//in case f doing factorial and asking for repeat
                     if (q==0)
                     {
                         ok+=1;
                         break;
                     }
                     else break;
                case '*' :
                     multiplication_print();
                     puts("do u want to repeat0-no/1-no continue");
                     scanf("%i",&q);//in case * doing multiplication and asking for repeat
                     if (q==0)
                     {
                         ok+=1;
                         break;
                     }
                else break;
                case '/' :
                     division_print();
                     puts("do u want to repeat0-no/1-no continue");
                     scanf("%i",&q);//in case / doing division and asking for repeat
                     if (q==0)
                     {
                         ok+=1;
                         break;
                     }
                     else break;
                case '^' :
                     power_print();
                     puts("do u want to repeat0-no/1-no continue");
                     scanf("%i",&q);//in case ^ finding a power and asking for repeat
                     if (q==0)
                     {
                         ok+=1;break;}
                     else break;
                default :
                     puts("another cycle don't forget commands +-f^*/  ");
                     ch ='l';
                     break;//repeat a list of commands because a wrong one
            }
    }
    return 0;
}
