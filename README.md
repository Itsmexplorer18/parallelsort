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

# User-Level vs Kernel-Level Threads

## Overview
Threads can be categorized into **User-Level Threads (ULTs)** and **Kernel-Level Threads (KLTs)**. The way threads are managed and scheduled affects whether true parallel execution is achieved or if the performance gains come from fast context switching.

---

## 1. User-Level Threads (ULTs)
- Managed in **user space** by a thread library (e.g., green threads, Java Virtual Threads).
- The **OS is unaware** of these threads; it only sees the process as a whole.
- Thread scheduling happens at the user level, **not at the kernel level**.
- **Fast context switching** (no kernel overhead), but **no true parallelism** on multi-core CPUs.

### **Example: User-Level Threads (Green Threads)**
Some programming languages like Go or Java (Project Loom) use user-level threads that are mapped dynamically to kernel threads.

```java
// Example: Java Virtual Threads (User-Level Threads)
Thread.startVirtualThread(() -> {
    System.out.println("Running in a virtual thread!");
});
```

---

## 2. Kernel-Level Threads (KLTs)
- Managed by the **Operating System (OS)**.
- The OS scheduler assigns threads to different CPU cores, allowing **true parallel execution**.
- Context switching involves kernel overhead, but it enables **multi-core utilization**.

---

## 3. Thread Mapping: 1:1 vs M:N
The way user threads are mapped to kernel threads determines if the program achieves **true parallelism**.

### **1:1 Thread Mapping**
- Each user thread maps **directly** to a kernel thread.
- Allows true parallel execution but can be resource-intensive.
- Example: Some OS implementations for `pthreads` and system threads.

### **M:N Thread Mapping**
- Multiple user threads (M) are mapped onto a limited number of kernel threads (N).
- Allows better resource sharing but may require a **user-space scheduler**.
- Example: **Go's Goroutines, Java Virtual Threads, some pthread implementations.**

---

## 4. How to Ensure True Parallelism
1. Use threading APIs that leverage kernel threads if multi-core execution is needed.
2. Avoid excessive thread creation (use thread pools).
3. Check available CPU cores before launching too many threads:

## 5. Conclusion
- **User-Level Threads (ULTs)** are fast but lack true parallelism.
- **Kernel-Level Threads (KLTs)** allow actual parallel execution on multi-core CPUs, depending on OS thread mapping.
- Whether user threads can run in parallel depends on how the **OS maps them to kernel-level execution**.


## Results
The program outputs the execution time for each sorting approach, helping to evaluate the efficiency of parallel sorting.

