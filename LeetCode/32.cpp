#include <string>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0, right = 0, sz = s.size();
        int maxLen = 0;
        for(int i =0; i< sz; i++){
            (s[i] == '(') ? left++ : right++;
            if (left == right) {
                maxLen = (maxLen > 2 * right) ? maxLen : 2 * right;
            }
            else if (left < right){
                left = right = 0;
            }
        }

        left = right = 0;
        for(int i =sz-1; i> 0; i--){
            (s[i] == '(') ? left++ : right++;
            if (left == right) {
                maxLen = (maxLen > 2 * right) ? maxLen : 2 * right;
            }
            else if (left > right) {
                left = right = 0;
            }
        }
        return maxLen;
    }
};