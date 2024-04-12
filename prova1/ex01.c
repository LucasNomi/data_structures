#include <stdio.h>
#include <stdlib.h>

int
main()
{
  int a; int b = 4; a = b++;
  printf("a=%d e b=%d\n",a,b);

  return 0;
}
