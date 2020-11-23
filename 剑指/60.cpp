#include <cmath>
using namespace std;


double probability(int n, int s){
    if(s < n || s > 6 * n){
        return 0;
    }

    double prob = 0.0;
    prob = core(n, s, 0);
    prob /= pow(6.0, n);
    return prob;
}

int core(int numOfDice, int targetSum, int curSum){
    if(numOfDice <= 0) return 0;
    if(curSum == targetSum){
        return 1;
    }else if(curSum > targetSum)
    {
        return 0;
    }
    int cnt = 0;
    for(int j =1; j<= 6; j++){
            cnt += core(numOfDice - 1, targetSum, curSum + j);
        }
    return cnt;
}

// 有更高效的方法
