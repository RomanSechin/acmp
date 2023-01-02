/*
ЗАДАЧА №26		
Две окружности
(Время: 1 сек. Память: 16 Мб Сложность: 17%)
На плоскости даны две окружности. Требуется проверить, имеют ли они хотя бы одну общую точку.

Входные данные
Входной файл INPUT.TXT состоит из двух строк. На каждой строке записана информация об одной окружности – координаты ее центра x и y (целые числа, по модулю не превосходящие 5000) и радиус (целое число 1 ≤ r ≤ 1000).

Выходные данные
В выходной файл OUTPUT.TXT выведите «YES», если окружности имеют хотя бы одну общую точку, и «NO» в противном случае.
*/

#include <stdio.h>
#include <math.h>
 
double distance(int x1, int x2, int y1, int y2)
{
  return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}
double diff(int r1, int r2)
{
  if(r1>r2) return r1-r2;
  else return r2-r1;
}
double max(double r1, double r2)
{
  return r1>r2?r1:r2;
}
double min(double r1, double r2)
{
  return r1>r2?r2:r1;
}
int main()
{
    FILE * in = fopen("input.txt", "r");
    FILE * out = fopen("output.txt", "w");
 
    int x1, x2, y1, y2, r1, r2;
 
    fscanf(in, "%d %d %d\n%d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
    double d = distance( x1,  x2,  y1,  y2);
    if((r1+r2) - d < 0.0 || d < max(r1,r2)-min(r1,r2)) fprintf(out, "NO");
    else fprintf(out, "YES");
 
    fclose(in);
    fclose(out);
 
    return 0;
}