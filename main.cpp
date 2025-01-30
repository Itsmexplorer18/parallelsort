#include <iostream>
#include <vector>
#include <mutex>
#include <chrono> // Include chrono for timing
#include "sorting/QuickSort.hpp"
#include "sorting/parallelquickSort.hpp"

int main(int argc, char *argv[]) {

    const int SIZE = 10000000;
    std::vector<int> nums(SIZE);
    std::vector<int> nums1(SIZE);
   for (int i = 0; i < SIZE; ++i) {
        nums[i] = rand() % 10000000;
        nums1[i] = nums[i];
    }

    
    QuickSort* quicksort = new QuickSort(&nums);
    auto start = std::chrono::high_resolution_clock::now();
    quicksort->sort();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> QuickSortDuration = end - start;

    std::cout << "Quicksort time taken: " << QuickSortDuration.count() << " seconds" << std::endl;

    delete quicksort;

     ParallelQuickSort* quicksort1 = new  ParallelQuickSort(&nums1);
    start = std::chrono::high_resolution_clock::now();
    quicksort1->sort();
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> parallelQuickSortDuration = end - start;

    std::cout << "ParallelquickSort time taken: " << parallelQuickSortDuration.count() << " seconds" << std::endl;

    delete quicksort1;


    return 0;
}