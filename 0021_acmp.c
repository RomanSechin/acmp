/*
ЗАДАЧА №21
Зарплата
(Время: 1 сек. Память: 16 Мб Сложность: 4%)
В отделе работают 3 сотрудника, которые получают заработную плату в рублях. Требуется определить: на сколько зарплата самого высокооплачиваемого из них отличается от самого низкооплачиваемого.
 
Входные данные
В единственной строке входного файла INPUT.TXT записаны размеры зарплат всех сотрудников через пробел. Каждая заработная плата – это натуральное число, не превышающее 105.
 
Выходные данные
В выходной файл OUTPUT.TXT необходимо вывести одно целое число — разницу между максимальной и минимальной зарплатой.
2021.07.12 Roman V.S.
*/
#include <stdio.h>
#include <stdlib.h>
 
int main()
{
    FILE * in = fopen("INPUT.TXT", "r");
    FILE * out = fopen("OUTPUT.TXT", "w");
 
    int sal1 = 0;
    int sal2 = 0;
    int sal3 = 0;
    int max = 0;
    int min = 0;
 
    fscanf(in, "%d %d %d", &sal1, &sal2, &sal3);
 
    if(sal1 >= sal2 && sal1 >= sal3)
    {
        max = sal1;
    }
    else if(sal2 >= sal1 && sal2 >= sal3)
    {
        max = sal2;
    }
    else if(sal3 >= sal1 && sal3 >= sal2)
    {
        max = sal3;
    }
 
    if(sal1 <= sal2 && sal1 <= sal3)
    {
        min = sal1;
    }
    else if(sal2 <= sal1 && sal2 <= sal3)
    {
        min = sal2;
    }
    else if(sal3 <= sal1 && sal3 <= sal2)
    {
        min = sal3;
    }
 
    fprintf(out, "%d", max - min);
 
    fclose(in);
    fclose(out);
 
    return 0;
}