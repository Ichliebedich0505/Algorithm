/**
 * 
 *      核心：
 *          只保存下标，不保存对应的数值
 *          有两段重复的代码
 *          逢小才入，大就弹出再加入新的大的
 * 
*/

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> res;
        int vsize = num.size();
        if(vsize < size || size < 1){
            return {};
        }
        // q只保存下标，不保存数字
        deque<int> q;
        // 只保留第一个窗口最大的数字(的下标)
        for(int i = 0; i< size; i++){
            while (!q.empty() && num[i] >= num[q.back()])
            {
                /* code */
                q.pop_back();
            }
            q.push_back(i);
        }
        for(int i = size; i< vsize; i++){
            res.push_back(num[q.front()]);
            if(!q.empty() &&  - q.front() >= size) {
                q.pop_front();
            }
            while (!q.empty() && num[i] >= num[q.back()])
            {
                /* code */
                q.pop_back();
            }
            q.push_back(i);
        }
        return res;
        
    }
};
int main()
{

}