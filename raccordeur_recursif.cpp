#include "raccordeur_recursif.h"

int RaccordeurRecursif::calculerRaccord(MatInt2* distances, int* coupe)
{
    int coutTemp = 0, cout = std::numeric_limits<int>::max();;
    MatInt2* coutTable = new MatInt2(distances->nLignes(), distances->nColonnes()+2);

    for (int i = 0; i < distances->nLignes(); i++)
    {
        coutTable->set(i, 0, std::numeric_limits<int>::max());
        coutTable->set(i, coutTable->nColonnes()-1, std::numeric_limits<int>::max());
    }

    for (int y = 0; y < coutTable->nLignes(); y++)
    {
        for (int x = 1; x < coutTable->nColonnes() - 1; x++)
        {
            coutTable->set(y, x, -1);
        }
    }

    for (int x = 0; x < distances->nColonnes(); x++)
    {
        _calculerRaccord(distances, x+1, distances->nLignes()-1, coutTable);
    }

    int cutx = 0;
    for (int i = 0; i < distances->nColonnes(); i++)
    {
        coutTemp = coutTable->get(coutTable->nLignes()-1, i+1);
        if (coutTemp < cout)
        {
            cout = coutTemp;
            cutx = i;
        }
    }

    coupe[distances->nLignes()-1] = cutx;
    for (int i = coutTable->nLignes() - 2; i >= 0; i--)
    {
        for (int j = -1; j < 2; j++)
        {
            if (coutTable->get(i, cutx + j + 1) + distances->get(i+1, cutx) == coutTable->get(i+1, cutx+1))
            {
                cutx = cutx + j;
                break;
            }
        }
        coupe[i] = cutx;
    } 

    /*
    // debug code. To check coupe same with RaccordeurIteratif and RaccordeurRecursifNaif
    distances->display();
    coutTable->display();
    for (int i = 0; i < distances->nLignes(); i++)
    {
        std::cout << coupe[i] << " ";
    }
    getchar();
    */

    return cout;
}

int RaccordeurRecursif::_calculerRaccord(MatInt2* distances, int x, int y, MatInt2* coutTable)
{
    if (coutTable->get(y, x) == -1)
    {
        if (y == 0) coutTable->set(y, x, distances->get(y, x-1));
        else
        {
            int p1 = _calculerRaccord(distances, x-1, y-1, coutTable);
            int p2 = _calculerRaccord(distances, x, y-1, coutTable);
            int p3 = _calculerRaccord(distances, x+1, y-1, coutTable);

            int pMin = std::min(std::min(p1, p2), p3);
            coutTable->set(y, x, distances->get(y, x-1) + pMin);
        }
    }
    return coutTable->get(y, x);
}

RaccordeurRecursif::~RaccordeurRecursif()
{
  // pas de ressources a liberer
}