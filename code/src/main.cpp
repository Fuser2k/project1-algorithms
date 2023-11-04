#include <iostream>
#include <format>
#include "sorting/sorting.hpp"
#include <algorithm> // for heap

struct Heap
{
    int val;
    Heap *parent;
    Heap *prev;
    Heap *left;
    Heap *right;
};



int main(int argc, char **argv)
{
    CSorting *sort = new CSorting({1, 7, 8, 3, 4, 2, 5, 6});
    auto vec = sort->Heap();

    for (auto it : vec)
    {
        std::cout << it << " ";
    }
    std::cout << "\n";

    return 0;
}
