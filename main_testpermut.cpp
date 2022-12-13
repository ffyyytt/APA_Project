#include <time.h>
#include <stdio.h>
#include "permuteur.h"

int main(int argc, char** argv) {
  int n = 3;
  Permuteur *p = new Permuteur(n);
  printf("Test n = 3, total permutations: %d\n", Permuteur::factorial(n));
  for (int i = 0; i < Permuteur::factorial(n)*n; i++)
  {
    printf("%d  ",p->suivant());
    if (i % n == n-1)
      printf("\n");
  }
  p->~Permuteur();
  printf("Test time:\n");
  n = 1;
  clock_t tStart;
  for (int i = 0; i < 8; i++)
  {
    n *= 10;
    tStart = clock();
    Permuteur *p = new Permuteur(n);
    printf("N = 1, time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    p->~Permuteur();
  }
  return 0;
}

