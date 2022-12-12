#include <stdio.h>
int main(){

  int n, i = 3, count, c;

//  scanf("%d", &n);


  for (count = 2; count <= 1000000000;)
  {
    for (c = 2; c <= i - 1; c++)
    {
      if (i%c == 0)
        break;
    }
    if (c == i)
    {
//      printf("%d\n", i);
      count++;
    }
    i++;
  }

  printf("%d\n", count);

  return 0;
}
