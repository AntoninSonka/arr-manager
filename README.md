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
