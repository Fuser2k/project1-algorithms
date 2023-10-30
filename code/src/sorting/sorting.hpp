#pragma once
#include <vector>

class CSorting {
public:
    CSorting(std::vector<int> vecNumbers){
        m_numbers = vecNumbers;
    }

    std::vector<int> Insertion();
    std::vector<int> Quick();
    std::vector<int> Radix();
    std::vector<int> Heap();

private:
    std::vector<int> m_numbers;
};