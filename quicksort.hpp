#ifndef QUICKSORT_H
#define QUICKSORT_H
#include <vector>

class QuickSort{
    private:
    std::vector<int> *nums;
    public:
    QuickSort(std::vector<int> *nums);
    ~QuickSort();
    void sort();
    void recursivesort(int low,int high);
};


#endif