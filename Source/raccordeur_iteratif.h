#ifndef _RACCORDEUR_ITERATIF_H
#define	_RACCORDEUR_ITERATIF_H

#include "limits"
#include "algorithm"
#include "raccordeur.h"

/*!
 * Raccordeur Iteratif: The minimum distance path cut.
 * Sum of the distances over cut point.
 * (x,y) -> [(x-1,y-1); (x, y-1); (x+1,y-1)].
 * Do without Recursif and cached memory (to store minimum distances from that point).
 * With cached memory every point excute one. So it belong to O(h*w) (h = height, w = width of intersection).
 * calculerRaccord(MatInt2* distances, int* coupe): Find the minimun cut (coupe) and return its cost.
*/
class RaccordeurIteratif: public Raccordeur {
  /*!
   * Find the minimun distance path. 
   * Calculate cout and save cut line
  */
  virtual int calculerRaccord(MatInt2* distances, int* coupe); // function pour cout
  virtual ~RaccordeurIteratif(); // destructeur
};

#endif	/* _RACCORDEUR_ITERATIF_H */

