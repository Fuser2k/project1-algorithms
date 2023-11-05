#pragma once
#include <vector>
#include <iostream>
#include <algorithm>

class CResult
{
public:
    CResult(std::vector<int> nums, bool btest = false, long duration = 0, std::string name = "Unknown Algorithm")
    {
        m_numbers = nums;
        m_test = btest;
        m_algorithm = name;
        m_duration = duration;
    }

    CResult *Print()
    {

        if (m_test)
        {
            std::cout << m_algorithm << ": ";
            const bool success = std::is_sorted(m_numbers.cbegin(), m_numbers.cend());
            std::cout << ((success) ? "\033[1;32mSUCCESS\033[0m\n" : "\033[1;31mFAILED\033[0m\n");
        }

        for (auto it : m_numbers)
            std::cout << it << " ";

        std::cout << "\n";

        if (m_test)
        {
            std::cout << "Time taken: " << m_duration << " nanosec\n";
        }
        return this;
    };

    std::vector<int> &GetNumbers()
    {
        return m_numbers;
    }

private:
    std::vector<int> m_numbers;
    std::string m_algorithm;
    bool m_test = false;
    long m_duration = 0;
};

enum EAlgorithmType
{
    SORT_INSERTION,
    SORT_QUICK,
    SORT_RADIX,
    SORT_HEAP
};

class CSorting
{
public:
    CSorting(std::vector<int> vecNumbers)
    {
        m_numbers = vecNumbers;
    }

    CSorting *SetType(EAlgorithmType algorithm)
    {
        m_type = algorithm;
        return this;
    }

    CSorting *WithTest()
    {
        m_runTests = true;
        return this;
    }

    CResult *Insertion();
    CResult *Quick();
    CResult *Radix();
    CResult *Heap();

    CResult *Run()
    {
        switch (m_type)
        {
        case SORT_INSERTION:
            return Insertion();
        case SORT_QUICK:
            return Quick();
        case SORT_RADIX:
            return Radix();
        case SORT_HEAP:
            return Heap();
        default:
            throw("Invalid Type");
        }
    }

private:
    std::vector<int> m_numbers;
    EAlgorithmType m_type;
    bool m_runTests = false;
};