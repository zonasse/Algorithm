class Solution {
public:
    bool isValidSerialization(string preorder) {
        preorder += ",";
        vector<string> arr;
        int i=0;
        int len = preorder.size();
        int left = 0;
        while(++i < len){
            if(preorder[i] == ','){
                arr.push_back(preorder.substr(left,i-left));
                left = i+1;
            }
        }
        int count = 0;
        for(int i=0; i<arr.size()-1; ++i){
            if(arr[i] == "#"){
                if(count == 0) return false;
                count--;
            }else{
                count++;
            }
        }
        return count == 0 && arr.back() == "#";
    }
};
