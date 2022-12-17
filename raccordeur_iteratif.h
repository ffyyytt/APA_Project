#ifndef _RACCORDEUR_ITERATIF_H
#define	_RACCORDEUR_ITERATIF_H

#include "limits"
#include "algorithm"
#include "raccordeur.h"

class RaccordeurIteratif: public Raccordeur {

  virtual int calculerRaccord(MatInt2* distances, int* coupe); // function pour cout
  virtual ~RaccordeurIteratif(); // destructeur
};

#endif	/* _RACCORDEUR_ITERATIF_H */

