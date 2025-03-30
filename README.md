# Parallel Sorting Algorithm

## Overview
This project demonstrates the efficiency of threading and parallel computing by implementing Merge Sort and Quick Sort with multithreading. It compares the execution times of normal (single-threaded) and threaded versions of these sorting algorithms.

## Features
- **Merge Sort with Threads:** Uses multithreading to parallelize the merging process.
- **Quick Sort with Threads:** Uses threads to parallelize the partitioning step.
- **Performance Comparison:** Measures and compares execution times of normal vs. multithreaded implementations.


## Compilation & Execution
### Using g++
```sh
 g++ -o parallel_sort parallel_sort.cpp -pthread
 ./parallel_sort
```

## Results
The program outputs the execution time for each sorting approach, helping to evaluate the efficiency of parallel sorting.

