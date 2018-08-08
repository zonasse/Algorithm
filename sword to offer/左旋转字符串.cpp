class Solution {
public:


    string LeftRotateString(string str, int n) {

        if(str.size() == 0){
            return str;
        }
        n %= str.size();
        reversePart(str,0,n-1);
        reversePart(str,n,str.size()-1);
        reversePart(str,0,str.size()-1);
        return str;
    }
    void reversePart(string &str,int left,int right){
        while(left < right){
            char temp = str[left];
            str[left] = str[right];
            str[right] = temp;
            left++;
            right--;
        }
    }
};
