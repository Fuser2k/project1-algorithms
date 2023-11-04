/*
Algorithms and Complexity, University of Lodz
Olcay Duzgun
*/

#include <iostream>
#include <format>
#include "sorting/sorting.hpp"
#include <algorithm>

int main(/*int argc, char **argv*/)
{
    CSorting *sort = new CSorting({1, 7, 8, 3, 4, 2, 5, 6});

    auto InsertionTest = sort->SetType(SORT_INSERTION)->WithTest()->Run()->Print();
    auto QuickTest = sort->SetType(SORT_QUICK)->WithTest()->Run()->Print();
    auto RadixTest = sort->SetType(SORT_RADIX)->WithTest()->Run()->Print();
    auto HeapTest = sort->SetType(SORT_HEAP)->WithTest()->Run()->Print();

    free(InsertionTest);
    free(QuickTest);
    free(RadixTest);
    free(HeapTest);

    free(sort);
    return 0;
}
