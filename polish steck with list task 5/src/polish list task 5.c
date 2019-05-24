/*
 ============================================================================
 Name        : test.c
 Author      : =^_^=
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//eсли хотите допп пояснений по выполнению программы уберите символы // по ходу программы
typedef struct list {
    char ch[10];
    struct list *next;
} list;


list *last = NULL;
list *head = NULL;
int bool =1;
//int a = 1;
typedef struct stek {
    float data;
    struct stek *next_stek;
} stek;

stek *lastFstek = NULL;
stek *headFstek = NULL;

//Initialization of list |функция для добавления эллемента списка или его старт

void projectenterprise ( FILE* inFile) {

    list *futureLast = (list*)calloc(1,sizeof(list));// calloc обязателен
    futureLast->next = NULL;
    fscanf(inFile, "%c", &futureLast->ch[0]);
    int size = 0;
   // puts("    here we put 1 element after a gap     ");
    if (futureLast->ch[0] == 'E')
    {
      //  puts("if it is a stop symbol(E) program stops reading from file ");
        free(futureLast);
        bool =0;
    }
    else {
    while (futureLast->ch[size] != ' ')
    {
        //тут мы вводим данные в список если ПОСЛЕДНИЙ СИМВОЛ из элемента очереди не пробел
        size++;
        fscanf(inFile, "%c", &futureLast->ch[size]);
    }

   // printf("   we put in  list      ");
  //  puts(futureLast->ch);
   // printf("            %c",futureLast->ch[0]); and 1 symbol is
// иначе просто добавляется еще 1 элемент в список
    if  (last != NULL)
    {
        //a++
      //  printf("put another element if list its number is  %i")
        last->next = futureLast;
        futureLast->next = NULL;
    }
    // ecли это 1 вызов списка происходит ее инициаизация
    else {
       // puts("   Initialization of list  ");
        head = futureLast;
    }
    }
    //очень важный элемент программы тк тут происходит передвижение списка для записи
    last = futureLast;

}

int main(void) {
//float what;
    // открытие файла для записи
FILE *inFile;
inFile = fopen("source.txt","r");
// пока не конец файла происходит считывание данных в очередь
while (bool)
{
    projectenterprise( inFile);
}
// чтение из файла закончилось
fclose(inFile);
// открытие файла для записи
FILE  *outFile;
outFile = fopen("output.txt","w");
//puts("end of reading start of calculating ");
while( head !=NULL)// пока есть элементы в списка совершается следующее
    {
    if (head->ch[0] != 'f') {// если элемент из списка  это f то происходит запись в файл иначе
        //если элемент это следующие символы то происходит счет
               if (head->ch[0] == '+'|| head->ch[0] == '*'|| head->ch[0] == '/'|| (head->ch[0] == '-'
                       && head->ch[1] == ' ')) {// это условия для отриц чисел
                   switch (head->ch[0]) {
                   case '+':
                     //  puts("  we do some magic  ");
                   //    printf(" and magic it is  %f  + %f   ",headFstek->next_stek->data,headFstek->data);
                       headFstek->next_stek->data = headFstek->next_stek->data + headFstek->data;
                       break;
                   case '-':
                    //   puts("  we do some magic  ");
                    //   printf(" and magic it is  %f  - %f   ",headFstek->next_stek->data,headFstek->data);
                       headFstek->next_stek->data = headFstek->next_stek->data - headFstek->data;
                       break;
                   case '*':
                    //   puts("  we do some magic  ");
                     //  printf(" and magic it is  %f  * %f   ",headFstek->next_stek->data,headFstek->data);
                       headFstek->next_stek->data = headFstek->next_stek->data * headFstek->data;
                       break;
                   case '/':
                   //    puts("   we do some magic");
                    //   printf(" and magic it is  %f  / %f   ",headFstek->next_stek->data,headFstek->data);
                       headFstek->next_stek->data = headFstek->next_stek->data / headFstek->data;
                       break;
                   }
             //      printf("    result  %f    ",headFstek->next_stek->data);
                   //тут очистка использованного элемента стека
                   lastFstek = headFstek;
                   headFstek = headFstek->next_stek;
                   free(lastFstek);
               } else { // если элемет число добавляем его в стек
                   stek *tmp = (stek*)malloc(sizeof(stek));
                   tmp->data = atof(head->ch);
                  // printf("  in steck    %f    ",tmp->data);
                   tmp->next_stek = headFstek;
                   headFstek = tmp;
               }
               // переход на следующий элемент списка вне зависимости от элемента
           } else {
               // вывод результата в файл
               //printf("    right?  %f    ",headFstek->data);
               fprintf(outFile, "result: %f\n", headFstek->data);
               free(headFstek);// удаление последнего элемента стека
           }
    head = head->next;
       }
//концец исрользования списка и закрытие файла
fclose(outFile);
return 0;
}
