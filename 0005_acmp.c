/*
ЗАДАЧА №5		
Статистика
(Время: 1 сек. Память: 16 Мб Сложность: 15%)
Вася не любит английский язык, но каждый раз старается получить хотя бы четверку за четверть, чтобы оставаться ударником. В текущей четверти Вася заметил следующую закономерность: по нечетным дням месяца он получал тройки, а по четным – четверки. Так же он помнит, в какие дни он получал эти оценки. Поэтому он выписал на бумажке все эти дни для того, чтобы оценить, сколько у него троек и сколько четверок. Помогите Васе это сделать, расположив четные и нечетные числа в разных строчках. Вася может рассчитывать на оценку 4, если четверок не меньше, чем троек.

Входные данные
В первой строке входного файла INPUT.TXT записано единственное число N – количество элементов целочисленного массива (1 ≤ N ≤ 100). Вторая строка содержит N чисел, представляющих заданный массив. Каждый элемент массива – натуральное число от 1 до 31. Все элементы массива разделены пробелом.

Выходные данные
В первую строку выходного файла OUTPUT.TXT нужно вывести числа, которые соответствуют дням месяцев, в которые Вася получил тройки, а во второй строке соответственно расположить числа месяца, в которые Вася получил четверки. В третьей строке нужно вывести «YES», если Вася может рассчитывать на четверку и «NO» в противном случае. В каждой строчке числа следует выводить в том же порядке, в котором они идут во входных данных. При выводе числа отделяются пробелом.
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE * in = fopen("input.txt", "r");
    if(in == NULL){printf("Can't open file input.txt!"); return 0;}
    FILE * out = fopen("output.txt", "w");
    if(out == NULL){ printf("Can't open file output.txt!"); fclose(in); return 0; }

    if(in ==  NULL || out == NULL)
    {
        exit(EXIT_FAILURE);
    }

    int N = 0;

    fscanf(in, "%d", &N);
    int array[N];
    int array_index = 0;
    int odd[N];
    int odd_index = 0;
    int even[N];
    int even_index = 0;

    int i = 0;
    for(array_index = 0; array_index < N; ++array_index)
    {
        fscanf(in, "%d", &array[array_index]);
        if(array[array_index] % 2 != 0)
        {
            even[even_index++] = array[array_index];
        }
        else
        {
            odd[odd_index++] = array[array_index];
        }
    }

    for(int j = 0; j < even_index; ++j)
    {
        fprintf(out, "%d ", even[j]);
    }
    fprintf(out, "\n");
    for(int j = 0; j < odd_index; ++j)
    {
        fprintf(out, "%d ", odd[j]);
    }
    fprintf(out, "\n");

    if(even_index <= odd_index)
        fprintf(out, "%s", "YES");
    else
        fprintf(out, "%s", "NO");



    fclose(in);
    fclose(out);

    return 0;
}