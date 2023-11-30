/*
Algorithms and Complexity, University of Lodz
Olcay Duzgun
*/

#include <iostream>
#include <format>
#include "sorting/sorting.hpp"
#include <algorithm>


std::vector<int> GenerateRandomNumbers(int size)
{
    std::vector<int> numbers;
    for (int i = 0; i < size; i++)
        numbers.push_back(rand() % 1000);
    return numbers;
}

void PrintTableRow(int size)
{
    CSorting *sort = new CSorting(GenerateRandomNumbers(size));
    auto insertion =  sort->SetType(SORT_INSERTION)->WithTest()->Run();
    auto quick =  sort->SetType(SORT_QUICK)->WithTest()->Run();
    auto radix =  sort->SetType(SORT_RADIX)->WithTest()->Run();
    auto heap =  sort->SetType(SORT_HEAP)->WithTest()->Run();
    auto hybrid =  sort->SetType(SORT_HYBRID)->WithTest()->Run();

    std::cout << size << " " << insertion->GetDuration() << " " << quick->GetDuration() << " " << radix->GetDuration() << " " << heap->GetDuration() << " " << hybrid->GetDuration() << "\n";

    free(insertion);
    free(quick);
    free(radix);
    free(heap);
    free(hybrid);
    free(sort);
}

void PrintAll(int size)
{
    CSorting *sort = new CSorting(GenerateRandomNumbers(size));
    auto insertion =  sort->SetType(SORT_INSERTION)->WithTest()->Run()->Print();
    auto quick =  sort->SetType(SORT_QUICK)->WithTest()->Run()->Print();
    auto radix =  sort->SetType(SORT_RADIX)->WithTest()->Run()->Print();
    auto heap =  sort->SetType(SORT_HEAP)->WithTest()->Run()->Print();
    auto hybrid =  sort->SetType(SORT_HYBRID)->WithTest()->Run()->Print();

    free(insertion);
    free(quick);
    free(radix);
    free(heap);
    free(hybrid);
    free(sort);
}
int main()
{
    PrintAll(20); // for testing

    std::cout << "size" << " " << "insertion" << " " << "quick" << " " << "radix" << " " << "heap" << " " << "hybrid" << "\n";
    
    for(int i = 1; i < 10; i++)
        PrintTableRow(i);

    for(int i = 10; i < 100; i += 10)
        PrintTableRow(i);

    for(int i = 100; i < 1000; i += 100)
        PrintTableRow(i);

    for(int i = 1000; i <= 9000; i += 1000)
        PrintTableRow(i);
    return 0;
}