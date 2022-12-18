#ifndef _PERMUTEUR_H
#define	_PERMUTEUR_H

#include <bits/stdc++.h>

/*!
 *
 * Les instances de cette classe sont des iterateurs sur des permutations
 * aleatoires d'un intervalle donne. Ces instances sont construites en donnant
 * un nombre entier definissant l'intervalle d'interet. Des appels successifs
 * a suivant() permettent d'acceder aux elements de la premiere permutation
 * puis de la seconde et ainsi de suite.
 *
 * Par exemple, si l'on construit une permutation en donnant max=3, on
 * s'interesse alors a des permutations de l'intervalle [0,1,2]. Des appels
 * successifs a suivant pourraient alors renvoyer :
 *  1 2 0  0 2 1  0 1 2  2 1 0  2 1 0  1 0 2 ...
 * Les 18 valeurs successives retournees par les appels a suivant(), une fois
 * groupees par max=3, mettent bien en evidence que l'on retourne les elements
 * d'une permutation, puis d'une autre, ...
 *
 */
class Permuteur {
// A FAIRE : classe a completer au besoin
// A FAIRE : les implementations dans permuteur.cpp

public:

  /*!
   * Construit un nouveau permuteur qui retournera des nombres entiers dans
   * l'intervalle [0 .. (max-1)].
   */
  Permuteur(int max);
  Permuteur(int max, int method); // 0: Dictionary, 1: HeapRecursive, 2: Heap

  /*!
   * Libere les ressources utilisees par ce permuteur.
   */
  ~Permuteur();

  /*!
   * Retourne l'entier suivant.
   */
  int suivant();
  int getLengthPerm();
  void setIndices(int *);

  /*!
   * Using heap to generate Permute.
   * Base on "The following permutation is formed from the previous permutation by permuting 2 elements, the other elements remain in place".
   * If k odd, swap(first, last). Else swap(c, last) (c is counter). Do until c = n
   * For example: (0, 1, 2)
   * k = 3
   *    c = 0, k = 3
   *        c = 0, k = 2
   *            (0, 1, 2)
   *        c = 1, k = 2
   *            (1, 0, 2)
   *    c = 1, k = 3
   *        c = 0, k = 2
   *            (2, 0 , 1)
   *        c = 1, k = 2
   *            (0, 2, 1)
   *    c = 2, k = 3
   *        c = 0, k = 2
   *            (1, 2, 0)
   *        c = 1, k = 2
   *            (2, 1, 0)
  */
  void genPermutHeapRecursive(int k, int &permutationIndex);

  /*!
   * Same with genPermutHeapRecursive but this time not Recursive
   * So we need a counter array to save c
  */
  void genPermutHeap(int k, int &permutationIndex);

  /*!
   * Generate Permutation with Dictionary order
   * While can Find k (last k): A(K) < A(K+1):
   *    Find l (last l): A(K) < A(L)
   *    swap(A(K), A(L));
   *    reverse (A(K+1), A(K+2), ..., A(N))
   * For example: (0, 1, 2)
   * k = 1
   * l = 2 -> (0, 2, 1) -> (0, 2, 1)
   * k = 0
   * l = 2 (last l) -> (1, 2, 0) -> (1, 0, 2)
   * k = 1
   * l = 2 -> (1, 2, 0) -> (1, 2, 0)
   * k = 0
   * l = 1 -> (2, 1, 0) -> (2, 0, 1)
   * k = 1
   * l = 2 -> (2, 1, 0) -> (2, 1, 0)
  */
  void genPermutDictionary();
  
  /*!
   * Assigin _indices to _perm
   * From index permutationIndex*len(_indices) -> (permutationIndex+1)*len(_indices)
  */
  void assignPermutation(int permutationIndex);
  static int factorial(int n);

 private :
  int _max; // max indice
  int _lengthPerm; // To store length of _perm
  int* _perm; // tableau de la permutation.
  int * _indices; // tableau des indices � permuter
  int _i_perm;  // indice d'avancement dans la permutation.

};


#endif	/* _PERMUTEUR_H */

