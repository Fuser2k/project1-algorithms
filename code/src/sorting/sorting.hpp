#pragma once
#include <vector>
#include <iostream>

class CResult
{
public:
    CResult(std::vector<int> nums, std::string name = "Unknown Algorithm")
    {
        m_numbers = nums;
        m_algorithm = name;
    }

    CResult *Print(bool details = false) // pass true to include algorithm name
    {
        if (details)
            std::cout << m_algorithm << ": ";
        for (auto it : m_numbers)
            std::cout << it << " ";

        std::cout << "\n";

        return this;
    };

    std::vector<int> &GetNumbers()
    {
        return m_numbers;
    }

private:
    std::vector<int> m_numbers;
    std::string m_algorithm;
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
        throw("TODO: not implemented yet");
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
};