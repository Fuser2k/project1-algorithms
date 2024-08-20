Sorting Algorithms Comparison

Overview
This repository provides a comparative analysis of four different sorting algorithms, with a focus on their speed and efficiency. The algorithms explored are:

1-Insertion Sort
2-Heap Sort
3-Quick Sort
4-Radix Sort

Additionally, this study includes insights into which algorithm is best suited for various use cases based on their performance metrics.

Repository Structure
-paper.pdf
Contains the detailed report comparing the four sorting algorithms, including implementation details, methodology, and performance results.

Methodology
The sorting algorithms were implemented in C++ and tested on datasets of varying sizes to evaluate their performance. The project includes:
-Implementation of each sorting algorithm.
-A framework for timing the execution of each algorithm.
-A test suite to ensure correctness and consistency of the algorithms.

Results
-Quick Sort emerged as the fastest algorithm with an average time complexity of O(n log n).
-Insertion Sort performed well for small datasets but struggled with larger arrays due to its O(n²) complexity.
-Heap Sort was a strong performer, though slightly slower than Quick Sort.
-Radix Sort, while stable, did not perform as well as the other algorithms in the test cases but was faster than Insertion Sort for large arrays.

Conclusion
This project provides valuable insights into the efficiency of various sorting algorithms. The findings can help developers choose the most appropriate algorithm based on the specific needs of their applications.

Contributions
Contributions are welcome! If you have ideas for further comparisons or improvements, feel free to submit a pull request or open an issue.

