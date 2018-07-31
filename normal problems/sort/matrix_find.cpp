#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool matrix_find(vector<vector<int> > &nums,int target){
        int row = nums.size();
        int col = nums[0].size();
        int curRow = 0;
        int curCol = col-1;
        while(curRow < row && curCol >= 0 ){
            int curNum = nums[curRow][curCol];
            if(curNum == target){
                return true;
            }else if(curNum < target){
                curRow++;
            }else{
                curCol--;
            }
        }
        return false;


    }

};
int main(){
    int arr[][5] = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15}};
    Solution s;
    vector<vector<int> > nums;
    for(int i=0; i<3; ++i){
        vector<int> temp;
        for(int j=0; j<5; ++j){
            temp.push_back(arr[i][j]);
        }
        nums.push_back(temp);
    }
    printf("%d\n",s.matrix_find(nums,16));
    return 0;
}
