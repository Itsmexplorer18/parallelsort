#include "quicksort.hpp"
#include <cstdlib>
 
QuickSort::QuickSort(std::vector<int> *nums) {
    this->nums = nums;
}

QuickSort::~QuickSort() {}

int find_partition(std::vector<int> *nums,int low,int high){
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
void QuickSort::recursivesort(int low,int high){
    if(low>high) return;
    int pivot_idx=find_partition(nums,low,high);
    recursivesort(low,pivot_idx-1);
    recursivesort(pivot_idx+1,high);
}
void QuickSort::sort() {
    if ((*nums).size() == 0) {
        exit(1);
    }
    recursivesort(0, (*nums).size() - 1);
}