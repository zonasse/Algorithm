class Solution1 {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res(nums.size());
        vector<int> temp;
        for(int i=nums.size()-1; i>=0; --i){
            int left = 0;
            int right = temp.size();
            while(left < right){
                int mid = left + (right-left)/2;
                if(temp[mid] >= nums[i]) right = mid;
                else left = mid + 1;
            }
            res[i] = right;
            temp.insert(temp.begin()+right,nums[i]);
        }
        return res;
    }
};
struct TNode{
    TNode *left;
    TNode *right;
    int val;
    int smaller;
    TNode(int v,int s): val(v),smaller(s),left(NULL),right(NULL){}
};
class Solution2 {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res(nums.size());
        TNode *root = NULL;
        for(int i=nums.size()-1; i>=0; --i){
            res[i] = insert(root,nums[i]);
        }
        return res;
    }
    int insert(TNode *&root,int val){
        if(!root){
            root = new TNode(val,0);
            return 0;
        }
        if(val < root->val){
            root->smaller++;
            return insert(root->left,val);
        }else{
            return insert(root->right,val) + root->smaller + (root->val < val ? 1:0);
        }
    }
};
