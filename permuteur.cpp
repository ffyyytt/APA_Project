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

Permuteur::Permuteur(int max, int method)
{
    _max = max;
    _lengthPerm = factorial(_max)*_max;
    _indices = (int*) malloc(_max*sizeof(int));
    _perm = (int*) malloc(_lengthPerm*sizeof(int));

    setIndices(_indices);
    int permutationIndex = 0;
    switch (method)
    {
        case 0:
            genPermutDictionary();
            break;
        case 1:
            genPermutHeapRecursive(_max, permutationIndex);
            break;
        case 2:
            genPermutHeap(_max, permutationIndex);
            break;
    } 
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

int Permuteur::getLengthPerm()
{
    return _lengthPerm;
}

void Permuteur::setIndices(int * indices)
{
    for (int i = 0; i < _max; i++)
        indices[i] = i;
}

void Permuteur::genPermutHeapRecursive(int k, int &permutationIndex)
{
    if (k < 2) return assignPermutation(permutationIndex++);
    for (int i=0; i<k-1; i++) {
        genPermutHeapRecursive(k-1, permutationIndex);
        if (k%2==0) std::swap(_indices[i], _indices[k-1]);
        else std::swap(_indices[0], _indices[k-1]);
    }
    genPermutHeapRecursive(k-1, permutationIndex);
    setIndices(_indices);
}


void Permuteur::genPermutHeap(int k, int &permutationIndex)
{
    int *counter = (int*) malloc(_max*sizeof(int));
    memset(counter, 0, _max*sizeof(int));
    int i=0;
    while (i<k) {
        if (counter[i] < i) {
            if (i%2 == 0) std::swap(_indices[0], _indices[i]);
            else std::swap(_indices[counter[i]], _indices[i]);
            assignPermutation(permutationIndex++);
            counter[i]++;
            i = 0;
        } else counter[i++] = 0;
    }
    setIndices(_indices);
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