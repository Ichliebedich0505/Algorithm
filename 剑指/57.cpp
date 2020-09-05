#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        if (sum <= 2) return {};
        int left = 1, right = left + 1;
        vector<int> cur;
        vector<vector<int>> res;
        // 99 = 49 + 50
        int curSum = left + right;
        // 加1的话，不管是偶数还是奇数都好使。
        while (left < right && left < (sum + 1 ) / 2)
        {
            if (curSum == sum) {
                cur.clear();
                for(int i = left; i <= right; i++){
                    cur.push_back(i);
                }
                res.push_back(cur);
                // 无论如何都要继续前进
                right ++;
                curSum += right;
            }else if(curSum > sum){
                curSum -= left;
                left++;
            }else {
                // 无论如何都要继续前进
                right ++;
                curSum += right;
            }

        }
        

        return res;
    }
};