#include <iostream>

int searchInsert(int* nums, int numsSize, int target){
    int mid = 0, init = 0, end = numsSize - 1;
    
    while(init <= end){
        mid = (init + end) / 2;
        if(nums[mid] < target){
          init = mid + 1;
        }
        if(target == nums[mid]){
          return mid;
        }
        if(nums[mid] > target){
          end = mid - 1;
        }
    }
    
    init = 0;
    end = numsSize - 1;
    
    while(init <= end){
        mid = (init + end) / 2;
        if(nums[mid] < target){
            init = mid + 1;
        }
        if(mid > 0){
            if(target < nums[mid] && target > nums[mid-1]){
                return mid;
            }   
        }
        if(mid < numsSize - 2){
            if(target > nums[mid] && target < nums[mid + 1]){
                return mid + 1;
            }
        }
        if(target > nums[mid] && mid == numsSize - 1){
            return mid + 1;
        }
        if(target < nums[mid] && mid == 0){
            return mid;
        }
        if(nums[mid] > target){
            end = mid - 1;
        }
    }
    
    return -1;
}