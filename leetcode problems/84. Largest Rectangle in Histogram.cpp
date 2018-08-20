class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size() == 0) return 0;
        stack<int> h_stack;
        int maxArea = 0;
        for(int i=0; i<heights.size(); ++i){
            while(!h_stack.empty() && heights[i] <= heights[h_stack.top()]){
                int j = h_stack.top();
                h_stack.pop();
                int k = h_stack.empty()? -1:h_stack.top();
                int curArea = (i-k-1)*heights[j];
                maxArea = max(maxArea,curArea);
            }
            h_stack.push(i);
        }
        while(!h_stack.empty()){
            int j = h_stack.top();
            h_stack.pop();
            int k = h_stack.empty()? -1:h_stack.top();
            int curArea = (heights.size() - k - 1)*heights[j];
            maxArea = max(maxArea,curArea);
        }
        return maxArea;
    }
};
