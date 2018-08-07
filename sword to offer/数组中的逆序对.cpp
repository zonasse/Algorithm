class Solution {
public:
    int count;
    int InversePairs(vector<int> data) {
        if(data.size() < 2){
            return 0;
        }
        count = 0;
        mergeSort(data,0,data.size()-1);
        return count%1000000007;
    }
    void mergeSort(vector<int> &data,int start,int end){
        if(start >= end){
            return;
        }
        int mid = start + (end-start)/2;
        mergeSort(data,start,mid);
        mergeSort(data,mid+1,end);
        merge(data,start,mid,end);
    }
    void merge(vector<int> &data,int start,int mid,int end){
        vector<int> support;
        int p1 = start;
        int p2 = mid+1;
        while(p1 <= mid && p2 <=end){
            if(data[p1] < data[p2]){
                support.push_back(data[p1++]);
            }else{
                support.push_back(data[p2++]);
                count = (count + mid-p1+1) % 1000000007;
            }
        }
        while(p1 <= mid){
            support.push_back(data[p1++]);
        }
        while(p2 <= end){
            support.push_back(data[p2++]);
        }
        for(int i=0; i<support.size(); ++i){
            data[start+i] = support[i];
        }
    }
};
