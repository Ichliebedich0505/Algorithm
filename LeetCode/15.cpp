#include <vector>
#include <cstdlib>
#include <cmath>
using namespace std;
vector<vector<int>> threeSum(vector<int>& nums) {

    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    for(int i = 0; i < (int)nums.size() - 2; i++){
        if(nums[i] > 0)
            break;
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        int target = 0 - nums[1], begin = i + 1, end = (int)nums.size() - 1;
        while (begin < end)
        {
            /* code */
            if (nums[begin] + nums[end] == target) {
                res.push_back({nums[i], nums[begin], nums[end]});
                while (begin < end && nums[begin] == nums[begin + 1])
                {
                    /* code */
                    begin ++;
                }

                while (begin < end && nums[end] == nums[end - 1])
                {
                    /* code */
                    end --;
                }
                begin ++;
                end --;
            }else if (nums[begin] + nums[end] < target){
                begin ++;
            }else {
                end --;
            }
        }
        
        
    }

}