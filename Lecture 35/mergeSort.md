# Merge Sort

[Explore Merge Sort Code!](mergeSort.cpp)

**Advantages:**

1. Stable Sorting: Merge sort is a stable sorting algorithm, preserving the relative order of equal elements.

2. Guaranteed Performance: Merge sort has a consistent worst-case time complexity of O(n log n), making it suitable for large datasets and critical applications.

3. Parallelizability: Merge sort can be easily parallelized to leverage multiple processors or cores, improving performance in high-performance computing scenarios.

**Disadvantages:**

1. Additional Space Requirement: Merge sort requires extra space for temporary arrays during merging, which can be a concern for large datasets or memory-constrained environments.

2. Recursive Nature: Merge sort's recursive implementation incurs overhead due to function calls and stack operations, potentially impacting efficiency and risking stack overflow errors.

3. Not In-place Sorting: Merge sort doesn't perform in-place sorting, requiring additional memory for sorted elements. This can be problematic for memory utilization or sorting large datasets that may not fit entirely in memory.

----

## The time complexity of Merge Sort is calculated as follows:

1. **Divide**: The array is divided into two halves recursively until each subarray contains a single element. This process requires `log n` divisions, where n is the number of elements in the array.

2. **Conquer**: In the conquer step, the single-element subarrays are merged back together in a sorted manner. The merging process takes linear time, `O(n)`, where n is the total number of elements in the merged arrays.

- Combining these steps, we can conclude that the time complexity of Merge Sort is `O(n log n)`, where n is the number of elements in the input array. 
- Merge Sort's time complexity remains the same regardless of the initial order of the elements. 
- This makes Merge Sort an efficient and reliable sorting algorithm for various applications, especially when dealing with large datasets.