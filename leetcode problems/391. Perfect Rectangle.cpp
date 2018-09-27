class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        unordered_map<string,int> M;
        int min_x = INT_MAX;
        int min_y = INT_MAX;
        int max_x = INT_MIN;
        int max_y = INT_MIN;
        int area = 0;
        int blueCount = 0;
        for(auto rect : rectangles){
            min_x = min(min_x,rect[0]);
            min_y = min(min_y,rect[1]);
            max_x = max(max_x,rect[2]);
            max_y = max(max_y,rect[3]);
            area += (rect[2]-rect[0])*(rect[3]-rect[1]);
            if(!valid(M,to_string(rect[0])+"_"+to_string(rect[1]),1)) return false;
            if(!valid(M,to_string(rect[0])+"_"+to_string(rect[3]),2)) return false;
            if(!valid(M,to_string(rect[2])+"_"+to_string(rect[3]),4)) return false;
            if(!valid(M,to_string(rect[2])+"_"+to_string(rect[1]),8)) return false;
        }
        for(auto it = M.begin(); it != M.end(); ++it){
            int cnt = it->second;
            if(cnt != 15 && cnt != 12 && cnt != 10 && cnt != 9 && cnt != 6 && cnt != 5 && cnt != 3) blueCount++;
        }
        return blueCount == 4 && (area == (max_y-min_y)*(max_x-min_x));
    }
    bool valid(unordered_map<string,int> &M,string corner,int type){
        int &cnt = M[corner];
        if(cnt & type) return false;
        cnt |= type;
        return true;
    }
};
