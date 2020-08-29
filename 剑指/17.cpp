#include <string>
#include <iostream>

using namespace std;
int cnt = 0;
void core(int n, string number, bool isTop){
    if(n == 0){
        int size = number.size();
        printf("%s\t", number.data());
        cnt++;
        return;
    }
    for(int i =0; i<= 9; i++){
        if(i == 0 && isTop){
            continue;
        }

        char c = '0' + i;
        core(n-1, number+c, false);
    }
}
void Print1ToMaxOfNDigits(int n){
    // 采用递归的话，就要从9开始
    if(n <= 0){
        return;
    }
    string number = "";
    for(int i = 1; i<= n; i++){
        core(i, number, true);
    }

}



int main(){
    string str = "I am a student.";
    Print1ToMaxOfNDigits(3);
    cout << endl;
    cout << cnt;
}