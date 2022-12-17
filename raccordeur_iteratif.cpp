#include "raccordeur_iteratif.h"

int RaccordeurIteratif::calculerRaccord(MatInt2* distances, int* coupe)
{
    int coutTemp = 0, cout = std::numeric_limits<int>::max();;
    MatInt2* coutTable = new MatInt2(distances->nLignes(), distances->nColonnes()+2);

    for (int i = 0; i < distances->nLignes(); i++)
    {
        coutTable->set(i, 0, std::numeric_limits<int>::max());
        coutTable->set(i, coutTable->nColonnes()-1, std::numeric_limits<int>::max());
    }

    for (int x = 0; x < distances->nColonnes(); x++)
    {
        coutTable->set(0, x+1, distances->get(0, x));
    }

    for (int y = 1; y < coutTable->nLignes(); y++)
    {
        for (int x = 0; x < distances->nColonnes(); x++)
        {
            coutTable->set(y, x+1, distances->get(y, x) + 
            std::min(std::min(coutTable->get(y-1, x), coutTable->get(y-1, x+1)), coutTable->get(y-1, x+2)));
        }
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
    // debug code. To check coupe same with RaccordeurRecursif and RaccordeurRecursifNaif
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

RaccordeurIteratif::~RaccordeurIteratif()
{
  // pas de ressources a liberer
}