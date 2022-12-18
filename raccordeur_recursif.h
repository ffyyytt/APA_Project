#ifndef _RACCORDEUR_RECURSIF_H
#define	_RACCORDEUR_RECURSIF_H

#include "limits"
#include "algorithm"
#include "raccordeur.h"

/*!
 * Raccordeur Recursif: The minimum distance path cut.
 * sum of the distances over cut point.
 * (x,y) -> [(x-1,y-1); (x, y-1); (x+1,y-1)].
 * Do with Recursif and cached memory (to store minimum distances from that point).
 * With cached memory every point excute one. So it belong to O(h*w) (h = height, w = width of intersection).
 * But with Recursif every time call function add return point to stack -> can be stack overflow.
 * calculerRaccord(MatInt2* distances, int* coupe): Find the minimun cut (coupe) and return its cost.
*/
class RaccordeurRecursif: public Raccordeur {

  /*!
  * Find the minimun distance path. 
  * "calculerRaccord" is abstract function, this will call "_calculerRaccord" to do recursive. 
  * Because we have a lot of start points. (Every point in first line can be start point).
  */
  virtual int calculerRaccord(MatInt2* distances, int* coupe); // function pour cout
  virtual ~RaccordeurRecursif(); // destructeur
  private:
    /*!
    * Do recursive to find the minimun distance path.
    * Start from (x, y) and end when recursive y = 0.
    * RaccordeurRecursif(\see{RaccordeurRecursif#_calculerRaccord})
    */
    int _calculerRaccord(MatInt2* distances, int x, int y, MatInt2* coutTable); //fuction pour recursif
};

#endif	/* _RACCORDEUR_RECURSIF_H */

