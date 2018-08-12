class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size() == 2){
            return min(height[0],height[1]);
        }
        int left = 0;
        int right = height.size()-1;
        int water = 0;
        while(left < right){
            int curWater = min(height[left],height[right]) * abs(right-left);
            water = max(water,curWater);
            if(height[left] > height[right]){
                right --;
            }else{
                left++;
            }
        }
        return water;
    }
};
