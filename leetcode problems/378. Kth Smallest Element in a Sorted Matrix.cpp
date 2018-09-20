class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int left = matrix[0][0];
        int right = matrix.back().back();
        while(left <= right){
            int mid = left + (right-left)/2;
            int cnt = lessCount(matrix,mid);
            if(cnt < k){
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        return left;
    }
    int lessCount(vector<vector<int>>& matrix,int target){
        int r = matrix.size()-1;
        int c = 0;
        int res = 0;
        while(r >= 0 && c < matrix.size()){
            if(matrix[r][c] > target){
                r--;
            }else{
                res += r+1;
                c++;
            }
        }
        return res;
    }
};
