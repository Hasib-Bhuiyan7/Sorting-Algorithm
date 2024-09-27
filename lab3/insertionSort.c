#include "mySort.h"

void mySort(int array[], unsigned int first, unsigned int last){
    int chosen, j;
    //int temp;
    for(int i=first; i<=last; i++){
        myCopy(&array[i], &chosen); //chosen = array[i];
        j = i-1;
        
        while(j>=0 && myCompare(array[j], chosen) >= 0){
            mySwap(&array[j], &array[j+1]);
            //temp = array[j];
            //array[j] = array[j+1];
            //array[j+1] = temp;
            j = j-1;
        }
    }

    }
