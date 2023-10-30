#include "../sorting.hpp"
#include <algorithm>
std::vector<int> CSorting::Insertion()
{
    std::vector<int> sorted = m_numbers;

    for (int i = 1; i < sorted.size(); i++)
    {
        const int cur_val = sorted.at(i);
        int prev_idx = i - 1;
        while (prev_idx >= 0 && sorted.at(prev_idx) > cur_val)
        {
            std::swap(sorted.at(prev_idx), sorted.at(prev_idx + 1));
            prev_idx--;
        }
    }
    return sorted;
}