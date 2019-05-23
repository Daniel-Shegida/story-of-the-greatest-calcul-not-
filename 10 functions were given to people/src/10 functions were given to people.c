/*
 ============================================================================
 Name        : 10 functions were given to people
 Author      : shegida tup пыр
 Version     : 1 .1 beta
 Copyright   : NONe
 Description : second task for vectors
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>


// в эти функции попадают значения из vector_pl_print и над ними производятся операции 

void vector_muinus(float *v1,float *v2,int *ret)
{
   int m;
   float res;
   puts("your vector is");
   for (m = 0;m<*ret;m++)
   {
       res= v1[m]- v2[m];
       printf ("%f\t%f\t%f\n",res,v1[m],v2[m]);
   }
}

void vectorPlus (float *v1,float *v2,int *ret)
{
    int m;
    float res;
    puts("your vector is");
    for (m = 0;m<*ret;m++)
    {
        res= v1[m] + v2[m];
        printf ("%f\t%f\t%f\n",res,v1[m],v2[m]);
    }
}


void vector_scal(float *v1,float *v2,int *ret)
{
    int m;
    float res;
    puts("your vector is");
    for (m = 0;m<*ret;m++)
    {
        res = v1[m]* v2[m];
        printf ("%f\t%f\t%f\n",res,v1[m],v2[m]);
    }
}


float plus_print ()
{
    float a ;
    float b ;
    float ret ;//переменная для проверки ввода
    printf("enter first number\n");
    ret = scanf("%f",&a);
   // проверка ввода 
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
 // если ввод был правильный происходит вычисления и вывод результатов 
    a = a + b;
    printf("%f",a);
    return 0;
}

// ряд функций выполняющие частичную проверку вводимых данных и проведение над ними операций в случае правильного ввода
float min_print()
{
    float a ;
    float b ;
    float ret ;//переменная для проверки ввода
    printf("enter first number\n");
  // проверка ввода 
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
   // проверка ввода 
    if (0 != ret)
    {
        printf("OK\n");
    }
    else
    {
        printf("invalid-not a number(or not)");
        return 0;
    }
  // если ввод был правильный происходит вычисления и вывод результатов
    a = a - b;
    printf("%f",a);
    return 0;
}
unsigned int fact_print()
{
    unsigned int ret;//переменная для проверки ввода
    puts ("enter a number");
    unsigned int a ;
    unsigned int b = 1;
    printf("enter first number\n");
    ret = scanf("%u",&a);
   // проверка ввода 
    if (0 != ret)
    {
        printf("OK\n");
    }
    else
    {
        printf("invalid-not a number(or not)");
        return 0;
    }
    for (int i = 1;i<=a;i++)
    {
        b=b*i;
    }
  // если ввод был правильный происходит вычисления и вывод результатов
    printf("%u",b);
    return 0;
}
float multiplication_print()
{
    float a;
    float b;
    float ret ;//переменная для проверки ввода
    printf("enter first number\n");
    ret = scanf("%f",&a);
   // проверка ввода 
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
    a= a*b;
  // если ввод был правильный происходит вычисления и вывод результатов
    printf("%f",b);
    return 0;}
float division_print()
{
    float ret ;//переменная для проверки ввода
    float a;
    float b;
    printf("enter first number\n");
    ret = scanf("%f",&a);
   // проверка ввода 
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
    a= a/b;
  // если ввод был правильный происходит вычисления и вывод результатов
    printf("%f",a);
    return 0;
}

int power_print()
{
    int ret ;//переменная для проверки ввода
    int a;
    int b;
    printf("enter  number\n");// input data
    ret = scanf("%i",&a);
   // проверка ввода 
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
  // если ввод был правильный происходит вычисления и вывод результатов
    printf("%i\n",a);//release answer
    return 0;
}

float vector_pl_print()///errors in vec are just to diff
{
    int ret,i,c;
    char cheese;
    float *vector1;
    float *vector2;
    printf("enter a number of spaces in vector ");
 // ввод кол-ва измерений в векторах
    scanf(" %d",&ret);
 //обьявление статических массивов длина которых зависит от предыдущей операции 
    vector1 = malloc(ret*sizeof(float));
    vector2 = malloc(ret*sizeof(float));
 //ввод векторов с консоли
    printf("enter first vector ");
    for (i = 0;i<ret;i++) {scanf ("%f",&vector1[i]);}
    printf("enter second vector ");
    for (c = 0;c<ret;c++) {scanf ("%f",&vector2[c]);}
 // отправка векторов в 1 из функций показанных выше
    puts("what do u want to do with vectors ");
    scanf(" %c",&cheese);
    switch(cheese)
        {
            case '+': vectorPlus(vector1,vector2,&ret);break;
            case '-': vector_muinus(vector1,vector2,&ret);break;
            case 's': vector_scal(vector1,vector2,&ret);break;
        }
    return 0 ;
}

int main()
{
    char Y = 'Y';
    int ok = 0;
    int q = 34;
    char ch ='p';
    puts("do u need a list of commandsY/N");
    scanf("%c",&ch);
    if (ch==Y) puts("+(summ)-(minus)f(factorial)^(power)*(multiplication)/(division)v(starting working with vectors)");
    puts("enter a command");
 // выбирается команда взависимости от введенного символа 
    while (ok!=1)
    {
            scanf("%c",&ch);
            switch(ch)
            {
              // во всех случаях сначала идет переход в функцию потом взависимости от ответа либо программа закрывается либо продолжает свою работу 
                case '+' :plus_print() ; puts("do u want to repeat 0-no1-continue");scanf("%i",&q);
                if (q==0) {ok+=1;break;}
                else break;
                case '-' :min_print(); puts("do u want to repeat 0-no1-continue");scanf("%i",&q);
                if (q==0) {ok+=1;break;}
                else break;
                case 'f' :fact_print();puts("do u want to repeat 0-no1-continue");scanf("%i",&q);
                if (q==0) {ok+=1;break;}
                else break;
                case '*' :multiplication_print(); puts("do u want to repeat 0-no1-continue");scanf("%i",&q);
                if (q==0) {ok+=1;break;}
                else break;
                case '/' :division_print(); puts("do u want to repeat 0-no1-continue");scanf("%i",&q);
                if (q==0) {ok+=1;break;}
                else break;
                case '^' :power_print(); puts("do u want to repeat 0-no1-continue");scanf("%i",&q);
                if (q==0) {ok+=1;break;}
                else break;
                case 'v' :vector_pl_print() ; puts("do u want to repeat 0-no1-continue");scanf("%i",&q);
                if (q==0) {ok+=1;break;}
                else break;
                default :puts("another cycle don't forget commands +(summ)-(minus)f(factorial)^(power)*(multiplication)/(division)v(starting working with vectors)");ch ='l';break;
            }
    }
    return 0;
}
