/*
 ============================================================================
 Name        : boring.c
 Author      : shegida tup пыр
 Version     :
 Copyright   : NONe
 Description : 4th task: lists
 ============================================================================
 */



// данные в списке остаются до конца работы программы тк не обговорено обратное
#include <stdio.h>
#include <stdlib.h>



typedef struct element {
    char ch;
    char vec;
    int nubmerOfVec;
    float *value1;
    float *value2;
    struct element *next;
} element;

element *last = NULL;
element *head = NULL;


typedef struct res {
    char oper;
    int size;
    float *result;
    struct res *next;
} res;


res *lastres = NULL;
res *headres = NULL;

void pushEl ( FILE* inFile) {

    element *futureLast = (element*)malloc(sizeof(element));

    fscanf(inFile, " %c %c", &futureLast->ch, &futureLast->vec);
    printf("   1414 we are here %c  %c",futureLast->ch,futureLast->vec);
    if (futureLast->vec == 'v')
        fscanf(inFile, "%d", &futureLast->nubmerOfVec);
    else
        futureLast->nubmerOfVec = 1;
    futureLast->value1 = malloc(futureLast->nubmerOfVec*sizeof(float));
    futureLast->value2 = malloc(futureLast->nubmerOfVec*sizeof(float));
    for (int i = 0; i < futureLast->nubmerOfVec; i++)
        fscanf(inFile, "%f", &futureLast->value1[i]);
    if (futureLast->ch !='f')
    {
        futureLast->value2 = malloc(futureLast->nubmerOfVec*sizeof(float));
        for (int i = 0; i < futureLast->nubmerOfVec; i++)
            fscanf(inFile, "%f", &futureLast->value2[i]);
    }
if  (last != NULL)
{
    last->next = futureLast;
    futureLast->next = NULL;
    last = futureLast;
}
else {
    head = futureLast;
  last = futureLast;
}
}

void pushres ()
{
    res *futureLast = (res*)malloc(sizeof(element));
    futureLast->result = malloc(last->nubmerOfVec*sizeof(float));
    futureLast->size = last->nubmerOfVec;
    futureLast->oper = last->vec;
    switch(last->vec)
    {
        case 'c' :switch(last->ch)
        {
            case '+' :
                puts("  6 we are here ");
                futureLast->result[0] = last->value1[0] + last->value2[0];
                break;
            case '-' :
                futureLast->result[0] = last->value1[0] - last->value2[0];
                break;
            case 'f' :
                futureLast->result[0] =1 ;
                for (int c = 0;c<=last->value1[0];c++)
                 {
                                 futureLast->result[0]=futureLast->result[0]*c;
                 }
                break;
            case '*' :
                futureLast->result[0] = last->value1[0] * (last->value2[0]);
                break;
            case '/' :
                futureLast->result[0] = last->value1[0] / last->value2[0];
                break;
            case '^' :
                futureLast->result[0] = last->value1[0] ;
                for (float c = 1 ;c<last->value2[0];c++)
                {
                    futureLast->result[0]= futureLast->result[0] * last->value1[0];
                }
                break;
        }break;
        case 'v' :switch(last->ch)
        {
            case '+':
                for (int m = 0;m<last->nubmerOfVec;m++)
                {
                    futureLast->result[m]= last->value1[m] +last->value2[m];
                }
                break;
           case '-':
               for (int m = 0;m<last->nubmerOfVec;m++)
               {
                   futureLast->result[m]= last->value1[m] - last->value2[m];
               }
               break;
          case '*':
              for (int m = 0;m<last->nubmerOfVec;m++)
               {
                  futureLast->result[m]=last->value1[m] * last->value2[m];
               }
              break;
        }
    }

if  (lastres != NULL)
{
    lastres->next = futureLast;
    futureLast->next = NULL;
    lastres = futureLast;
}
else {
    headres = futureLast;
  lastres = futureLast;
}
}



int main(void) {
    FILE *inFile;
    inFile = fopen("source.txt","r");
    while (!feof(inFile))
    {
        pushEl ( inFile);
    }
    fclose(inFile);
    last = head;
    while(last !=NULL)
    {
        pushres () ;
        last =last->next;
    }
    lastres = headres;
    FILE  *outFile;
    outFile = fopen("output.txt","w");
    while(lastres !=NULL)
    {
        fputs("your result",outFile);
        for (int y =0;y<lastres->size;y++)
        {
            fprintf (outFile,"%f ",lastres->result[y]);
        }
        lastres =lastres->next;
    }
        fclose(outFile);
    return EXIT_SUCCESS;
}
