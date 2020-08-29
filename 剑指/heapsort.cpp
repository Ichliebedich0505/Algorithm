#include <cstdio>
#include <cstdlib>
using namespace std;
// 假设下面已经排好序
void adjustDown(int* data, int len, int k) {
    data[0] = data[k];
    int i = k*2;
    for (; i<= len; i*=2){
        // 注意i< len的越界判断。涉及到+1的数组读取就要注意。
        if(i< len && data[i] < data[i+1]) i++;
        if(data[i] > data[0]){
            swap(data[k], data[i]);
            k = i;
        }else
        {
            break;
        }
    }
    
}
void heapsort(int* data, int len){
    // 先build
    for(int i = len/2; i > 0; i--){
        adjustDown(data, len, i);
    }
    for(int i = len; i > 0; i--){
        swap(data[i], data[1]);
        adjustDown(data, i - 1, 1);
    }
}

int main() {

}