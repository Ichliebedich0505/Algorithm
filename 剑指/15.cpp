class Solution {
public:
     int  NumberOf1(int n) {
        // 负数的补位不是0，而是1，会一直死循环
        int limit = 32;
        int cnt = 0;
        while (n != 0 && limit > 0)
        {
            /* code */
            if (n & 1) cnt++;
            n >>= 1;
            limit --;
        }
        return cnt;
     }
};