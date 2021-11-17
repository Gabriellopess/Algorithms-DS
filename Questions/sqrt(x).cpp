#include <iostream>

int searchInsert();

int mySqrt(int x){
    int aux = 0, limite = 46341;
    aux = searchInsert(limite, x);
    return aux;
}

int searchInsert(int numsSize, int target){
    int mid = 0, init = 0, end = numsSize - 1;

    while(init <= end){
        mid = (init + end) / 2;
        if(mid*mid < target){
          init = mid + 1;
        }
        if(mid < numsSize - 1){
            if(target >= mid*mid && target < (mid+1)*(mid+1)){
                return mid;
            }
        }
        else{
            return numsSize - 1;
        }
        
        if(mid*mid > target){
          end = mid - 1;
        }
    }
    return -1;
}