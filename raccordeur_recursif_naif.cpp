#include "raccordeur_recursif_naif.h"

int RaccordeurRecursifNaif::calculerRaccord(MatInt2* distances, int* coupe)
{
    int *coupeTemp = (int*) malloc(distances->nLignes()*sizeof(int));
    int coutTemp = 0, cout = std::numeric_limits<int>::max();;

    for (int x = 0; x < distances->nColonnes(); x++)
    {
        coutTemp = _calculerRaccord(distances, coupeTemp, x, distances->nLignes()-1);
        if (coutTemp < cout)
        {
            coupe[distances->nLignes()-1] = x;
            std::copy(coupeTemp, coupeTemp+distances->nLignes(), coupe);
            cout = coutTemp;
        }
    }
    return cout;
}

int RaccordeurRecursifNaif::_calculerRaccord(MatInt2* distances, int* coupe, int x, int y)
{
    if (x < 0 || x >= distances->nColonnes()) return std::numeric_limits<int>::max();;
    if (y == 0) return distances->get(y, x);
    else
    {
        int p1 = _calculerRaccord(distances, coupe, x-1, y-1);
        int p2 = _calculerRaccord(distances, coupe, x, y-1);
        int p3 = _calculerRaccord(distances, coupe, x+1, y-1);
        int pMin = std::min(std::min(p1, p2), p3);
        if (p1 == pMin) coupe[y-1] = x-1;
        else if (p2 == pMin) coupe[y-1] = x;
        else coupe[y-1] = x+1;

        return distances->get(y, x) + pMin;
    }

}

RaccordeurRecursifNaif::~RaccordeurRecursifNaif()
{
  // pas de ressources a liberer
}