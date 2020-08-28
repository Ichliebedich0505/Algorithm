#include <vector>
using namespace std;
class Solution {
public:
    int findTheFirstDecreasing(vector<int> nums) {
        int end = nums.size() - 1;
        int target = -1;
        for(int i = end; i > 0; i--){
            if(nums[i-1] < nums[i]){
                target = i - 1;
                break;
            }
        }
        return target;
    }
    int findTheFirstBigger(vector<int> nums, int n) {
        int end = nums.size() - 1;
        int target = -1;
        for(int i = end; i > 0; i--){
            if(nums[i] > n){
                target = i;
                break;
            }
        }
        return target;
    }
    void transposition(vector<int>& nums, int start) {
        int end = nums.size() - 1;
        while (start < end)
        {
            /* code */
            int tmp = nums[start];
            nums[start] = nums[end];
            nums[end] = tmp;
            start ++, end--;
        }
    }
    void nextPermutation(vector<int>& nums) {
        if(nums.size() <= 1){
            return;
        }
        int fd = findTheFirstDecreasing(nums);
        if(fd > -1) {
            int tmp = nums[fd];
            int fb = findTheFirstBigger(nums, tmp);
            nums[fd] = nums[fb];
            nums[fb] = tmp;
        }
        if(fd > -1){
            transposition(nums, fd+1);
        }else
        {
            /* code */
            transposition(nums, 0);
        }
        
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
