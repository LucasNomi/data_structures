#include <stdio.h>
#include <stdlib.h>

#define N 10

int
main()
{
  int m[N][N];
  int sum = 0;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i % 2 == 0)
        sum += m[i][j];
    }
  }

  return 0;
}
