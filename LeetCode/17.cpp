#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> letterCombinations(string digits) {

        if (digits.empty()) return {};
        vector<string> res;
        vector<string> dict{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        letterCombinationsDFS(digits, dict, 0, "", res);
        return res;
    }

    void letterCombinationsDFS(string digits,  vector<string>& dict, int level, string out, vector<string>& res){
        if(level == digits.length()){
            res.push_back(out);
            return;
        }
        int curNum = digits[level] - '0';
        for(int i =0; i < dict[curNum].length(); i++){
            letterCombinationsDFS(digits, dict, level+1, out+dict[curNum][i], res);
        }

    }

};