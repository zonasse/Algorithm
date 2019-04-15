//
// Created by 钟奇龙 on 2019-04-15.
//

#include <vector>
#include <deque>

using namespace std;

int getNum(vector<int> arr,int num){
    if(arr.size() == 0) return 0;
    int res = 0;
    deque<int> qmax;
    deque<int> qmin;
    int i=0;
    int j=0;
    while(i < arr.size()){
        while(j < arr.size()){
            while(qmax.empty() == false && arr[qmax.back()] <= arr[j]){
                qmax.pop_back();
            }
            qmax.push_back(j);
            while(qmin.empty() == false && arr[qmin.back()] >= arr[j]){
                qmin.pop_back();
            }
            qmin.push_back(j);
            if(arr[qmax.front()] - arr[qmin.front()] > num){
                break;
            }
            j++;
        }
        if(i == qmax.front()){
            qmax.pop_front();
        }
        if(i == qmin.front()){
            qmin.pop_front();
        }
        res += j-i;
        i++;
    }
    return res;
}

int main(){
    vector<int> arr = {3,1,6,5,2};
    printf("%d",getNum(arr,3));
}