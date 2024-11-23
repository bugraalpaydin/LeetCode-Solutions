#include <stdio.h>
#include <stdlib.h>

int removeDuplicates(int*, int);

int main(){
    int* array = (int *)malloc (sizeof(int)*3);
    array[0] = 1;
    array[1] = 2;
    array[2] = 2;
    int k = removeDuplicates(array, 3);
    printf("%d", k);
}

int removeDuplicates(int* nums, int numsSize) {
    int k = 1;
    for (int i = 1; i<numsSize; i++){
        if (nums[i] != nums[i-1]){
            nums[k] = nums[i];
            k++;
        }
    }
    return k;
}
