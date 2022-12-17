#ifndef _RACCORDEUR_RECURSIF_NAIF_H
#define	_RACCORDEUR_RECURSIF_NAIF_H

#include "limits"
#include "algorithm"
#include "raccordeur.h"

/*!
 * Raccordeur Recursif Naif: The minimum distance path cut.
 * sum of the distances over cut point.
 * (x,y) -> [(x-1,y-1); (x, y-1); (x+1,y-1)].
 * Do with only recursive. So its took O(3^h) for every start point in first line.
 * So totally O(w*3^h) (h = height, w = width of intersection).
 * calculerRaccord(MatInt2* distances, int* coupe): Find the minimun cut (coupe) and return its cost.
*/
class RaccordeurRecursifNaif: public Raccordeur {
  virtual int calculerRaccord(MatInt2* distances, int* coupe);
  virtual ~RaccordeurRecursifNaif();
  private:
    int _calculerRaccord(MatInt2* distances, int* coupe, int x, int y);
    int _calculerRaccordMemPath(MatInt2* distances, int* coupe, int x, int y);
};

#endif	/* _RACCORDEUR_RECURSIF_NAIF_H */

