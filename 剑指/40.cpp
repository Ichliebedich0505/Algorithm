#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if(input.size() <= 0) return {};
        // 1) 第一种解法，基于快排改进过来
        core(input, k, 0, (int)(input.size() - 1));
        vector<int> res;
        for(int i =0; i< k; i++){
            res.push_back(input[i]);
        }
        return res;

        // 2）第二种解法，依靠大顶堆
        multiset<int, greater<int>> st;
        for(int i =0; i< input.size(); i++){
            if(st.size() < k){
                st.insert(input[i]);
            }
            else
            {
                if(input[i] < *st.begin()){
                    st.erase(st.begin());
                    st.insert(input[i]);
                }
            }
        }
        vector<int> res;
        multiset<int>::iterator it = st.begin();
        for(; it != st.end(); it++){
            res.push_back(*it);
        }
        return res;
    }
    void core(vector<int>& input, int k, int begin, int end){
        if(begin >= end) return;
        if(flag) return;
        int pivot = (begin+end)/2, tmp = input[end];
        input[end] = input[pivot], input[pivot] = tmp;

        int left = begin, right = end - 1;
        // 这边条件判断上的等号“=”其实是跟代码“swap(input[left], input[end]);”配套的。等号意味着肯定要让left越过right，这样swap代码那边的交换才有意义。
        while (left <= right)
        {
            /* code */
            while (input[left] < input[end])
            {
                /* code */
                left++;
            }

            while (input[right] > input[end])
            {
                /* code */
                right--;
            }
            if(left < right)
            {
                swap(input[left], input[right]);
            }
        }
        swap(input[left], input[end]);
        if(left== k-1){
            flag = true;
            return;
        }
        if(left > k -1) {
            core(input, k, begin, left-1);
        }else {
            core(input, k, left+1, end);
        }
        
    }
    private:
        bool flag = false;
};
int main(){
    Solution s;
    vector<int> res  = s.GetLeastNumbers_Solution({10, 8, 11, 7, 6, 1, 2, 5}, 3);
    for(int i =0; i< res.size(); i++){
        printf("%d\t", res[i]);
    }
}