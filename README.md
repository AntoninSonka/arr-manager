# arr-manager
This is C++ header for managing arrays
Functions in this file are called through namespaces, so if for example you want to call function merge_sort(), you will need to call am::sort::merge_sort().

when there is array, it can be static/dynamic of any type.
when ther is dArray, it must be dynamic array of any type.
size is size of array.
sizeCh can get changed when calling function.

namespace am:
  this namespace contains other namespaces
  
namespaces under namespace am:

sort:
  merge_sort(array, size)
  quick_sort(array, size)
  insertion_sort(array, size)
  heap_sort(array, size)
  shuffle(array, size)
  
basic:
  set_arr_el(array, size)
  print_arr(array, size)
  
manip:
  split(array, size, dArray1, dArray2)
  slice(array, size, from, to) //returns dArray
  concatenate(array1, size1, array2, size2) //returns dArray
  reverse(array, size)
  resize(array, sizeCh, newSize) //returns dArray
  remove_dups(array, sizeCh) //returns dArray
  remove_slice(array, size, from, to) //returns dArray
  
search:
  binary_search(sortedArray, size, element)
  linear_search(array, size, element)

stats:
  max_val(array, size) //return schoosen type
  min_val(array, size) //returns choosen type
  sum_el(array, size) //returns choosen type
  avarage(array, size) //return choosen type
  median(array, size) //returns choosen type
