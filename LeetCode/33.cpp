#include <vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() < 1){
            return -1;
        }
        if(nums.size() == 1){
            if(nums[0] == target){
                return 0;
            }else{
                return -1;
            }
        }
        
        int left = 0, right = nums.size() - 1;
        int res = -1;
        while (left < right)
        {
            /* code */
            int mid = (left + right) / 2;
            if(mid - 1 >= 0 && nums[mid - 1] < nums[mid])
        }
        return res;
    }
};