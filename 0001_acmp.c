//ЗАДАЧА №1     
//A+B
//(Время: 1 сек. Память: 16 Мб Сложность: 2%)
//Требуется сложить два целых числа А и В.
 
//Входные данные
//В единственной строке входного файла INPUT.TXT записаны два натуральных числа через пробел. Значения чисел не превышают 109.
 
//Выходные данные
//В единственную строку выходного файла OUTPUT.TXT нужно вывести одно целое число — сумму чисел А и В.
#include <stdio.h>
#include <stdlib.h>
 
int main()
{
	FILE * in = fopen("input.txt", "r"); if(in == NULL){ printf("Can't open input.txt"); return 0;} 
	FILE * out = fopen("output.txt", "w"); if(out == NULL){ printf("Can't open output.txt"); return 0;}
 
    if(in ==  NULL || out == NULL)
    {
        exit(EXIT_FAILURE);
    }
 
    int a = 0;
    int b = 0;
 
    fscanf(in, "%d %d", &a, &b);
    fprintf(out, "%d", a+b);
 
    fclose(in);
    fclose(out);
 
    return 0;
}