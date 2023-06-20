# arr-manager
This is C++ header for managing arrays
Functions in this file are called through namespaces, so if for example you want to call function merge_sort(), you will need to call am::sort::merge_sort().

namespaces:

sort:
  merge_sort()
  quick_sort()
  insertion_sort()
  shuffle()
  
basic:
  set_arr_el()
  print_arr()
  
manip:
  split()
  slice()
  concatenate()
  reverse()
  
search:
  binary_search()
  linear_search()

stats:
  max_val()
  min_val()
  sum_el()
  avarage()
  median()

for example:
int arr[10];
int size = sizeof(arr) / sizeof(arr[0]);
am::basic::set_arr_el(arr, size, 5);
am::sort::shuffle(arr, size);
int x = am::search::linear_search(arr, size, 15);