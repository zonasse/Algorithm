class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        if(data.empty()){
            return 0;
        }
        int count = 0;
        int first = getFirstK(data,0,data.size()-1,k);
        int last = getLastK(data,0,data.size()-1,k);
        if(first > -1 && last > -1){
            count = last-first+1;
        }
        return count;
    }
    int getFirstK(vector<int> &data,int left,int right,int k){
        int first = -1;
        while(left <= right){
            int mid = left + (right-left)/2;
            if(data[mid] == k){
                if(mid == left || data[mid] != data[mid-1]){
                    first = mid;
                    break;
                }else{
                    right = mid-1;
                }
            }else if(data[mid] < k){
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        return first;

    }
        int getLastK(vector<int> &data,int left,int right,int k){
        int last = -1;
        while(left <= right){
            int mid = left + (right-left)/2;
            if(data[mid] == k){
                if(mid == right || data[mid] != data[mid+1]){
                    last = mid;
                    break;
                }else{
                    left = mid+1;
                }
            }else if(data[mid] < k){
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        return last;

    }
};
