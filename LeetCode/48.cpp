#include <vector>
using namespace std;
// 我的做法：4次循环；按照坐标转换公式与下一坐标进行交换-----这个解法本身就有问题
// 正确解法：转置+反转
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n < 2) return;
        // 核心，非边界条件 
        for(int i =0; i< n-1; i++){
            int beginX = 0, beginY = i;
            int traverseX = beginX, traverseY = beginY;
            int tmp = -1,tmp1, loopCnt = n;
            while (loopCnt--)
            {
                /* code 在我的解法里，纵坐标的变换尤为关键。坐标转换公式没问题，但是解法本身就错了*/
                int nextX = traverseY, nextY = n - 1 - traverseX;
                tmp1 = matrix[traverseX][traverseY];
                if (tmp == -1) {
                    tmp = tmp1;
                    traverseX = nextX, traverseY = nextY;
                    continue;
                }
                matrix[traverseX][traverseY] = tmp;
                tmp = tmp1;
                traverseX = nextX, traverseY = nextY;
            }
        }
    }

    // 正确解法
    void rotate(int[][] matrix) {
        int n = matrix.length;

        // transpose matrix
        for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int tmp = matrix[j][i];
            matrix[j][i] = matrix[i][j];
            matrix[i][j] = tmp;
        }
        }
        // reverse each row
        for (int i = 0; i < n; i++) {
        for (int j = 0; j < n / 2; j++) {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[i][n - j - 1];
            matrix[i][n - j - 1] = tmp;
        }
        }
  }
};