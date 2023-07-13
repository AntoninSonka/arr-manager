#ifndef ARRMANAGER_HPP
#define ARRMANAGER_HPP

#include <cstdlib>
#include <ctime>
#include <iostream>

namespace am {
    namespace{
        template<typename T>
        void swap(T& x, T& y){
            T z = x;
            x = y;
            y = z;
        }
    }
    namespace search{
        template <typename T>
        int linear_search(T* arr, std::size_t size, T element);
    }
    namespace sort {
        namespace {
            //merge sort
            template <typename T> 
            void merge(T* arr, T* arrL, int arrLSize, T* arrR, int arrRSize){
                int l = 0;
                int r = 0;
                while(r < arrRSize && l < arrLSize){
                    if(arrL[l] < arrR[r]){
                        arr[l + r] = arrL[l];
                        l++;
                    }
                    else{
                        arr[l + r] = arrR[r];
                        r++;
                    }
                }
                while(l < arrLSize){
                    arr[l + r] = arrL[l];
                    l++;
                }
                while(r < arrRSize){
                    arr[l + r] = arrR[r];
                    r++;
                }
            }
            
            template <typename T> 
            void mergeSort(T* arr, int size){
                if(size <= 1)
                    return;
                int mid = size / 2;
                T arrL[mid];
                T arrR[size - mid];
                for(int i = 0; i < mid; i++){
                    arrL[i] = arr[i];
                }
                for(int i = mid; i < size; i++){
                    arrR[i - mid] = arr[i];
                }
                mergeSort(arrL, mid);
                mergeSort(arrR, size - mid);
                merge(arr, arrL, mid, arrR, size - mid);
            }
            
            //quick sort
            template <typename T> 
            int partition(T* arr, int low, int high){
                int pivot = high;
                int swapMarker = low - 1;
                for(int currentIndex = low; currentIndex < high; currentIndex++){
                    if(arr[currentIndex] <= arr[pivot]){
                        swapMarker++;
                        if(arr[currentIndex] < arr[swapMarker]){
                            swap(arr[currentIndex], arr[swapMarker]);
                        }
                    }
                }
                swapMarker++;
                swap(arr[swapMarker], arr[pivot]);
                return swapMarker;
            }
            
            template <typename T> 
            void quickSort(T* arr, int low, int high){
                if(low >= high)
                    return;
                int pivot = partition(arr, low, high);
                quickSort(arr, low, pivot - 1);
                quickSort(arr, pivot + 1, high);
            }

            //insertion sort
            template <typename T> 
            void insertionSort(T* arr, int size){
                for(int i = 1; i < size; i++){ 
                    T current = arr[i];
                    int j = i - 1;
                    while(j >= 0 && current < arr[j]){
                        swap(arr[j + 1], arr[j]);
                        j--;
                    }
                    arr[j + 1] = current;
                }
            }
            
            //heap sort
            template <typename T>
            void heapify(T* arr, int parent, int size){
                int left = parent * 2 + 1;
                int right = left + 1;
                int bigger = parent;
                if(left < size && arr[left] > arr[bigger]){
                    bigger = left;
                }
                if(right < size && arr[right] > arr[bigger]){
                    bigger = right;
                }
                if(bigger != parent){
                    swap(arr[bigger], arr[parent]);
                    heapify(arr, bigger, size);
                }
            }
            
            template <typename T>
            void heapSort(T* arr, int size){
                for(int i = size / 2 - 1; i >= 0; i--){
                    heapify(arr, i, size);
                }
                for(int i = size - 1; i > 0; i--){
                    swap(arr[0], arr[i]);
                    heapify(arr, 0, i);
                }
            }
        }

        template <typename T>
        void quick_sort(T* arr, std::size_t size){
            quickSort(arr, 0, size - 1);
        }

        template <typename T>
        void merge_sort(T* arr, std::size_t size){
            mergeSort(arr, size);
        }

        template <typename T>
        void insertion_sort(T* arr, std::size_t size){
            insertionSort(arr, size);
        }

        template <typename T>
        void heap_sort(T* arr, std::size_t size){
            heapSort(arr, size);
        }

