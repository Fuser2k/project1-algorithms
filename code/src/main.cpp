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

    auto InsertionTest = sort->SetType(SORT_INSERTION)->Run()->Print(true);
    auto QuickTest = sort->SetType(SORT_QUICK)->Run()->Print(true);

    free(InsertionTest);
    free(QuickTest);

    free(sort);
    return 0;
}
