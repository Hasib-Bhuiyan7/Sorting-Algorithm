#include "mySort.h"

void merge(int array[], unsigned int first, unsigned int mid, unsigned int last){

    int i, j, k, p, t;

    int left_length = mid - first + 1;
    int right_length = last - mid;
    
    int left[left_length];
    int right[right_length];
    
    for(p=0; p < left_length; p++){
        myCopy(&array[p + first], &left[p]);
    }
    for(t=0; t < right_length; t++){
        myCopy(&array[t + mid + 1], &right[t]);
    }
    
    i = 0;
    j = 0;
    k = first;
    
    while(i < left_length && j < right_length){
        if(myCompare(left[i], right[j]) <= 0){
            myCopy(&left[i], &array[k]);
            i++;
        }
        else{
            myCopy(&right[j], &array[k]);
            j++;
        }
        k++;
        
    }
    
    while(i < left_length){
        myCopy(&left[i], &array[k]);
        i++;
        k++;
    }
    while(j < right_length){
        myCopy(&right[j], &array[k]);
        j++;
        k++;
    }
}

void mySort(int array[], unsigned int first, unsigned int last){
    if(first < last){
        int mid = first + (last - first)/2;
        mySort(array, first, mid);
        mySort(array, mid+1, last);
        merge(array, first, mid, last);
    }
}
