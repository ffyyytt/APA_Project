#include "raccordeur_recursif_naif.h"

RaccordeurRecursifNaif::RaccordeurRecursifNaif(bool memoryCut)
{
    _memoryCut = memoryCut;
}

int RaccordeurRecursifNaif::calculerRaccord(MatInt2* distances, int* coupe)
{
    int *coupeTemp = (int*) malloc(distances->nLignes()*sizeof(int)); //to save cut for every start(x, distances->nLignes()-1)
    int coutTemp = 0, cout = std::numeric_limits<int>::max(); //to save cout for every start(x, distances->nLignes()-1)

    //
    for (int x = 0; x < distances->nColonnes(); x++)
    {
        if (_memoryCut)
            coutTemp = _calculerRaccordMemPath(distances, coupeTemp, x, distances->nLignes()-1); // cal recursive new array to save cut
        else
            coutTemp = _calculerRaccord(distances, coupeTemp, x, distances->nLignes()-1); // cal recursive normal
        if (coutTemp < cout) // if coutTemp < cout
        {
            std::copy(coupeTemp, coupeTemp+distances->nLignes(), coupe); // copy cutTemp to cut
            coupe[distances->nLignes()-1] = x; //set last point
            cout = coutTemp; //set cout
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
    if (x < 0 || x >= distances->nColonnes()) return std::numeric_limits<int>::max(); // if reached horizontal edge
    if (y == 0) return distances->get(y, x); // if reached first line
    else
    {   
        int p1 = _calculerRaccord(distances, coupe, x-1, y-1); // calculate min cout end at (x-1, y-1)
        int p2 = _calculerRaccord(distances, coupe, x, y-1); // calculate min cout end at (x, y-1)
        int p3 = _calculerRaccord(distances, coupe, x+1, y-1); //calculate min cout end at (x+1, y-1)
        int pMin = std::min(std::min(p1, p2), p3);  // get min
        if (p1 == pMin) 
        {
            _calculerRaccord(distances, coupe, x-1, y-1); // travel again to get cut path
            coupe[y-1] = x-1; // set last point
        }
        else if (p2 == pMin) 
        {
            _calculerRaccord(distances, coupe, x, y-1); // travel again to get cut path
            coupe[y-1] = x; // set last point
        }
        else 
        {
            _calculerRaccord(distances, coupe, x+1, y-1); // travel again to get cut path
            coupe[y-1] = x+1; // set last point
        }

        return distances->get(y, x) + pMin; // return cout at this point
    }
}

int RaccordeurRecursifNaif::_calculerRaccordMemPath(MatInt2* distances, int* coupe, int x, int y)
{
    if (x < 0 || x >= distances->nColonnes()) return std::numeric_limits<int>::max(); // if reached horizontal edge
    if (y == 0) return distances->get(y, x); // if reached first line
    else
    {
        int* coupeTemp = (int*) malloc(distances->nLignes()*sizeof(int)); // create new cut line
        int pMin = _calculerRaccordMemPath(distances, coupe, x-1, y-1); // calculate min cout end at (x-1, y-1) and assign coupe
        coupe[y-1] = x-1; // set last point
        int p = _calculerRaccordMemPath(distances, coupeTemp, x, y-1); // calculate min cout end at (x, y-1) and assign to couptTemp
        if (p < pMin) // if cout(x, y-1) < cout min
        {
            pMin = p;
            std::copy(coupeTemp, coupeTemp+distances->nLignes(), coupe); // copy cut line
            coupe[y-1] = x;
        }
        p = _calculerRaccordMemPath(distances, coupeTemp, x+1, y-1);
        if (p < pMin) // if cout(x+1, y-1) < cout min
        {
            pMin = p;
            std::copy(coupeTemp, coupeTemp+distances->nLignes(), coupe); // copy cut line
            coupe[y-1] = x+1;
        }
        return distances->get(y, x) + pMin; // return cout at this point
    }
}

RaccordeurRecursifNaif::~RaccordeurRecursifNaif()
{
  // pas de ressources a liberer
}