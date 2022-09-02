#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

long long Search(int arr[], const long long size, const int num)
{
    for(long long i = 0; i < size; ++i)
    {
        if(arr[i] == num)
        {
            return arr[i];
        }
    }
    
    return -1;
}

long long BinarySearch(int arr[], long long l, long long r, int x)
{
    while (l <= r) {
        long long m = l + (r - l) / 2;
 
        // Check if x is present at mid
        if (arr[m] == x)
            return arr[m];
 
        // If x greater, ignore left half
        if (arr[m] < x)
            l = m + 1;
 
        // If x is smaller, ignore right half
        else
            r = m - 1;
    }
 
    // if we reach here, then element was
    // not present
    return -1;
}

int main(int argc, const char * argv[])
{
    const long long size = 10000000000; // 10 billion
    
    int *arr = (int*) malloc(size * sizeof(int));
    memset(arr, 0, size);
    
    arr[size -1] = 10;
    
    // Calculate the time taken by Search()
    clock_t t;
    t = clock();
    long long res = Search(arr, size, 10);
    t = clock() - t;
    double timeTakenSearch = ((double)t)/CLOCKS_PER_SEC; // in seconds
    printf("function Search() returned: %lld took: %f\n", res, timeTakenSearch);
    
    // Calculate the time taken by BinarySearxh()
    t = clock();
    res = BinarySearch(arr, 0, size-1, 10);
    t = clock() - t;
    double timeTakenBinarySearch = ((double)t)/CLOCKS_PER_SEC; // in seconds
    printf("function BinarySearch() returned: %lld took: %f\n", res, timeTakenBinarySearch);
    
    return 0;
}
