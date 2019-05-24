/*
 ============================================================================
 Name        : calcul.c
 Author      : me
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
//order is important in functions

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *inFile, *outFile;
    float *a ;
    float *b ;
    char ch ='p';
    char vec ='v';
    float buffer;
    int nubmerOfVec;
    inFile = fopen("source.txt","r");
    outFile = fopen("output.txt","w");
    fscanf (inFile, "%c %c ", &ch,&vec);
    switch(vec)
    {
     case 'v':fscanf (inFile, "%d", &nubmerOfVec);break;
     case 'c': nubmerOfVec = 1;
    }

    printf("we are here 1 %d", nubmerOfVec);
    a = malloc(nubmerOfVec*sizeof(float));
    b = malloc(nubmerOfVec*sizeof(float));
    for(int q=0;q<nubmerOfVec;q++)
    {
            fscanf (inFile, " %f",&a[q]);
            printf("\tFirst%f",a[q]);
    }
    for(int q=0;q<nubmerOfVec;q++)
        {
                fscanf (inFile, " %f",&b[q]);
                printf("\tSecond%f",b[q]);
        }
    puts("we are here 2 ");
           switch(vec)
           {
            case 'c' :
                switch(ch)
                {
                case '+' :puts("we are here ");*a = *a + *b;fprintf ( outFile,"this is a result %f\n", *a); ; break;
                case '-' :*a = *a - *b;fprintf ( outFile,"this is a result %f\n", *a); ; break;

                case 'f' :*b =1 ;for (int c = 1;c<=*a;c++)
    {
        *b=*b*c;
    }fprintf ( outFile,"this is a result %f\n", *b); break;
                case '*' :;*a = *a * (*b);fprintf ( outFile,"this is a result %f\n", *a); ; break;
                case '/' :;*a = *a / *b;fprintf ( outFile,"this is a result %f\n", *a); ; break;
                case '^' :
                    buffer = a[0];
                    for (int c = 1;c<*b;c++)
                    {
                        a[0]= a[0] * buffer;
                    }
                    fprintf (outFile, "this is a result %f\n", *a);
                    break;
               }break;
            case 'v' :  switch(ch)
            {
                case '+':
                    for (int m = 0;m<nubmerOfVec;m++)
                                            {
                                                a[m]= a[m] + b[m];
                                                fprintf (outFile,"%f ",a[m]);
                                            }break;
                case '-':
                    for (int m = 0;m<nubmerOfVec;m++)
                        {
                            a[m]= a[m] - b[m];
                            fprintf (outFile,"%f ",a[m]);
                        }
                    break;
                case '*':
                    for (int m = 1;m<nubmerOfVec;m++)
                                            {
                                                a[m]= a[m] * b[m];
                                                fprintf (outFile,"%f ",a[m]);
                                            }
                    break;
            }
          }




           fclose(inFile);
           fclose(outFile);

    return 0;
}
