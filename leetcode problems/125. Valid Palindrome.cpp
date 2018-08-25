class Solution1 {
public:
    bool isPalindrome(string s) {
        if(s.empty()) return true;
        transform(s.begin(),s.end(),s.begin(),::tolower);
        int left = 0;
        int right = s.size()-1;
        while(left < right){
            while(!isDigitOrAlpha(s[left])) left++;
            while(!isDigitOrAlpha(s[right])) right--;
            if(left >= right) break;
            if(s[left++] != s[right--]) return false;
        }
        return true;
    }
    bool isDigitOrAlpha(char ch){
        return (ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
    }
};
class Solution2 {
public:
    bool isPalindrome(string s) {
        if(s.empty()) return true;
        int left = 0;
        int right = s.size()-1;
        while(left < right){
            switch(s[left]){
                case '0'...'9':
                    break;
                case 'a'...'z':
                    break;
                case 'A'...'Z':
                    s[left] += 32;
                    break;
                default:
                    left++;
                    continue;
            }
            switch(s[right]){
                case '0'...'9':
                    break;
                case 'a'...'z':
                    break;
                case 'A'...'Z':
                    s[right] += 32;
                    break;
                default:
                    right--;
                    continue;
            }
            if(left >= right) break;
            if(s[left++] != s[right--]) return false;
        }
        return true;
    }
};
