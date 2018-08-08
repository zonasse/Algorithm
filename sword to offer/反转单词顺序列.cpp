class Solution {
public:
    string ReverseSentence(string str) {
        if(str.size() < 2){
            return str;
        }
        reversePart(str,0,str.size()-1);
        str += " ";
        int left = 0;
        int right = 0;
        while(left < str.size() && right < str.size()){
            if(str[right] == ' '){
                reversePart(str,left,right-1);
                left = right+1;
                right = left;
            }else{
                right++;
            }
        }
        str.pop_back();
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
