#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
int TranslationCore(char* num){
    // 每一位，要么选，要么不选
    if(*num == '\0'){
        return 1;
    }
    int cnt = 0, len = strlen(num);
    if(len >= 2){
        int futureTwo = (num[0] - '0') * 10 + (num[1] - '0');
        if(futureTwo > 25){
            cnt += TranslationCore(num+1);
        }else
        {
            cnt += (TranslationCore(num+2) + TranslationCore(num+1));
        }
    }else
    {
        /* code */
        cnt += TranslationCore(num+1);
    }
    return cnt;
}
int GetTranslationCount(int number){
    char* num = new char[20];
    sprintf(num, "%d", number);
    return TranslationCore(num);
}
int main(){

}