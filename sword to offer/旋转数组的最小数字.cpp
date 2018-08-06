class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.empty()){
            return 0;
        }
        int left = 0;
        int right = rotateArray.size()-1;
        int mid = left;
        while(rotateArray[left] >= rotateArray[right]){
            if(right - left == 1){
                mid = right;
                break;
            }
            mid = left + (right-left)/2;
            if(rotateArray[mid] >= rotateArray[left]){
                //位于前一个数组中
                left = mid;
            }else if(rotateArray[mid] <= rotateArray[right]){
                //位于后一个数组中
                right = mid;
            }
        }
        return rotateArray[mid];
    }
};
