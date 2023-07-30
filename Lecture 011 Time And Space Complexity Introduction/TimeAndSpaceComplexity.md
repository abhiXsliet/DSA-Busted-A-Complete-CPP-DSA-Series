# Time Complexity

Time Complexity is a measure of the amount of time taken by an algorithm to run, and it helps us understand how the algorithm's performance scales with the input size. However, the actual execution time of a program can be influenced by various factors such as computer hardware, system load, and memory access times.

The order of time complexity, from best to worst, is as follows:

- **O(1)** (Constant Time): This represents algorithms with a constant running time, regardless of the input size. Examples include accessing an element in an array by its index or performing a simple arithmetic operation.

- **O(log(n))** (Logarithmic Time): This indicates algorithms with a running time that increases logarithmically with the input size. Examples include binary search in a sorted array or searching elements in a balanced binary search tree.

- **O(√n)** (Square Root Time): This represents algorithms that have a running time proportional to the square root of the input size. Examples include finding divisors of a number or checking for a perfect square.

- **O(n)** (Linear Time): This represents algorithms with a running time that scales linearly with the input size. Examples include iterating through an array or counting the occurrences of an element in a list.

- **O(nlog(n))** (Linearithmic Time): This indicates algorithms that have a running time of n multiplied by the logarithm of n. Examples include sorting algorithms like Merge Sort and Heap Sort.

- **O(n²)** (Quadratic Time): This represents algorithms whose running time is directly proportional to the square of the input size. Examples include nested loops where each iteration depends on the input size.

- **O(n³)** (Cubic Time): This indicates algorithms with a running time that scales with the cube of the input size. Examples include three nested loops where each iteration depends on the input size.

- **O(2^n)** (Exponential Time): This represents algorithms with a running time that grows exponentially with the input size. Examples include generating all subsets of a set or solving the traveling salesman problem using a brute-force approach.

- **O(n!)** (Factorial Time): This indicates algorithms with a running time that grows factorially with the input size. Examples include generating all permutations of a sequence using a brute-force approach.

## Order of Time Complexity

**O(1) < O(log(n)) < O(√n) < O(n) < O(nlog(n)) < O(n²) < O(n³) < O(2^n) < O(n!)**

It's important to note that as we move from left to right in the above list, the algorithms become increasingly inefficient and slower.

### Examples:

Here are some additional examples to illustrate the different time complexities:

- O(1): Accessing an element in a hashmap.
- O(log(n)): Finding an element in a balanced binary search tree.
- O(√n): To check Prime, iterating upto the square root of number for divisibility.
- O(n): Finding the maximum element in an unsorted array.
- O(n²): Performing a bubble sort on an array.
- O(2^n): Solving the Tower of Hanoi problem recursively.
- O(n!): Solving the permutation problem using a brute-force approach.

# Space Complexity

Space Complexity measures the amount of memory required by an algorithm to run, and it helps us understand how the algorithm's memory usage scales with the input size.

The space complexity is typically expressed using the same Big O notation as time complexity.

- **O(1)** (Constant Space): Algorithms with constant space complexity use a fixed amount of memory that doesn't depend on the input size. Examples include simple mathematical operations or maintaining a fixed-size array.

- **O(n)** (Linear Space): Algorithms with linear space complexity use an amount of memory that scales linearly with the input size. Examples include storing input elements in an array or creating a new array of the same size as the input.

- **O(n²)** (Quadratic Space): Algorithms with quadratic space complexity use an amount of memory that is proportional to the square of the input size. Examples include creating a matrix or a 2D array with dimensions based on the input size.

- **O(log(n))** (Logarithmic Space): Algorithms with logarithmic space complexity use an amount of memory that grows logarithmically with the input size. Examples include binary search or recursive algorithms with a logarithmic stack depth.

- **O(nlog(n))** (Linearithmic Space): Algorithms with linearithmic space complexity use an amount of memory that grows in proportion to n multiplied by the logarithm of n. Examples include merge sort or heap sort algorithms.

It's important to analyze both time and space complexity to get a comprehensive understanding of an algorithm's performance characteristics.