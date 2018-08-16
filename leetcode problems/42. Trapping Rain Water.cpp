class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int left = 0;
        int right = height.size()-1;
        while(left < right){
            int minH = min(height[left],height[right]);
            if(minH == height[left]){
                while(++left < right && height[left] < minH){
                    res += minH - height[left];
                }
            }else{
                while(--right > left && height[right] < minH){
                    res += minH - height[right];
                }
            }
        }
        return res;
    }
};
