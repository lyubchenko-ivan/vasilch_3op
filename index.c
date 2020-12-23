#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXLEN 1000


char delim[] = " ;,.\t\n\0";

int main(void)
{
    // строки
    char str1[MAXLEN];
    char str2[MAXLEN];

    // переменные для хранения слов двух предложений
    char *word1;
    char *word2;

    //массивы для хранения всех слов двух предложений
    char words1[20][20];
    char words2[20][20];

    int i = 0,
        k = 0,
        j = 0;// счетчики для итерации по массивам слов


    int countWords1 = 0,
        countUniqEls = 0,
        countWords2 = 0;//кол-во слов в каждой строке


    char uniqEls[20][20];//массив для хранения уникальных слов 


    //принимаем 1-ую строку
    puts("Enter first string");
    fgets(str1, MAXLEN, stdin);

    //принимаем 2-ую строку
    puts("Enter second string");
    fgets(str2, MAXLEN, stdin);

    //заполняем массив слов первой строки
    word1 = strtok(str1, delim);

    do{

        strcpy(words1[i++], word1);
        countWords1++;
        word1 = strtok(NULL, delim);
    }while (word1 != NULL);
    free(word1);
    //закончили заполнение



    //начинаем заполнение массива слов второй строки
    i = 0;

    word2 = strtok(str2, delim);
    do{
        strcpy(words2[i++], word2);
        countWords2++;
        word2 = strtok(NULL, delim);
    }while(word2 != NULL);
    free(word2);
    //закончили заполнение

    

    //найдем уникальные элементы первой строки
    for ( i = 0, k = 0; i < countWords1; i++)
    {
        int status = 1;

        for ( j = 0; j <= countWords2; j++)
        {

            if(strcmp(words1[i], words2[j]) == 0){
                status = 0;
                break;
            }

        }
        if (status == 1){
            strcpy(uniqEls[k++], words1[i]);
            countUniqEls++;
        }    
    } 

    
    //заканчиваем поиск уникальных элементов

    
    // найдем самое маленькое слово из уникальных
    
    char answer[20];
    strcpy(answer, uniqEls[0]);
    for ( i = 0; i < countUniqEls; i++)
    {
        if (strlen(answer) >= strlen(uniqEls[i])){
            strcpy(answer, uniqEls[i]);
        }
        // printf("%s", answer);
    }
    printf("least common word: \"%s\"\n", answer);

    

    // закончим поиск


    // выведем ответ


    return 0;

}



