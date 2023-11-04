#include "../sorting.hpp"
#include <algorithm>
CResult* CSorting::Radix()
{
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
    auto res = new CResult(sorted, "Radix Sort");
    return res;
}