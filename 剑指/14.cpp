#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int cutRope(int number) {
        if(number < 2){
            return 0;
        }

        if(number == 2){
            return 1;
        }
        if(number == 3){
            return 2;
        }
        int* n =new int[number+1];
        n[0] = 0;
        n[1] = 1;
        n[2] = 2;
        n[3] = 3;

        // 公式：f(n) = max(f(i)*f(n-i))
        for(int i = 4; i<= number; i++){
            for(int j = 1; j <= i/2; j++){
                n[i] = max(n[i], n[j]*n[i - j]);
            }
        }
        return n[number];
    }
};