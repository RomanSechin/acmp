/*
ЗАДАЧА №15		
Дороги
(Время: 1 сек. Память: 16 Мб Сложность: 18%)
В галактике «Milky Way» на планете «Snowflake» есть N городов, некоторые из которых соединены дорогами. Император галактики «Milky Way» решил провести инвентаризацию дорог на планете «Snowflake». Но, как оказалось, он не силен в математике, поэтому он просит вас сосчитать количество дорог. Требуется написать программу, помогающую императору сосчитать количество дорог на планете «Snowflake».

Входные данные
В первой строке входного файла INPUT.TXT записано число N (0 ≤ N ≤ 100). В следующих N строках записано по N чисел, каждое из которых является единичкой или ноликом. Причем, если в позиции (i, j) квадратной матрицы стоит единичка, то i-ый и j-ый города соединены дорогами, а если нолик, то не соединены. Гарантируется, что все дороги соединяют различные города.

Выходные данные
В выходной файл OUTPUT.TXT необходимо вывести число, определяющее количество дорог на планете «Snowflake».
*/

#include <stdio.h>
#include <stdlib.h>
 
int main()
{
  FILE * in = fopen("input.txt", "r"); if(in == NULL){ printf("Can't open input.txt"); return 0;} 
  FILE * out = fopen("output.txt", "w"); if(out == NULL){ printf("Can't open output.txt"); return 0;}
  
  int n;
  int result = 0;
  fscanf(in, "%d", &n);
  int temp = 0;
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j)
  {
    fscanf(in, "%d", &temp);
    result += temp;
  }
 
  fprintf(out, "%d", result/2);
  fclose(in);
  fclose(out);
 
  return 0;
}