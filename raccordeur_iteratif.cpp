#include "raccordeur_iteratif.h"

int RaccordeurIteratif::calculerRaccord(MatInt2* distances, int* coupe)
{
    int coutTemp = 0, cout = std::numeric_limits<int>::max();;
    MatInt2* coutTable = new MatInt2(distances->nLignes(), distances->nColonnes()+2);

    // Set 2 horizontal edges to max_int
    for (int i = 0; i < distances->nLignes(); i++)
    {
        coutTable->set(i, 0, std::numeric_limits<int>::max());
        coutTable->set(i, coutTable->nColonnes()-1, std::numeric_limits<int>::max());
    }

    // Set first line to distances
    for (int x = 0; x < distances->nColonnes(); x++)
    {
        coutTable->set(0, x+1, distances->get(0, x));
    }

    // calculate coutTable
    for (int y = 1; y < coutTable->nLignes(); y++)
    {
        for (int x = 0; x < distances->nColonnes(); x++)
        {
            // E(ij) = D(ij) + Min(E(i-1, j-1), E(i, j-1), E(i+1, j-1))
            coutTable->set(y, x+1, distances->get(y, x) + 
            std::min(std::min(coutTable->get(y-1, x), coutTable->get(y-1, x+1)), coutTable->get(y-1, x+2)));
        }
    }

    // Find minimum cout on last line
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

    // Start from last line, column = cutx (minimum cout on last line)
    // Backwark to line 0
    // To find minimum cut
    coupe[distances->nLignes()-1] = cutx;
    for (int i = coutTable->nLignes() - 2; i >= 0; i--)
    {
        for (int j = -1; j < 2; j++) // j = -1, j = 0, j = 1
        {
            if (coutTable->get(i, cutx + j + 1) + distances->get(i+1, cutx) == coutTable->get(i+1, cutx+1)) // find which previous cout + distance = current cout
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