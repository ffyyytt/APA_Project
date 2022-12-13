#include "permuteur.h"

Permuteur::Permuteur(int max)
{
    _max = max;
    _lengthPerm = factorial(_max)*_max;
    _indices = (int*) malloc(_max*sizeof(int));
    _perm = (int*) malloc(_lengthPerm*sizeof(int));

    setIndices(_indices);
    genPermutDictionary();
}

Permuteur::~Permuteur()
{
    delete[] _indices;
    delete[] _perm;
}

int Permuteur::suivant()
{
    _i_perm = _i_perm%_lengthPerm;
    return _perm[_i_perm++];
}

void Permuteur::setIndices(int * indices)
{
    for (int i = 0; i < _max; i++)
        indices[i] = i;
}

void Permuteur::genPermutDictionary()
{
    int permutationIndex = 0;
    int k, l;
    while (true)
    {
        assignPermutation(permutationIndex++);
        for (k = _max-2; k>=0; k--) if (_indices[k] < _indices[k+1]) break;
        if (k<0) break;
        for (l = _max-1; l>k; l--) if (_indices[k] < _indices[l]) break;
        std::swap(_indices[k], _indices[l]);
        for (int i=k+1, j=_max-1; i<j; i++, j--) std::swap(_indices[i], _indices[j]);
    }
    setIndices(_indices);
}

void Permuteur::assignPermutation(int permutationIndex)
{
    for (int i = 0; i < _max; i++)
        _perm[permutationIndex*_max + i] = _indices[i];
}

int Permuteur::factorial(int n)
{
    int result = n;
    for (int i = n-1; i > 1; i--)
        result *= i;
    return result;
}