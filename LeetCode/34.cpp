#include <stdc++.h>
using namespace std;
// 警醒：二分法的区间设置要加1和减1这个细节别忘了
class Solution {
public:
    int search(vector<int>& nums, int target, int left, int right){
        int first = -1;
        while (left <= right)
        {
            /* code */
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                first = mid;
                break;
            }else if(nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return first;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int smallest = -1, biggest = -1;
        if(nums.size() == 1){
            if(nums[0] == target) {
                return vector<int>{0, 0};
            }else{
                return vector<int>{-1, -1};
            }
        }

        smallest = biggest = search(nums, target, 0, nums.size() - 1);
        while (smallest > 0 && nums[smallest] == nums[smallest - 1])
        {
            /* code */
            smallest --;
            int res = search(nums, target, 0, smallest);
            if (res >= 0 && res < smallest){
                smallest = res;
            }
        }

        while (biggest >= 0 && biggest < nums.size() - 1 && nums[biggest] == nums[biggest + 1])
        {
            /* code */
            biggest ++;
            int res = search(nums, target, biggest, nums.size() - 1);
            if (res >= 0 && res > biggest){
                biggest = res;
            }
        }
        
        return vector<int>{smallest, biggest};
    }
};