        //shuffles array
        template <typename T>
        void shuffle(T* arr, std::size_t size){
            srand(time(NULL));
            for(int i = 0; i < size; i++){
                swap(arr[i], arr[rand()%(size - i) + i]);
            }
        }
    };

    namespace manip {
        using am::search::linear_search;
        //splits array into 2 subarrays
        template <typename T>
        void split(T arr[], std::size_t size, T*& arrL, T*& arrR){ //if size of arr is odd, arrR has the odd setArrElement
            int mid = size / 2;
            arrL = new T[mid];
            arrR = new T[size - mid];
            for(int i = 0; i < mid; i++){
                arrL[i] = arr[i];
            }
            for(int i = mid; i < size; i++){
                arrR[i - mid] = arr[i];
            }
        }
        
        //slices form inclusive, to exclusive
        template <typename T>
        T* slice(T arr[], int& size, std::size_t from, std::size_t to){
            if(size < 0){
                std::cerr << "Invalid size\n";
                return arr;
            }
            if(from >= to){
                std::cerr << "In function slice, 'from' is greater, or equal, than 'to'. 'From' needs to be smaller than 'to'.\n";
                return arr;
            }
            if(to > size){
                std::cerr << "'To' is greater than size of array, 'to' is out of bounds.\n";
                return arr;
            }
            T* slicedArr = new T[to - from];
            for(int i = from; i < to; i++){
                slicedArr[i - from] = arr[i];
            }
            size = to - from;
            return slicedArr;
        }

        //wil put 2 arrays together
        template <typename T>
        T* concatenate(T* arr1, std::size_t size1, T* arr2, std::size_t size2){
            T* arr = new T[size1 + size2];
            for(int i = 0; i < size1; i++){
                arr[i] = arr1[i];
            }
            for(int i = 0; i < size2; i++){
                arr[size1 + i] = arr2[i];
            }
            return arr;
        }
        
        //reverses array
        template <typename T>
        void reverse(T* arr, std::size_t size){
            T* tempArr = new T[size];
            for(int i = 0; i < size; i++){
                tempArr[i] = arr[i];
            }
            for(int i = 0; i < size; i++){
                arr[size - 1 - i] = tempArr[i];  
            }
            delete[] tempArr;
        }

        //resizes array
        template <typename T>
        T* resize(T* arr, int& size, std::size_t newSize, bool delOrigArr = 1){
            if(size < 0){
                std::cerr << "Invalid size\n";
                return arr;
            }
            T* tempArr = new T[newSize];
            for(int i = 0; i < newSize; i++){
                if(i < size){
                    tempArr[i] = arr[i];
                }
            }
            if(delOrigArr)
                delete[] arr;

            return tempArr;
        }

        //removes duplicates
        template <typename T>
        T* remove_dups(T* arr, int& size, bool delOrigArr = 1){
            if(size < 0){
                std::cerr << "Invalid size\n";
                return arr;
            }
            T* tempArr = new T[size];
            for(int i = 0; i < size; i++){
                tempArr[i] = arr[i];
            }
            sort::merge_sort(tempArr, size);
            T* dups = new T[size];
            int dupsIndex = 0;
            for(int i = 1; i < size; i++){
                if(tempArr[i] == tempArr[i - 1]){
                    dups[dupsIndex] = tempArr[i];
                    dupsIndex++;
                }
            }
            if(dupsIndex == 0){
                delete[] tempArr;
                delete[] dups;
                return arr;
            }
            for(int i = 0; i < dupsIndex; i++){
                int x = am::search::linear_search(arr, size, dups[i]);
                for(int j = x; j < size - 1; j++){
                    arr[j] = arr[j + 1];
                }
                arr = resize(arr, size, size - 1);
                size--;
            }
            T* returnArr = new T[size];
            for(int i = 0; i < size; i++){
                returnArr[i] = arr[i];
            }
            delete[] tempArr;
            delete[] dups;
            if(delOrigArr)
                delete[] arr;
            return returnArr;
        }

