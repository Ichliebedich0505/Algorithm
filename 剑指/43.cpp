#include <bits/stdc++.h>
using namespace std;
// 先验知识：后N位中，固定1，其他N-1位从0-9选择，按照排列组合，就可以计算出1出现总次数。可以拿22～3来举例子，目前无法从证明的角度去理解。
int getDigits(int n){
    int cnt = 0;
    while (n)
    {
        /* code */
        cnt++;
        n /= 10;
    }
    
    return cnt;
}
int NumberOf1Between1AndN_Solution(int n) {
    if(n <= 0){
        return 0;
    }

    if(n < 10) {
        return 1;
    }

    char* number = new char[100];
    sprintf(number, "%d", n);
    int cnt1 = 0, cnt2 = 0;
    int dit = getDigits(n);
    // 21456~1456
    if(number[0] > '1') {
        cnt1 = (int)pow(10, dit - 1);
    }else {
        cnt1 = atoi(number+1) + 1;
    }
    cnt2 = (number[0] - '0') * (dit - 1) * (int)pow(10, dit - 2);

    return cnt1 + cnt2 + NumberOf1Between1AndN_Solution(atoi(number+1));
}