/*
 *  ∫…¿ºπ˙∆ÏŒ Ã‚
 */
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void three_color(vector<char> &colors){
        if(colors.empty() || colors.size() < 3){
            return;
        }
        _sort(colors,0,colors.size()-1);
    }
private:
    void _sort(vector<char> &colors,int left,int right){
        if(left >= right){
            return;
        }
        int lt = left;
        int i = left+1;
        int gt = right;
        char pivot = colors[left];
        while(i <= gt){
            if(colors[i] > pivot){
                _swap(colors[i],colors[gt--]);
            }else if(colors[i] < pivot){
                _swap(colors[i++],colors[lt++]);
            }else{
                i++;
            }
        }
        _sort(colors,left,lt-1);
        _sort(colors,gt+1,right);
    }
    void _swap(char &a,char &b){
        char temp = a;
        a = b;
        b = temp;
    }
};

int main(){
    char arr[] = {'R','B','W','W','R','W','B','R','R','W','B','R'};
    vector<char> colors(arr,arr+12);
    Solution s;
    s.three_color(colors);
    for(int i=0; i<colors.size(); ++i){
        printf("%c ",colors[i]);
    }
    printf("\n");
    return 0;
}
