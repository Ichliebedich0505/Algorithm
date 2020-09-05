#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // 以后看到排列permutation，第一反应要是swap
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        core(nums, 0, res);
        return res;
    }
    void core(vector<int>& nums, int start, vector<vector<int>>& res) {
        if(start >= nums.size()) res.push_back(nums);
        for(int i = start; i< nums.size(); i++){
            swap(nums[start], nums[i]);
            core(nums, start + 1, res);
            swap(nums[start], nums[i]);
        }
    }
};

// 还有常规的递归法（回溯的思想），回溯的核心就是使用一个visit数组表示路径
// 这种类型的回溯，就要求每次都从0开始了
class S {
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> visit(nums.size(), 0), out;
        core(nums, 0, out, visit, res);
        return res;
    }
    void core(vector<int>& nums, int level, vector<int>& out, vector<int>& visit, vector<vector<int>>& res) {
        if(level >= nums.size()) {
            res.push_back(out);
            return;
        }
        // 这种类型的回溯，就要求每次都从0开始了
        for(int i = 0; i< nums.size(); i++){
            if(visit[i] == 1) continue;
            visit[i] = 1;
            out.push_back(nums[i]);
            core(nums, level + 1, out, visit, res);
            out.pop_back();
            visit[i] = 0;
        }
    }
};
