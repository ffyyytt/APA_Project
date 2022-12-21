#include <time.h>
#include <stdio.h>
#include "permuteur.h"

int main(int argc, char** argv) {
  int n = 3;
  Permuteur *p0 = new Permuteur(n);
  Permuteur *p1 = new Permuteur(n, 1);
  Permuteur *p2 = new Permuteur(n, 2);
  printf("Test n = 3, total permutations: %d\n", Permuteur::factorial(n));
  printf("Method 0 \t|\t Method 1 \t|\t Method 2\n");
  for (int i = 0; i < Permuteur::factorial(n); i++)
  {
    for (int j = 0; j < n; j++)
    {
      printf("%d  ", p0->suivant());
    }

    printf("\t|\t");

    for (int j = 0; j < n; j++)
    {
      printf("%d  ", p1->suivant());
    }

    printf("\t|\t");

    for (int j = 0; j < n; j++)
    {
      printf("%d  ", p2->suivant());
    }
    
    printf("\n");
  }

  p0->~Permuteur();
  p1->~Permuteur();
  p2->~Permuteur();

  printf("Test time:\n");
  n = 1;
  clock_t tStart;
  for (n = 0; n < 12; n++)
  {
    for (int method = 0; method < 3; method ++)
    {
      tStart = clock();
      Permuteur *p = new Permuteur(n, method);
      printf("N = %d, method: %d, lengthPerm: %d, time taken: %.2fs\n", n, method, p->getLengthPerm(), (double)(clock() - tStart)/CLOCKS_PER_SEC);
      p->~Permuteur();
    }
  }
  return 0;
}

