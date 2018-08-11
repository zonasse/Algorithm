/*
 * manacherÀ„∑®
 */
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty()){
            return "";
        }
        string manacher = manacherString(s);
        int pR = -1;
        int pArr[manacher.size()] = {0};
        int index = -1;
        int maxLen = -0x7fffffff;
        int longestIndex = -1;
        for(int i=0; i<manacher.size(); ++i){
            pArr[i] = pR>i ? min(pArr[2*index - i],pR-i):1;
            while(i+pArr[i] < manacher.size() && i-pArr[i] > -1){
                if(manacher[i+pArr[i]] == manacher[i-pArr[i]]){
                    pArr[i]++;
                }else{
                    break;
                }
            }
            if(i+pArr[i] > pR){
                pR = i+pArr[i];
                index = i;
            }
            if(pArr[i] >= maxLen){
                maxLen = pArr[i];
                longestIndex = i;
            }
        }
        int startIndex = longestIndex-maxLen+1;
        string res = "";
        for(int i=startIndex; i<=longestIndex+maxLen-1; ++i){
            if(manacher[i] == '#') continue;
            res+=manacher[i];
        }
        return res;



    }
    string manacherString(string str){
        string manacher = "";
        int index = 0;
        for(int i=0; i<(str.size()*2+1); ++i){
            manacher += (i%2) == 0 ? '#':str[index++];
        }
        return manacher;
    }
};
