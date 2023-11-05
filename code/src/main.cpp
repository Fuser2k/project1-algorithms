/*
Algorithms and Complexity, University of Lodz
Olcay Duzgun
*/

#include <iostream>
#include <format>
#include "sorting/sorting.hpp"
#include <algorithm>

int main()
{
    CSorting *sort = new CSorting({1, 7, 8, 3, 4, 2, 5, 6});

    std::vector<CResult *> Results = {

        sort->SetType(SORT_INSERTION)->WithTest()->Run()->Print(),
        sort->SetType(SORT_QUICK)->WithTest()->Run()->Print(),
        sort->SetType(SORT_RADIX)->WithTest()->Run()->Print(),
        sort->SetType(SORT_HEAP)->WithTest()->Run()->Print()

    };

    //@TODO: I'll use result vector for comparisons

    for (auto res : Results)
        free(res);
    free(sort);
    return 0;
}
