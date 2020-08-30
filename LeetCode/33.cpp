#include <vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        if(nums.size() < 1){
            return -1;
        }
        
        int left = 0, right = size - 1;
        if(nums[left] == target){
            return left;
        }else if(nums[right] == target)
        {
            /* code */
            return right;
        }
        
        int res = -1;
        while (left < right-1)
        {
            /* code */
            int mid = (left + right) / 2;
            if(nums[mid] == target){
                res = mid;
                break;
            }else if(nums[mid] > nums[left])
            {
                /* code */
                if(target > nums[left] && target < nums[mid]){
                    right = mid;
                }else{
                    left = mid;
                }
            }else if (nums[mid] < nums[right]) {
                if(target > nums[mid] && target < nums[right]){
                    left = mid;
                }else{
                    right = mid;
                }
            }else{
                break;
            }
            
        }
        return res;
    }
};