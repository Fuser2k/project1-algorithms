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

void heap1(std::vector<int> &heap, int root)
{
    int left = 2 * root + 1;
    int right = 2 * root + 2;
    int largest = root;
    int &val_current = heap.at(root);

    if (left < heap.size())
    {
        if (heap.at(left) > heap.at(largest))
            largest = left;
    }
    if (right < heap.size())
    {
        if (heap.at(right) > heap.at(largest))
            largest = right;
    }

    if (largest != root)
    {
        std::swap(heap.at(largest), val_current);

        heap1(heap, largest);
    }
}

int main(int argc, char **argv)
{
#if 0
    CSorting *sort = new CSorting({1, 7, 8, 3, 4, 2, 5, 6});
    // auto vec = sort->Insertion();
    auto vec = sort->Radix();

    for (auto it : vec)
    {
        std::cout << it << " ";
    }
    std::cout << "\n";
#endif

    std::vector<int> data = {4, 10, 3, 5, 1};

    // build heap
    std::vector<int> heap = data;

    for (int i = heap.size() / 2 - 1; i >= 0; i--)
        heap1(heap, i);

    data = heap;


    for (auto it : data)
    {
        std::cout << it << " ";
    }
    std::cout << "\n";

    return 0;
}
