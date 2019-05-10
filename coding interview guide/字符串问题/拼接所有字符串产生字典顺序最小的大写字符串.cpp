//
// Created by 钟奇龙 on 2019-05-10.
//

#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool compare(string a,string b){
    return a + b < b + a;
}

string lowestString(vector<string> arr){
    if(arr.size() == 0) return "";
    sort(arr.begin(),arr.end(),compare);
    string res = "";
    for(int i=0; i<arr.size(); ++i){
        res += arr[i];
    }
    return res;
}

int main(){
    vector<string> arr = {"b","ba"};
    cout<<lowestString(arr)<<endl;
    return 0;
}