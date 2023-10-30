#include "../sorting.hpp"
#include <algorithm>
#include <functional>

extern int QuickSort_Partition_Internal(std::vector<int> &sorted, int low, int high);
extern void QuickSort_Internal(std::vector<int> &sorted, int low, int high);

std::vector<int> CSorting::Quick()
{
    std::vector<int> sorted = m_numbers;

    QuickSort_Internal(sorted, 0, sorted.size() - 1);
    return sorted;
}

int QuickSort_Partition_Internal(std::vector<int> &sorted, int low, int high)
{
    const int pivot = sorted.at(high);
    int part_index = low;
    for (int j = low; j <= high; j++)
    {
        if (sorted.at(j) < pivot)
        {
            std::swap(sorted.at(part_index), sorted.at(j));
            part_index++;
        }
    }
    std::swap(sorted.at(part_index), sorted.at(high));
    return part_index;
}
void QuickSort_Internal(std::vector<int> &sorted, int low, int high)
{
    if (low >= high)
        return;

    const int divided = QuickSort_Partition_Internal(sorted, low, high);
    QuickSort_Internal(sorted, low, divided - 1);
    QuickSort_Internal(sorted, divided + 1, high);
}