        //same as slice, but it removes selected area
        template <typename T>
        T* remove_slice(T arr[], int& size, std::size_t from, std::size_t to ){
            if(size < 0){
                std::cerr << "Invalid size\n";
                return arr;
            }
            if(from >= to){
                std::cerr << "In function slice, 'from' is greater, or equal, than 'to'. 'From' needs to be smaller than 'to'.\n";
                return arr;
            }
            if(to > size){
                std::cerr << "'To' is greater than size of array, 'to' is out of bounds.\n";
                return arr;
            }
            T* arrL = new T[from];
            for(int i = 0; i < from; i++){
                arrL[i] = arr[i];
            }
            T* arrR = new T[size - to];
            for(int i = to; i < size; i++){
                arrR[i - to] = arr[i];
            }
            T* arrC = concatenate(arrL, from, arrR, size - to);
            delete[] arrL;
            delete[] arrR;
            size -= to - from;
            return arrC;
        }
    };
    
    namespace basic {
        //sets elements from 'from', incrementing by one
        template <typename T>
        void set_arr_el(T* arr, std::size_t size, int from = 0){
            for(int i = 0; i < size; i++){
                arr[i] = from;
                from++;
            }
        }
        
        //prints array
        template <typename T>
        void print_arr(T* arr, std::size_t size){
            for(int i = 0; i < size; i++){
                std::cout << arr[i];
                if(i < size - 1){
                    std::cout << ", ";
                }
            }
            std::cout << std::endl;
        }
    };
    
    namespace search {
        //will return index of provided element in sorted array
        template <typename T>
        int binary_search(T* arr, std::size_t size, T element){
            for(int i = 1; i < size; i++){
                if(arr[i] < arr[i - 1]){
                    std::cerr << "'binary_search' was used on unsorted array, array must be sorted form lowest, to greatest.\n";
                    return 0;
                }
            }

            int lowBarrier = 0;
            int highBarrier = size - 1;

            while (lowBarrier <= highBarrier) {
                int mid = lowBarrier + (highBarrier - lowBarrier) / 2;

                if (arr[mid] == element) {
                    return mid;

                } else if (arr[mid] < element) {
                    lowBarrier = mid + 1;

                } else {
                    highBarrier = mid - 1;
                }
            }
            return -1; //Element not found
        }

        //will return index of provided element
        template <typename T>
        int linear_search(T* arr, std::size_t size, T element){
            for(int i = 0; i < size; i++){
                if(arr[i] == element)
                    return i;
            }
            return -1; //element not found
        }
    };

    namespace stats {
        //returns min value
        template <typename T>
        T min_val(T arr[], std::size_t size){
            T* arrT = new T[size];
            for(int i = 0; i < size; i++){
                arrT[i] = arr[i];
            }
            sort::merge_sort(arrT, size);
            int x = arrT[0];
            delete[] arrT;
            return x;
        }
        
        //returns max value
        template <typename T>
        T max_val(T arr[], std::size_t size){
            T* arrT = new T[size];
            for(int i = 0; i < size; i++){
                arrT[i] = arr[i];
            }
            sort::merge_sort(arrT, size);
            int x = arrT[size - 1];
            delete[] arrT;
            return x;
        }
        
        //returns sum of all elements
        template <typename T>
        T sum_el(T arr[], std::size_t size){
            T sum = 0;
            for(int i = 0; i < size; i++){
                sum += arr[i];
            }
            return sum;
        }
        
        //returns avarege
        template <typename T>
        T avarage(T arr[], std::size_t size){
            int sum = sum_el(arr, size);
            return sum / size;
        }
        
        //returns median
        template <typename T>
        T median(T arr[], std::size_t size){
            T* arrT = new T[size];
            for(int i = 0; i < size; i++){
                arrT[i] = arr[i];
            }
            sort::merge_sort(arrT, size);
            int mid = size / 2;
            T med1 = arrT[mid - 1];
            T med2 = arrT[mid];
            delete[] arrT;
            if(size % 2 == 1){
                return (med1 + med2) / 2;
            }
            return med1;
        }
    };
};

#endif
