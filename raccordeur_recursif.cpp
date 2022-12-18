#include "raccordeur_recursif.h"

int RaccordeurRecursif::calculerRaccord(MatInt2* distances, int* coupe)
{
    int coutTemp = 0, cout = std::numeric_limits<int>::max();;
    MatInt2* coutTable = new MatInt2(distances->nLignes(), distances->nColonnes()+2);

    // Set default coutTable -> -1
    for (int y = 0; y < coutTable->nLignes(); y++)
    {
        for (int x = 1; x < coutTable->nColonnes() - 1; x++)
        {
            coutTable->set(y, x, -1);
        }
    }

    // Set 2 horizontal edges to max_int
    for (int i = 0; i < distances->nLignes(); i++)
    {
        coutTable->set(i, 0, std::numeric_limits<int>::max());
        coutTable->set(i, coutTable->nColonnes()-1, std::numeric_limits<int>::max());
    }

    // calculate coutTable
    for (int x = 0; x < distances->nColonnes(); x++)
    {
        _calculerRaccord(distances, x+1, distances->nLignes()-1, coutTable); //call recursive
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
    if (coutTable->get(y, x) == -1) // if not cached
    {
        if (y == 0) coutTable->set(y, x, distances->get(y, x-1)); // if reached first line
        else
        {
            int p1 = _calculerRaccord(distances, x-1, y-1, coutTable); // calculate min cout end at (x-1, y-1)
            int p2 = _calculerRaccord(distances, x, y-1, coutTable); // calculate min cout end at (x, y-1)
            int p3 = _calculerRaccord(distances, x+1, y-1, coutTable); //calculate min cout end at (x+1, y-1)

            int pMin = std::min(std::min(p1, p2), p3); // get min
            coutTable->set(y, x, distances->get(y, x-1) + pMin); // assign to x, y
        }
    }
    return coutTable->get(y, x);
}

RaccordeurRecursif::~RaccordeurRecursif()
{
  // pas de ressources a liberer
}