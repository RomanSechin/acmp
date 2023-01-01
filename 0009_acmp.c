/*
ЗАДАЧА №9
Домашнее задание
(Время: 1 сек. Память: 16 Мб Сложность: 27%)
 
Входные данные
В первой строке входного файла INPUT.TXT записано единственное число N – количество элементов массива.
Вторая строка содержит N целых чисел, представляющих заданный массив. Все элементы массива разделены пробелом.
Каждое из чисел во входном файле, в том числе и N, не превышает 10^2 по абсолютной величине.
 
Выходные данные
В единственную строку выходного файла OUTPUT.TXT нужно вывести два числа, разделенных пробелом:
сумму положительных элементов и произведение чисел, расположенных между минимальным и максимальным элементами.
 Значения суммы и произведения не превышают по модулю 3*10^4.
 2021.07.11 Roman V.S.
*/
#include <stdio.h>
#include <stdlib.h>
 
int main()
{
    FILE *in = fopen("INPUT.TXT", "r");
    FILE *out = fopen("OUTPUT.TXT", "w");
 
    if(in ==  NULL || out == NULL)
    {
        exit(EXIT_FAILURE);
    }
 
    int N = 0;
    int min = 0;
    int max = 0;
    int min_index = 0;
    int max_index = 0;
    int sum_of_positive = 0;
    int product = 1;
 
    fscanf(in, "%d", &N);
    int array[N];
 
    for(int i = 0; i < N; ++i)
    {
        fscanf(in, "%d", &array[i]);
        if(array[i] > 0)
        {
            sum_of_positive += array[i];
        }
    }
    min = max = array[0];
 
    for(int i = 0; i < N; ++i)
    {
        if(array[i] > max)
          {
             max = array[i];
             max_index = i;
          }
        if(array[i] < min)
        {
            min = array[i];
            min_index = i;
        }
    }
 
    if(min_index < max_index)
    for(int i = min_index + 1; i < max_index; ++i)
    {
        product *= array[i];
    }
    else
        for(int i = max_index + 1; i < min_index; ++i)
    {
        product *= array[i];
    }
 
    fprintf(out, "%d %d", sum_of_positive, product);
 
    fclose(in);
    fclose(out);
 
    return 0;
}