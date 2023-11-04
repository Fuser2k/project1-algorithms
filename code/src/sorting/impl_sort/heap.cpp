#include "../sorting.hpp"
#include <algorithm>
#include <chrono>

/*
Complexity: O(nlog n)

Description:
[
    We are generating a binary tree using our numbers.
    Our first number will be root at the start and next element added as left element and next one is right element.
    Then we add other numbers like this (adding other numbers to left as left and right again)
    And we check if greater child element is greater than parent, if it is we swap them.
    We continue doing this for generating max heap.

    After generating final max heap,
    we remove root (largest number) from heap and swap it with last element in vector.
]
*/

// Forward declerations
void gen_heap(std::vector<int> &heap, int maxval, int root);

CResult *CSorting::Heap()
{
    auto start = std::chrono::high_resolution_clock::now();

    std::vector<int> heap = m_numbers;

    for (int i = heap.size() / 2 - 1; i >= 0; i--)
    {
        gen_heap(heap, heap.size(), i);
    }

    // Now we are using heap for every element to sort.
    for (int i = heap.size() - 1; i > 0; i--)
    {
        std::swap(heap.at(0), heap.at(i)); // swap root with the last element

        gen_heap(heap, i, 0); // doing it again with the new root
    }
    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

    auto res = new CResult(heap, m_runTests, duration.count(), "Heap Sort");
    return res;
}

void gen_heap(std::vector<int> &heap, int maxval, int root)
{
    int left = 2 * root + 1;
    int right = 2 * root + 2;
    int largest = root;
    int &val_current = heap.at(root);

    if (left < maxval)
    {
        if (heap.at(left) > heap.at(largest))
            largest = left;
    }
    if (right < maxval)
    {
        if (heap.at(right) > heap.at(largest))
            largest = right;
    }

    if (largest != root)
    {
        std::swap(heap.at(largest), val_current);

        gen_heap(heap, maxval, largest);
    }
}