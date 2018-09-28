class Solution1 {
public:
    bool isSubsequence(string s, string t) {
        int left = 0;
        int right = t.size()-1;
        while(left <= right && s.size()){
            if(t[left] == s[0]){
                s.erase(0,1);
                left++;
            }else if(t[right] == s[s.size()-1]){
                s.pop_back();
                right--;
            }else{
                left++;
                right--;
            }
        }
        return s.size() == 0;
    }
};
class Solution2 {
public:
    bool isSubsequence(string s, string t) {
        int i=0,j=0;
        while(i < s.size() && j < t.size()){
            while(j < t.size() && s[i] != t[j]) j++;
            i++;
            j++;
        }
        return i == s.size() && j <= t.size();
    }
};
