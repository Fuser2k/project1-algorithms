#include "../sorting.hpp"
#include <algorithm>
#include <functional>
#include <chrono>

/*
Description:
[
   As of my observations, quick sort is the fastest sorting algorithm for large data sets.
   For the small data sets, insertion sort is the fastest sorting algorithm.
   So, I have implemented a hybrid sorting algorithm which uses quick sort for large data sets and insertion sort for small data sets.
]
*/

// Forward declerations
int QuickSort_Partition_Internal(std::vector<int> &sorted, int low, int high);
void QuickSort_Internal(std::vector<int> &sorted, int low, int high);

CResult *CSorting::Hybrid()
{
    if (m_numbers.size() <= 12)
    {
        auto start = std::chrono::steady_clock::now();

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

        auto end = std::chrono::steady_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

        auto res = new CResult(sorted, m_runTests, duration.count(), "Hybrid Sort");
        return res;
    }
    else
    {
        auto start = std::chrono::steady_clock::now();

        std::vector<int> sorted = m_numbers;

        QuickSort_Internal(sorted, 0, sorted.size() - 1);

        auto end = std::chrono::steady_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

        auto res = new CResult(sorted, m_runTests, duration.count(), "Hybrid Sort");
        return res;
    }
}
