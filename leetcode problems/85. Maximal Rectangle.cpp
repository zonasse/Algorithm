class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int maxArea = 0;
        vector<int> height(n,0);
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                height[j] = matrix[i][j] == '0' ? 0:(height[j]+1);
            }
            maxArea = max(maxArea,maxRecFromBottom(height));
        }
        return maxArea;
    }
    int maxRecFromBottom(vector<int> &height){
        if(height.size() == 0) return 0;
        int maxArea = 0;
        stack<int> h_stack;
        for(int i=0; i<height.size(); ++i){
            while(!h_stack.empty() && height[h_stack.top()] >= height[i]){
                int j = h_stack.top();
                h_stack.pop();
                int k = h_stack.empty() ? -1:h_stack.top();
                int curArea = (i-k-1)*height[j];
                maxArea = max(curArea,maxArea);
            }
            h_stack.push(i);
        }
        while(!h_stack.empty()){
            int j = h_stack.top();
            h_stack.pop();
            int k = h_stack.empty() ? -1:h_stack.top();
            int curArea = (height.size()-k-1)*height[j];
            maxArea = max(maxArea,curArea);
        }
        return maxArea;
    }
};
