#include <bits/stdc++.h>
using namespace std;

void merge(int* data, int low, int mid, int high) {

    int* A = new int[high - low + 1];
    int left = low, right = mid + 1, k =0;
    while (left <= mid && right <= high)
    {
        /* code */
        if (data[left] < data[right])
        {
            /* code */
            A[k++] = data[left++];
        }else{
            A[k++] = data[right--];
        }
    }
    while(left <= mid) {
        A[k++] = data[left++];
    }

    while(right <= high){
        A[k++] = data[right--];
    }
    for(int i = low; i<= high; i++){
        data[i] = A[i - low];
    }
    delete A;
    
}

// 归并排序
void mergeSort(int* data, int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(data, low, mid);
        mergeSort(data, mid+1, high);
        merge(data, low, mid, high);
    }
}

class Solution {
public:
    // 依然是从小到大排序，但是从右到左统计更方便
    // 可以直接修改mergeSort，但是不太优雅
    int InversePairs(vector<int> data) {
        if (data.size() < 2) return 0;
        vector<int> copy;
        for(int i = 0; i< data.size(); i++){
            copy.push_back(data[i]);
        }
        return inverseCore(data, copy, 0, data.size() - 1)%1000000007;
    }

    int inverseCore(vector<int>& data, vector<int>& copy, int begin, int end){
        if(begin >= end) {
            copy[begin] = data[begin];
            return 0;
        }
        int mid = (begin + end) / 2;
        // 通过这种方式交换数组更新，实在是高。但是比较难理解
        int left = inverseCore(copy, data, begin, mid)%1000000007;
        // 通过这种方式交换数组更新
        int right = inverseCore(copy, data, mid + 1, end)%1000000007;

        int cnt = 0, k = end, small = mid, big = end;
        while(small >= begin && big >= mid + 1){
            if(cnt >= 1000000007) {
                cnt %= 1000000007;
            }
            if(copy[small] > copy[big]){
                data[k--] = copy[small];
                cnt += (big - mid);
                small--;
            }else{
                data[k--] = copy[big--];
            }
        }
        while(small >= begin){
            data[k--] = copy[small--];
        }

        while (big >= mid + 1)
        {
            /* code */
            data[k--] = copy[big--];
        }
        

        return (left + right + cnt) % 1000000007;
    }
};

