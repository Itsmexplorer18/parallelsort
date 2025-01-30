#ifndef PARALLELQUICKSORT_H
#define PARALLELQUICKSORT_H
#include<vector>
#include <thread>
#include <mutex>
#include <iostream>
class ParallelQuickSort {
private:
    std::vector<int> *nums;

public:
    ParallelQuickSort(std::vector<int> *nums);
    ~ParallelQuickSort();
    void sort();
    void recursiveSort(int left, int right);
};


#endif