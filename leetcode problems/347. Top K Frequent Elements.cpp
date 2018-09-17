struct Node{
    int val;
    int times;
    Node(int v,int t){
        val = v;
        times = t;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> M;
        for(int i=0; i<nums.size(); ++i){
            if(!M.count(nums[i])){
                M[nums[i]] = 1;
            }else{
                M[nums[i]]++;
            }
        }
        vector<Node*> smallHeap(k);
        int index = 0;
        for(auto it = M.begin(); it != M.end(); ++it){
            Node *cur = new Node(it->first,it->second);
            if(index != k){
                smallHeap[index] = cur;
                heapInsert(smallHeap,index++);
            }else{
                if(cur->times > smallHeap[0]->times){
                    smallHeap[0] = cur;
                    heapify(smallHeap,0,k);
                }
            }
        }
        vector<int> res;
        for(int i=k-1; i>=0; --i){
            res.push_back(smallHeap[0]->val);
            swap(smallHeap[0],smallHeap[i]);
            heapify(smallHeap,0,i);
        }
        return res;
    }
    void heapInsert(vector<Node*> &smallHeap,int index){
        while(index){
            int parent = (index-1)/2;
            if(smallHeap[parent]->times > smallHeap[index]->times){
                swap(smallHeap[parent],smallHeap[index]);
                index = parent;
            }else{
                break;
            }
        }
    }
    void heapify(vector<Node*> &smallHeap,int index,int heapSize){
        int left = index*2 + 1;
        int right = left + 1;
        int smallestIndex = index;
        while(left < heapSize){
            if(smallHeap[left]->times < smallHeap[index]->times){
                smallestIndex = left;
            }
            if(right < heapSize && smallHeap[right]->times < smallHeap[smallestIndex]->times){
                smallestIndex = right;
            }
            if(smallestIndex == index) break;
            swap(smallHeap[index],smallHeap[smallestIndex]);
            index = smallestIndex;
            left = index*2 + 1;
            right = left + 1;
        }
    }
};
