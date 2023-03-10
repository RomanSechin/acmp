/*
ЗАДАЧА №3		
Пятью пять - двадцать пять!
(Время: 1 сек. Память: 16 Мб Сложность: 8%)
Вася и Петя учатся в школе в одном классе. Недавно Петя поведал Васе о хитром способе возведения в квадрат натуральных чисел, оканчивающихся на цифру 5. Теперь Вася может с легкостью возводить в квадрат двузначные (и даже некоторые трехзначные) числа, оканчивающиеся на 5. Способ заключается в следующем: для возведения в квадрат числа, оканчивающегося на 5 достаточно умножить число, полученное из исходного вычеркиванием последней пятерки на следующее по порядку число, затем остается лишь приписать «25» к получившемуся результату справа. Например, для того, чтобы возвести число 125 в квадрат достаточно 12 умножить на 13 и приписать 25, т.е. приписывая к числу 12*13=156 число 25, получаем результат 15625, т.е. 1252=15625. Напишите программу, возводящую число, оканчивающееся на 5, в квадрат для того, чтобы Вася смог проверить свои навыки.

Входные данные
В единственной строке входного файла INPUT.TXT записано одно натуральное число А, оканчивающееся на цифру 5, не превышающее 4*105.

Выходные данные
В выходной файл OUTPUT.TXT выведите одно натуральное число - A2 без лидирующих нулей.
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

    unsigned N = 0;

    fscanf(in, "%u", &N);
    if(N < 0)
    {
        N *= -1;
    }

    int rest = 0;
    unsigned limit =  399996;
    if((N < limit) && (N % 10) == 5)
    {
        rest = N/10;
        if(rest != 0)
            fprintf(out, "%u", (unsigned )((rest * (rest + 1))));

        fprintf(out, "%u", (unsigned )(25));
    }

    fclose(in);
    fclose(out);

    return 0;
}