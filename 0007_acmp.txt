/*
Золото племени АББА
(Время: 1 сек. Память: 16 Мб Сложность: 30%)
Главный вождь племени Абба не умеет считать.
В обмен на одну из его земель вождь другого племени предложил ему выбрать одну из трех куч с золотыми монетами.
Но вождю племени Абба хочется получить наибольшее количество золотых монет. Помогите вождю сделать правильный выбор!
 
Входные данные
В первой строке входного файла INPUT.TXT записаны три натуральных числа через пробел.
Каждое из чисел не превышает 10^100. Числа записаны без ведущих нулей.
 
Выходные данные
В выходной файл OUTPUT.TXT нужно вывести одно целое число — максимальное количество монет, которые может взять вождь.
Roman V.S. 2021.07.10
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
char * cmp_strings(char * str1, char * str2)
{
    char * result;
    if(strlen(str1) > strlen(str2))
        result = str1;
    else if(strlen(str1) < strlen(str2))
        result = str2;
    else
    {
        if(strcmp(str1, str2) > 0)
            result = str1;
        else
            result = str2;
    }
 
    return result;
}
 
int main()
{
    FILE *in = fopen("INPUT.TXT", "r");
    FILE *out = fopen("OUTPUT.TXT", "w");
 
    if(in ==  NULL || out == NULL)
    {
        exit(EXIT_FAILURE);
    }
 
    char str1[100] = {0};
    char str2[100] = {0};
    char str3[100] = {0};
 
    fscanf(in, "%s %s %s", str1, str2, str3);
 
    fprintf(out, "%s", cmp_strings(str1, cmp_strings(str2, str3)));
 
    fclose(in);
    fclose(out);
 
    return 0;
}