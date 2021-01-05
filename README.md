# Program4

Purpose

This programming assignment will serve two purposes. First, it will provide hands-on experience for utilizing many of the sorting algorithms introduced in the class. Second, it will viscerally demonstrate the cost of O(n2) v. O(n logn) algorithms. It will also clearly show that algorithms with the same complexity may have different running times.

Problem:

You will write a program which implements the following sorts and compares the performance for operations on arrays of integers of growing sizes 10, 100, 1000, 5000, 10000, 25000, etc….

You will graph the performance of the different sorts as a function of the size of the array.

1) BubbleSort

2) InsertionSort

3) MergeSort

4) Non-Recursive, one extra array MergeSort (We’ll call this improved version, IterativeMergeSort from here on out in this homework)

5) QuickSort

6) ShellSort

 

Details:

IterativeMergeSort

In-place sorting refers to sorting that does not require extra memory arrays. For example, QuickSort performs partitioning operations by repeating a swapping operation on two data items in a given array. This does not require an extra array.

MergeSort as shown in Carrano allocates a temporary array at each recursive call. Due to this MergeSort is slower than QuickSort even though their running time is upper-bounded to O(n log n).

We can improve the performance of MergeSort by utilizing a non-recursive method and using only one additional array (instead of one array on each recursive call). In this improved version of MergeSort, IterativeMergeSort, one would merge data from the original array into the additional array and alternatively copy back and forth between the original and the additional temporary array. Please re-read the last sentence as it is critical to the grading of the lab.

For the IterativeMergeSort we still need to allow data items to be copied between the original and this additional array as many times as O(log n). However, given the iterative nature we are not building up state on the stack.

Runtime Details

Your program, called Sorter, will take in two parameters:

1) sort type as a string of characters

2) an array size as an integer.

Your program will create and sort an integer array of the size with the specified sort:

MergeSort, BubbleSort, InsertionSort, QuickSort, ShellSort or IterativeMergeSort. The driver functions below will help with the creation.

Examples:

Sorter MergeSort 100 (creates and sorts an array of 100 using MergeSort)

Sorter QuickSort 1000 (creates and sorts an array of 1000 using QuickSort)

Sorter IterativeMergeSort 10000 (creates and sorts an array of 10000 using the newly implemented non-recursive semi-in-place MergeSort)

 

What to submit:

Turn in, in a .zip (not gz, etc..):

(1) Your SortImpls.h file which has implementations of all of the sorts

(2) Your a.out

(3) A separate report in word or pdf which includes: Graphs that compares the performance among the different sorting algorithms with increasing data size. You should increase the data size to clearly show the difference in performance of the different sorts.

Driver Code

Use the driver code Actions  here to test and time the different Sort functions.

Word version of Driver Code Actions

