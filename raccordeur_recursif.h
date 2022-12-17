#ifndef _RACCORDEUR_RECURSIF_H
#define	_RACCORDEUR_RECURSIF_H

#include "limits"
#include "algorithm"
#include "raccordeur.h"

/*!
 * Raccordeur simple : il coupe au milieu et calcule le cout du raccord comme
 * etant la somme des distances sur la zone de recouvrement.
 *
 * Cette classe est une classe concrete et derive/implemente le concept de
 * Raccordeur (\see{Raccordeur}).
 */
class RaccordeurRecursif: public Raccordeur {

  /*!
   * le calcul du raccord (\see{Raccordeur#calculerRaccord}).
   * Le code effectif se trouve dans RaccordeurSimple.cpp
   */
  virtual int calculerRaccord(MatInt2* distances, int* coupe);
  virtual ~RaccordeurRecursif(); // destructeur
  private:
    int _calculerRaccord(MatInt2* distances, int* coupe, int x, int y, MatInt2* coutTable);

};

#endif	/* _RACCORDEUR_RECURSIF_H */

