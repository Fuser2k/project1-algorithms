#include <iostream>
#include <format>
#include "sorting/sorting.hpp"

int main(int argc, char **argv)
{
    CSorting *sort = new CSorting({1, 7, 8, 3, 4, 2, 5, 6});
    // auto vec = sort->Insertion();
    auto vec = sort->Quick();

    for (auto it : vec)
    {
        std::cout << it << " ";
    }
    std::cout << "\n";

    return 0;
}
