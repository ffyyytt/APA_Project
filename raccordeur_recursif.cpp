#include "raccordeur_recursif.h"
#include "iostream"

int RaccordeurRecursif::calculerRaccord(MatInt2* distances, int* coupe)
{
    int *coupeTemp = (int*) malloc(distances->nLignes()*sizeof(int));
    int coutTemp = 0, cout = std::numeric_limits<int>::max();;
    MatInt2* coutTable = new MatInt2(distances->nColonnes(), distances->nLignes());

    for (int y = 0; y < coutTable->nLignes(); y++)
    {
        for (int x = 0; x < coutTable->nColonnes(); x++)
        {
            coutTable->set(y, x, -1);
        }
    }

    for (int x = 0; x < distances->nColonnes(); x++)
    {
        coutTemp = _calculerRaccord(distances, coupeTemp, x, distances->nLignes()-1, coutTable);
        if (coutTemp < cout)
        {
            coupe[distances->nLignes()-1] = x;
            std::copy(coupeTemp, coupeTemp+distances->nLignes(), coupe);
            cout = coutTemp;
        }
    }
    return cout;
}

int RaccordeurRecursif::_calculerRaccord(MatInt2* distances, int* coupe, int x, int y, MatInt2* coutTable)
{
    if (x < 0 || x >= distances->nColonnes()) return std::numeric_limits<int>::max();
    else if (coutTable->get(x, y) == -1)
    {
        if (y == 0) coutTable->set(x, y, distances->get(y, x));
        else
        {
            int p1 = _calculerRaccord(distances, coupe, x-1, y-1, coutTable);
            int p2 = _calculerRaccord(distances, coupe, x, y-1, coutTable);
            int p3 = _calculerRaccord(distances, coupe, x+1, y-1, coutTable);

            int pMin = std::min(std::min(p1, p2), p3);
            if (p1 == pMin) coupe[y-1] = x-1;
            else if (p2 == pMin) coupe[y-1] = x;
            else coupe[y-1] = x+1;

            coutTable->set(x, y, distances->get(y, x) + pMin);
        }
    }
    return coutTable->get(x, y);
}

RaccordeurRecursif::~RaccordeurRecursif()
{
  // pas de ressources a liberer
}