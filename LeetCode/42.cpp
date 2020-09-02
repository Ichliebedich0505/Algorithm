#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int sum = 0, size = height.size();
        // 并不是说每轮都要自加1
        for(int i =0; i < size; ) {
            if(st.empty() || (height[st.top()] >= height[i])) {
                // 并不是说每轮都要自加1。只有push进去一个后才自加1.
                st.push(i++);
            }else {
                // 突然变高了，说明可能有坑位
                int top = height[st.top()];
                // 取出来当坑使用
                st.pop();
                if(st.empty()) continue;
                // 要减去坑的高度
                sum += (min(height[st.top()], height[i]) - top) * (i - st.top() - 1);
            }
        }
        return sum;
    }
};
