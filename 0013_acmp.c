/*
ЗАДАЧА №13		
Быки и коровы
(Время: 1 сек. Память: 16 Мб Сложность: 26%)
Петя и Вася часто играют в различные логические игры. Недавно Петя поведал Васе о новой игре «Быки и коровы» и теперь они играют в эту игру сутками. Суть игры очень проста: Петя загадывает четырехзначное число, состоящее из различных цифр. Вася отгадывает задуманное Петей число, перебирая возможные варианты. Каждый раз Вася предлагает вариант своего четырёхзначного числа, состоящего из различных цифр, а Петя делает Васе подсказку: сообщает количество быков и коров, после чего Вася с учетом подсказки продолжает отгадывание числа до тех пор, пока не отгадает. Быки – это количество цифр в предложенном Васей числе, совпадающих по значению и стоящих в правильной позиции в задуманном Петей числе. Коровы – количество цифр, совпадающих по значению, но находящихся в неверной позиции. Например, если Петя задумал число 5671, а Вася предложил вариант 7251, то число быков равно 1 (только цифра 1 на своем месте), а число коров равно 2 (только цифры 7 и 5 не на своих местах). Петя силен в математике, но даже он может ошибаться. Помогите Пете написать программу, которая бы по загаданному Петей и предложенному Васей числам сообщала количество быков и коров.

Входные данные
В единственной строке входного файла INPUT.TXT записано два четырехзначных натуральных числа A и B через пробел, где А – загаданное Петей число, а В – предложенный Васей вариант.

Выходные данные
В выходной файл OUTPUT.TXT нужно вывести два целых числа через пробел — количество быков и коров.
*/

#include <stdio.h>
#include <string.h>

int get_int(FILE * in)
{
    int a;
    fscanf(in, "%d", &a);
    return a;
}

char * get_string(char * str, int n)
{
    //char * str = (char *)malloc(11 * sizeof(char));
    int i;
    int m = n;
    for(i = 0; i < 11; ++i)
    {
        str[i] = (m % 10) + '0';
        m /= 10;
        if(m == 0) break;
    }
    str[++i] = '\0';
    return str;
}
int get_bulls(char * ca, char * cb, int n)
{
    int bulls = 0;
    for(int i = 0; i < n; ++i)
    {
        if(ca[i] == cb[i])
            ++bulls;
    }
    return bulls;
}

int get_cows(char * ca, char * cb, int n)
{
    int a[10] = {0};
    int b[10] = {0};
    int temp = 0;
    int temp1, temp2;
    int cows = 0;
    for(int i = 0; i < n; ++i)
    {
        temp = ca[i] - '0';
        ++a[temp];
        temp = cb[i] - '0';
        ++b[temp];
    }
    for(int i = 0; i < n; ++i)
    {
        temp = ca[i];

        for(int j = 0; j < n; ++j)
            if((i != j) && (cb[j] == temp))
            {
                ++cows;
            }
    }
    return cows;
}
int main()
{

    FILE * in = fopen("input.txt", "r"); if(in == NULL){ printf("Can't open input.txt"); return 0;} 
    FILE * out = fopen("output.txt", "w"); if(out == NULL){ printf("Can't open output.txt"); return 0;} 

    int bulls = 0;
    int cows = 0;
    int a = get_int(in);
    int b = get_int(in);


    char ca[5];
    get_string(ca, a);
    char cb[5];
    get_string(cb, b);

    bulls = get_bulls(ca, cb, 4);
    cows = get_cows(ca, cb, 4);

    fprintf(out,"%d %d", bulls, cows);

    fclose(in);
    fclose(out);
    return 0;
}