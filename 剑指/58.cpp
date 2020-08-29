#include <string>
#include <iostream>
/***
 * 
 * 
 *  错在两个地方：string传入函数的修改要生效要用引用"&"
 *              然后空格间单词的寻找没那么容易（开头空格要考虑去掉；除了遇到空格要翻转，遇到结束符也要）。
*/
using namespace std;
class Solution {
public:
    string ReverseSentence(string str) {
        //
        str = wordReverse(str, 0, str.length()-1);
        int prev = 0;
        int i = 0, j = 0, len = str.length();
        while(j <= len) {
            if(i < len && str[i] == ' '){
                i++, j++;
            }
            else if (j == len || str[j] == ' '){
                str = wordReverse(str, i, j-1);
                j++;
                i = j;
            }else
            {
                /* code */
                j++;
            }

        }

        return str;
    }

    string wordReverse(string str, int begin, int end) {
        int i = begin, j = end;
        while (i < j)
        {
            /* code */
            char a = str[i];
            str[i] = str[j];
            str[j] = a;
            i++, j--;
        }
        return str;
    }
};

int main(){
    string str = "I am a student.";
    Solution s;
    cout << s.ReverseSentence(str);
}