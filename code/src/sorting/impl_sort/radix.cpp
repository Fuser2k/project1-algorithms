#include "../sorting.hpp"
#include <algorithm>
#include <chrono>
/*
Complexity: O(MAX_NUMBER_OF_DIGITS * (n + SIZE_OF_NUMBER))

NOTE: SIZE_OF_NUMBER is 4 bytes

Description:
[
   The algorithm is straight-forward to understand.
    We are sorting the numbers by checking their digits. Let's say we have an array that contains 14, 62, 733, 610.
    We sorting from their first digits, 610, 62, 733, 14
    Then we are applying same logic for second digit and so on.
]
*/

CResult *CSorting::Radix()
{
    auto start = std::chrono::steady_clock::now();

    std::vector<int> sorted = m_numbers;

    int largest_element = *std::max_element(std::begin(sorted), std::end(sorted));

    for (int exp = 1; largest_element / exp > 0; exp *= 10)
    {
        auto compare_digits = [exp](int left, int right)
        {
            const int left_digit_value = (left / exp % 10);
            const int right_digit_value = (right / exp % 10);
            return left_digit_value < right_digit_value;
        };

        std::sort(sorted.begin(), sorted.end(), compare_digits);
    }
    auto end = std::chrono::steady_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

    auto res = new CResult(sorted, m_runTests, duration.count(), "Radix Sort");
    return res;
}