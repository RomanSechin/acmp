
/*
ЗАДАЧА №14		
НОК
(Время: 1 сек. Память: 16 Мб Сложность: 19%)
Требуется написать программу, определяющую наименьшее общее кратное (НОК) чисел a и b.

Входные данные
В единственной строке входного файла INPUT.TXT записаны два натуральных числа А и В через пробел, не превышающих 46340.

Выходные данные
В единственную строку выходного файла OUTPUT.TXT нужно вывести одно целое число — НОК чисел А и В.
*/

#include <stdio.h>
#include <stdlib.h>
 
int NOD(int a, int b)
{
    while (a != b)
    {
        if (a > b)
        {
            a -= b;
        }
        else
        {
            b -= a;
        }
    }
    return a;
}
 
int NOK(int a, int b)
{
    return abs(a * b)/NOD(a, b);
}
 
int main()
{
    FILE * in = fopen("input.txt", "r");
    if(in == NULL){printf("Can't open file input.txt!"); return 0;}
    FILE * out = fopen("output.txt", "w");
    if(out == NULL){ printf("Can't open file output.txt!"); fclose(in); return 0; } 
 
    int n;
    int m;
 
    if(fscanf(in, "%d %d", &n, &m) == 2)
    {
        fprintf(out, "%d", NOK(n, m));
    }
 
    fclose(in);
    fclose(out);
    return 0;
}