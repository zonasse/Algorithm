/*
 * 思路：用j和i索引记录滑动窗口记录当前遍历到的元素范围。若j索引指向元素不在集合中，则将其加入集合，并更新最大长度，右侧+1，否则滑动窗口左侧+1。
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> char_set;
        int ans = 0;
        int i=0;
        int j=0;
        while(i < s.size() && j < s.size()){
            if(char_set.find(s[j]) == char_set.end()){
                char_set.insert(s[j]);
                ans = max(ans,j-i+1);
                j++;
            }else{
                char_set.erase(s[i]);
                i++;
            }
        }
        return ans;
    }
};
