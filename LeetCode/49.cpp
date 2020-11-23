#include <string>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        while (strs.size() > 0)
        {
            /* code */
            vector<string> vStr = strsIter(strs);
            res.push_back(vStr);
        }
        return res;
    }

    vector<string> strsIter(vector<string>& partOfStrs) {
        vector<string> res;
        map<char, bool> charsMap;
        // 标准库用法之边遍历边删除只能使用迭代器
        for(vector<string>::iterator it = partOfStrs.begin(); it != partOfStrs.end();){
            if(charsMap.size() <= 0){
                for(int j =0; j< (*it).size(); j++){
                    charsMap.insert(pair<char, bool>((*it)[j], true));
                }
                // 边缘条件---空字符串
                if(charsMap.size() <= 0){
                    charsMap.insert(pair<char, bool>('\0', true));
                }
                res.push_back((*it));
                // 标准库用法之vector erase返回的是下一个指针
                it = partOfStrs.erase(it);
                continue;
            }else
            {
                if((*it) == ""){
                    res.push_back((*it));
                    it = partOfStrs.erase(it);
                    continue;
                }
                if (check(*it, charsMap)){
                    res.push_back((*it));
                    it = partOfStrs.erase(it);
                    continue;
                }
            }
            if(it == partOfStrs.end()){
                break;
            }
            it++;
        }
        return res;
    }

    // error: 但是我的思路是错误解法，因为当字符串长度不一样或者字符串里边有重复字符，check返回的结果就可能有问题了。
    bool check(string str, map<char, bool> charsMap){
        bool res = false;
        for(int i =0; i< str.size(); i++){
            if(charsMap.find(str[i]) != charsMap.end()){
                res = true;
            }else
            {
                res = false;
                return res;
            }
            
        }
        return res;
    }
};


// 正确答案
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> strMap;
        vector<vector<string>> res;

        for(auto str: strs){
            auto key = str;
            sort(key.begin(), key.begin()+key.size());
            strMap[key].push_back(str);
        }

        for(auto v: strMap){
            // map的遍历结果是个pair，要调用second
            res.push_back(v.second);
        }
        return res;
    }
};