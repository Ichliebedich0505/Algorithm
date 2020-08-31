#include <vector>
#include <cstdio>
using namespace std;
class Solution {
public:
    void combineCore(vector<int>& candidates, int index, int target, vector<vector<int>>& res, vector<int> current, int sum) {
        if (index > candidates.size() - 1) {
            return;
        }
        if (sum > target) {
            return;
        }

        if (sum == target) {
            res.push_back(current);
            return;
        }
        int thisRound = index;
        current.push_back(candidates[thisRound]);
        combineCore(candidates, thisRound, target, res, current, sum+candidates[thisRound]);
        current.pop_back();
        combineCore(candidates, thisRound+1, target, res, current, sum);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // 每个数字都是要么选择跟不选
         // 就算当前满足了也要继续前进
        int index = 0;
        vector<vector<int>> res;
        vector<int> current;
        combineCore(candidates, index, target, res, current, 0);
        return res;
    }
};
int main() {
    Solution s;
    vector<int> v = {2,3,5};
    vector<vector<int>> res = s.combinationSum(v, 8);
    for(int i =0; i< res.size(); i++){
        vector<int> vv = res[i];
        for(int j = 0; j < vv.size(); j++){
            printf("%d ", vv[j]);
        }
        printf("\n");
    }
}




