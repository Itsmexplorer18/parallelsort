#include "parallelMergeSort.hpp"
#include <algorithm>

// Scope resolution operator: here we are defining our function.
// In the header file, only the function declarations exist.
ParallelMergeSort::ParallelMergeSort(std::vector<int>& nums) : nums(nums) {} // Constructor initializes reference

// Destructor
ParallelMergeSort::~ParallelMergeSort() {}

// Defining the recursive function here using the scope resolution operator
void ParallelMergeSort::recursiveSort(int left, int right) {
   //this is pointing to mergesort1 which is the pointer to out current instance of object
   
    const int THRESHOLD = 5000;

    if (right - left < THRESHOLD) {
        std::sort(nums.begin() + left, nums.begin() + right + 1);
        return;
    }

    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;

    std::thread thread_1([this, left, mid] { this->recursiveSort(left, mid); });
    std::thread thread_2([this, mid, right] { this->recursiveSort(mid + 1, right); });
    thread_1.join();
    thread_2.join();

    std::vector<int> result;
    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j]) {
            result.push_back(nums[i]);
            i++;
        } else {
            result.push_back(nums[j]);
            j++;
        }
    }

    while (i <= mid) {
        result.push_back(nums[i]);
        i++;
    }

    while (j <= right) {
        result.push_back(nums[j]);
        j++;
    }

    for (int k = 0; k < result.size(); k++) {
        nums[left + k] = result[k];
    }
}

/*When calling sort()
ParallelMergeSort* mergesort1 = new ParallelMergeSort(nums1);
mergesort1->sort();
Inside sort(), we have:
std::thread thread_1([this] { this->recursiveSort(0, nums.size() - 1); });
this == mergesort1
So, this->recursiveSort(...) calls recursiveSort() on mergesort1.
This means this->recursiveSort(...) is the same as mergesort1->recursiveSort(...).*/
void ParallelMergeSort::sort() {
    if (nums.empty()) { // Check for an empty vector
        return;
    }
    /*new ParallelMergeSort(nums1) creates an instance of ParallelMergeSort on the heap.
    mergesort1 is a pointer to this instance
    this is pointing to mergesort1*/
    std::thread thread_1([this] { this->recursiveSort(0, nums.size() - 1); });
    thread_1.join();
}
