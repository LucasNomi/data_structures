#include <stdio.h>
#include <stdlib.h>

int
main()
{
  float notas[2];
  float sum = 0.0;

  for (int i = 0; i < 2; i++) {
    printf("%d nota do aluno: ", i+1);
    setbuf(stdin, NULL);
    scanf("%f", &notas[i]);
    sum += notas[i];
  }
  
  float media = sum/2.0;
  if (media >= 6.0)
    printf("APROVADO\n");
  else
    printf("REPROVADO\n");

  return 0;
}
