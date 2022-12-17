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
            std::copy(coupeTemp, coupeTemp+distances->nLignes(), coupe);
            coupe[distances->nLignes()-1] = x;
            cout = coutTemp;
        }
    }

    /*
    // debug code. To check coupe same with RaccordeurIteratif and RaccordeurRecursif
    distances->display();
    for (int i = 0; i < distances->nLignes(); i++)
    {
        std::cout << coupe[i] << " ";
    }
    getchar();
    */

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
        if (p1 == pMin) 
        {
            _calculerRaccord(distances, coupe, x-1, y-1);
            coupe[y-1] = x-1;
        }
        else if (p2 == pMin) 
        {
            _calculerRaccord(distances, coupe, x, y-1);
            coupe[y-1] = x;
        }
        else 
        {
            _calculerRaccord(distances, coupe, x+1, y-1);
            coupe[y-1] = x+1;
        }

        return distances->get(y, x) + pMin;
    }
}

int RaccordeurRecursifNaif::_calculerRaccordMemPath(MatInt2* distances, int* coupe, int x, int y)
{
    if (x < 0 || x >= distances->nColonnes()) return std::numeric_limits<int>::max();;
    if (y == 0) return distances->get(y, x);
    else
    {
        int* couptTemp = (int*) malloc(distances->nLignes()*sizeof(int));
        int pMin = _calculerRaccordMemPath(distances, coupe, x-1, y-1);
        coupe[y-1] = x-1;
        int p = _calculerRaccordMemPath(distances, couptTemp, x, y-1);
        if (p < pMin)
        {
            pMin = p;
            std::copy(couptTemp, couptTemp+y-2, coupe);
            coupe[y-1] = x;
        }
        std::cout << x << " " << y << std::endl;
        p = _calculerRaccord(distances, couptTemp, x+1, y-1);
        if (p < pMin)
        {
            pMin = p;
            std::copy(couptTemp, couptTemp+y-2, coupe);
            coupe[y-1] = x+1;
        }
        return distances->get(y, x) + pMin;
    }
}

RaccordeurRecursifNaif::~RaccordeurRecursifNaif()
{
  // pas de ressources a liberer
}