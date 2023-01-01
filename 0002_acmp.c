/*
ЗАДАЧА №2		
Сумма
(Время: 1 сек. Память: 16 Мб Сложность: 19%)
Требуется посчитать сумму целых чисел, расположенных между числами 1 и N включительно.

Входные данные
В единственной строке входного файла INPUT.TXT записано единственное целое число N, не превышающее по абсолютной величине 104.

Выходные данные
В единственную строку выходного файла OUTPUT.TXT нужно вывести одно целое число — сумму чисел, расположенных между 1 и N включительно.
*/
#include <stdio.h>
#include <stdlib.h>
int sum_pyramid(int N)
{
    int sum = 0;
    if(N>0)
    for(int i = 1; i <= N; ++i)
    {
        sum += i;
    }
    else
        for(int i = 1; i >= N; --i)
    {
        sum += i;
    }
    return sum;
}

int main()
{
	FILE * in = fopen("input.txt", "r"); if(in == NULL){ printf("Can't open input.txt"); return 0;} 
	FILE * out = fopen("output.txt", "w"); if(out == NULL){ printf("Can't open output.txt"); return 0;}

    if(in ==  NULL || out == NULL)
    {
        exit(EXIT_FAILURE);
    }

    int N = 0;

    fscanf(in, "%d", &N);

    fprintf(out, "%d", sum_pyramid(N));

    fclose(in);
    fclose(out);

    return 0;
}
