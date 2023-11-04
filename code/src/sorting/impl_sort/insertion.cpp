#include "../sorting.hpp"
#include <algorithm>
#include <chrono>
CResult *CSorting::Insertion()
{

    auto start = std::chrono::high_resolution_clock::now();

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

    auto end = std::chrono::high_resolution_clock::now();


    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

    auto res = new CResult(sorted, m_runTests, duration.count(), "Insertion Sort");
    return res;
}