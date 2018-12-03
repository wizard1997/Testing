#include "insertion.h"



std::vector<int> Insertion::insertionSort(std::vector<int> & returnVect)
{
    int j, temp;

    for (std::size_t i=1; i < returnVect.size(); i++) {

        j = i;
        temp=returnVect[i];

        while (j>0 && temp < returnVect[j-1]) {
            returnVect[j] = returnVect[j-1];
            j--;
        }

        returnVect[j]=temp;
    }
    return returnVect;
}
