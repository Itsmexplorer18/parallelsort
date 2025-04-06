#include "parallelquicksort.hpp"
#include <cstdlib>
#include<algorithm>
 
ParallelQuickSort::ParallelQuickSort(std::vector<int> *nums) {
    this->nums = nums;
}



ParallelQuickSort::~ParallelQuickSort() {}

int find_partition1(std::vector<int> *nums,int low,int high){
     int pivot=(*nums)[high];
       int pi=low;
       for(int i=low;i<high;i++){
           if((*nums)[i]<=pivot){
               std::swap((*nums)[i],(*nums)[pi]);
               pi++;
           }
       }
       std::swap((*nums)[pi],(*nums)[high]);
       return pi;
}
void ParallelQuickSort::recursiveSort(int low,int high){
    if(low>high) return;
    int pivot_idx=find_partition1(nums,low,high);
    const int THRESHOLD = 5000;

    if (high - low < THRESHOLD) {
        std::sort(nums->begin() + low, nums->begin() + high + 1);
        return;
    }
    std::thread thread_1([this, low, pivot_idx] { this->recursiveSort(low, pivot_idx-1); });
    std::thread thread_2([this, pivot_idx, high] { this->recursiveSort(pivot_idx+1,high); });
    thread_1.join();
    thread_2.join();
    //recursivesort(low,pivot_idx-1);
    //recursivesort(pivot_idx+1,high);
}

void ParallelQuickSort::sort() {
    if ((*nums).size() == 0) {
        exit(1);
    }
    recursiveSort(0, (*nums).size() - 1);
}


