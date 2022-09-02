#include <stdio.h>
#include <time.h>

long long  Add(int nums[], const unsigned int size) {
    long long sum = 0;
    for(int i = 0; i < size; ++i)
    {
        sum += nums[i];
    }
    printf("result: %lld", sum);
    return sum;
}

long long  FastAdd(int nums[], const unsigned int size) {
    long long int sum = size*(size + 1)/2;
    printf("\nresult: %lld", sum);
    return sum;
}

int main(int argc, const char * argv[]) {
    const unsigned int size = 20000;
    //const unsigned int size = 100000;
    int arr[size];
    
    for(int i = 0; i < size; ++i)
    {
        arr[i] = i + 1;
    }
    
    // Calculate the time taken by fun()
    clock_t t;
    t = clock();
    Add(arr, size);
    t = clock() - t;
    double timeTakenAdd = ((double)t)/CLOCKS_PER_SEC; // in seconds
    
    t = clock();
    FastAdd(arr, size);
    t = clock() - t;
    double timeTakenFastAdd = ((double)t)/CLOCKS_PER_SEC; // in seconds
 
    printf("\nAdd() took %f seconds to execute \n", timeTakenAdd);
    printf("FastAdd() took %f seconds to execute \n", timeTakenFastAdd);
    return 0;
}
