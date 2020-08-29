#include <cstdio>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // 其实括号的选择就两种，要么左括号，要么右括号。但是这边还要收到n的限制
        string s = "";
        vector<string> res;
        core(n, n, res, s);
        return res;
    }
    void core(int left, int right, vector<string>& res, string s){
        if(left > right){
            return;
        }
        if(left == 0 && right == 0){
            res.push_back(s);
            return;
        } else{

            if (left > 0) core(left-1, right, res, s + "(");

            if(right>0) core( left, right-1, res, s + ")");
        }




    }
};
int main(){
    Solution s;
    vector<string> res = s.generateParenthesis(3);
    int len = res.size();
    for(int i =0; i< len; i++){
        printf("%s\n", res[i].data());
    }
}