#ifndef _RACCORDEUR_RECURSIF_NAIF_H
#define	_RACCORDEUR_RECURSIF_NAIF_H

#include "limits"
#include "algorithm"
#include "raccordeur.h"

/*!
 * Raccordeur Recursif Naif: The minimum distance path cut.
 * sum of the distances over cut point.
 * (x,y) -> [(x-1,y-1); (x, y-1); (x+1,y-1)].
 * Do with only recursive. So its took O(4^h) for every start point in first line.
 * So totally O(w*4^h) (h = height, w = width of intersection).
 * O(w*3^h) for cost only (without cut)
 * calculerRaccord(MatInt2* distances, int* coupe): Find the minimun cut (coupe) and return its cost.
*/
class RaccordeurRecursifNaif: public Raccordeur {
  /*!
  * Find the minimun distance path. 
  * "calculerRaccord" is abstract function, this will call "_calculerRaccord" to do recursive.
  * We can change _calculerRaccord to _calculerRaccordMemPath.
  * _calculerRaccord: found min previous cout -> travel again to set cut
  * __calculerRaccordMemPath: every time go to previous cout, create new cut to save. Need a really large RAM to run.
  * Because we have a lot of start points. (Every point in first line can be start point).
  */
  virtual int calculerRaccord(MatInt2* distances, int* coupe);
  virtual ~RaccordeurRecursifNaif(); // destructeur
  private:
    /*!
     * boolean to use save cut path
     * if true call _calculerRaccordMemPath instead of _calculerRaccord
     * read _calculerRaccord and _calculerRaccordMemPath for more information
    */
    bool _memoryCut = false;
    /*!
     * Do recursive to find the minimun distance path.
     * Start from (x, y) parameters and end when recursive y = 0.
     * When found min, do travel again to assign cut.
     * O(4^n)
    */
    int _calculerRaccord(MatInt2* distances, int* coupe, int x, int y);
    
    /*!
     * Do recursive to find the minimun distance path.
     * Start from (x, y) parameters and end when recursive y = 0.
     * For each time (xi, yi) create new cut_i to save min cut
     * Then set cut_i to cut
     * O(3^n)
     * But memory: T(n*2^n) (n = height)
    */
    int _calculerRaccordMemPath(MatInt2* distances, int* coupe, int x, int y);
    public:
      RaccordeurRecursifNaif(bool memoryCut);
};

#endif	/* _RACCORDEUR_RECURSIF_NAIF_H */

