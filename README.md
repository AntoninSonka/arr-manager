#arr-manager

arr-manager is a C++ header file that provides functionality for managing arrays. It offers various operations such as sorting, searching, manipulation, and basic array operations. The functions are organized into different namespaces for easy access and clarity.

Getting Started

To use the functions in arr-manager, include the arrmanager.hpp header file in your C++ project.

#include "arrmanager.hpp"

Usage

The functions in arr-manager are called through namespaces. For example, to call the merge_sort function, you need to use the namespace am::sort. Here's an example of how to use it:

cpp


    int array[] = {4, 2, 7, 1, 5};
    int size = sizeof(array) / sizeof(array[0]);

    am::sort::merge_sort(array, size);

    // Print the sorted array
    am::basic::print_arr(array, size);

    return 0;
    

Available Namespaces and Functions
Namespace am

This is the main namespace that contains other namespaces.
Namespace am::sort

This namespace provides sorting algorithms to sort arrays.

    merge_sort(array, size): Sorts the array using the merge sort algorithm.
    quick_sort(array, size): Sorts the array using the quicksort algorithm.
    insertion_sort(array, size): Sorts the array using the insertion sort algorithm.
    heap_sort(array, size): Sorts the array using the heapsort algorithm.
    shuffle(array, size): Shuffles the elements of the array randomly.

Namespace am::basic

This namespace provides basic array operations.

    set_arr_el(array, size, from): Sets elements of the array starting from the specified value (default is 0).
    print_arr(array, size): Prints the elements of the array.

Namespace am::manip

This namespace provides array manipulation functions.

    split(array, size, dArray1, dArray2): Splits the array into two subarrays.
    slice(array, sizeCh, from, to): Returns a dynamic array (dArray) containing a slice of the original array.
    concatenate(array1, size1, array2, size2): Concatenates two arrays into a single dynamic array.
    reverse(array, size): Reverses the elements of the array.
    resize(array, sizeCh, newSize, deleteOriginalArray): Resizes the array to the specified size and returns a dynamic array.
    remove_dups(array, sizeCh, deleteOriginalArray): Removes duplicates from the array and returns a dynamic array.
    remove_slice(array, size, from, to): Removes a slice from the array and returns a dynamic array.

Namespace am::search

This namespace provides search algorithms to find elements in arrays.

    binary_search(sortedArray, size, element): Performs a binary search on a sorted array and returns the index of the element.
    linear_search(array, size, element): Performs a linear search on the array and returns the index of the element.

Namespace am::stats

This namespace provides statistical functions for arrays.

    max_val(array, size): Returns the maximum value in the array.
    min_val(array, size): Returns the minimum value in the array.
    sum_el(array, size): Returns the sum of all elements in the array.
    average(array, size): Returns the average value of the elements in the array.
    median(array, size): Returns the median value of the elements in the array.

Contributing

If you want to contribute to arr-manager, please submit a pull request with your changes. We welcome bug fixes, feature enhancements, and other improvements.
