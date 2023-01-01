//ЗАДАЧА №12
//Дачники
//(Время: 1 сек. Память: 16 Мб Сложность: 45%)
//Всем известно, что дачники – народ странный, почти такой же, как и программисты.
//Строят они свои дачи непонятно где, да и выращивают там непонятно что и непонятно зачем.
//А уж как они туда добираются, это другая история: кто на автобусе, кто на электричке,
//кто на автомобиле, ну а кто-то вовсе пешком ходит от дома и до самого участка.
//Так что не стоит удивляться, если вдруг Вы узнаете, что некое садоводческое товарищество
//располагается на острове, а дачники добираются до него самолетом. Да еще и на этом острове
//может не быть посадочной полосы, так что высадиться на остров можно, только прыгая с
//парашютом (мы уж не рассматриваем то, как они возвращаются с дач домой).
//Рассмотрим этот уникальный случай. Пилот всегда старается осуществить высадку парашютистов
//таким образом, чтобы дачники приземлялись как можно ближе к своим прямоугольным участкам.
//Пилоту интересно знать: сколько дачников приземлится на свои участки? Помогите ему решить
//эту задачу!
//
//Входные данные
//В первой строке входного файла INPUT.TXT записано натуральное число N (1 ≤ N ≤ 1000) –
//количество дачников, далее идут N строк, в каждой из которых описаны координаты каждого
//дачника и его участка:
//X Y X1 Y1 X2 Y2 X3 Y3 X4 Y4
//где
//(X,Y) – координаты приземления парашютиста
//(X1, Y1, X2, Y2, X3, Y3, X4,Y4) – координаты прямоугольного участка на плоскости,
//указанные последовательно.
//Все координаты – целые числа, не превышающие 50000 по абсолютной величине
//
//Выходные данные
//В выходной файл OUTPUT.TXT нужно вывести количество дачников, приземлившихся на свой участок.
//Попадание на границу участка считается попаданием на участок.
//
//Пример
//№ INPUT.TXT   OUTPUT.TXT
//1 3
//6 6 3 6 6 9 8 7 5 4
//13 5 9 2 9 8 12 8 12 2
//3 2 2 1 2 3 6 3 6 1   2
#include <stdio.h>
#include <stdlib.h>
 
 
int sign(long long x,long long y, long long x1, long long y1, long long x2, long long y2)
{
  if((y-y2)*(x1-x2) - (x - x2)*(y1 - y2) > 0)
    return 1;
  else if((y-y2)*(x1-x2) - (x - x2)*(y1 - y2) < 0)
    return -1;
  else
    return 0;
}
int main()
{
	FILE * in = fopen("input.txt", "r");
    if(in == NULL){printf("Can't open file input.txt!"); return 0;}
    FILE * out = fopen("output.txt", "w");
    if(out == NULL){ printf("Can't open file output.txt!"); fclose(in); return 0; }
 
  long long x[5], y[5];
  int count = 0, ans = 0;
  fscanf(in, "%d", &count);
  long long s1, s2, s3, s4;
  for(int cnt = 0; cnt < count; ++cnt)
  if(fscanf(in, "%lld %lld %lld %lld %lld %lld %lld %lld %lld %lld",
    &x[0], &y[0], &x[1], &y[1], &x[2], &y[2], &x[3], &y[3], &x[4], &y[4]) == 10)
  {
    s1 = sign(x[0], y[0], x[1], y[1], x[2], y[2]);
    s2 = sign(x[0], y[0], x[4], y[4], x[3], y[3]);
    s3 = sign(x[0], y[0], x[2], y[2], x[3], y[3]);
    s4 = sign(x[0], y[0], x[1], y[1], x[4], y[4]);
      if((s1 * s2 <= 0) && (s3 * s4 <= 0))
      ++ans;
  }
  fprintf(out, "%d", ans);
 
  fclose(in);
  fclose(out);
 
  return 0;
}