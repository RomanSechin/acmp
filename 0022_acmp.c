/*
ЗАДАЧА №22		
Единицы
(Время: 1 сек. Память: 16 Мб Сложность: 16%)
На уроках информатики вас, наверное, учили переводить числа из одних систем счисления в другие и выполнять другие подобные операции. Пришло время продемонстрировать эти знания. Найдите количество единиц в двоичной записи заданного числа.

Входные данные
Во входном файле INPUT.TXT записано целое число n (0 ≤ n ≤ 2×109).

Выходные данные
В единственную строку выходного файла OUTPUT.TXT нужно вывести одно целое число — количество двоичных единиц в записи числа n.
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
 
int check_bit(int n, int pos)
{
    if((n & (1 << pos)) == 0) return 0;
    else return 1;
}
 
int count_bit(int n)
{
    return sizeof(int) * CHAR_BIT;
}
 
int main()
{
    FILE * in = fopen("INPUT.TXT", "r");
    FILE * out = fopen("OUTPUT.TXT", "w");
 
    int n = 0;
    while(fscanf(in, "%d", &n) == 1)
    {
        int cnt_of_one = 0;
        int len = count_bit(n);
        for(int i = 0; i < len; ++i)
        {
            cnt_of_one += check_bit(n, i);
        }
        fprintf(out, "%d\n", cnt_of_one);
    }
 
    fclose(in);
    fclose(out);
    return 0;
}