#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if(input.size() <= 0) return {};
        // 1) 第一种解法，基于快排改进过来
        core(input, k, 0, (int)(input.size() - 1));
        return input;

        // 2）第二种解法，依靠大顶堆
    }
    void core(vector<int>& input, int k, int begin, int end){
        if(begin >= end) return;
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
        core(input, k, begin, left-1);
        core(input, k, left+1, end);
    }
};
int main(){
    Solution s;
    vector<int> res  = s.GetLeastNumbers_Solution({10, 8, 11, 7, 6, 1, 2, 5}, 3);
    for(int i =0; i< res.size(); i++){
        printf("%d\t", res[i]);
    }
}