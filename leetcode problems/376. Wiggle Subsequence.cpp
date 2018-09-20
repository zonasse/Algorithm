enum WiggleState{
    WiggleStateBegin = 0,
    WiggleStateUp = 1,
    WiggleStateDown = 2
};
class Solution1 {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        WiggleState state = WiggleStateBegin;
        int count = 1;
        for(int i=1; i<nums.size(); ++i){
            switch(state){
                case WiggleStateBegin:
                    if(nums[i-1] > nums[i]){
                        state = WiggleStateDown;
                    }else if(nums[i-1] < nums[i]){
                        state = WiggleStateUp;
                    }else{
                        continue;
                    }
                    count++;
                break;
                case WiggleStateUp:
                    if(nums[i-1] > nums[i]){
                        state = WiggleStateDown;
                        count++;
                    }
                break;
                case WiggleStateDown:
                    if(nums[i-1] < nums[i]){
                        state = WiggleStateUp;
                        count++;
                    }
                break;
            }
        }
        return count;
    }
};
class Solution2 {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int p=1,q=1;
        for(int i=1; i<nums.size(); ++i){
            if(nums[i-1] > nums[i]){
                q = p+1;
            }else if(nums[i-1] < nums[i]){
                p = q+1;
            }
        }
        return min((int)nums.size(),max(p,q));
    }
};
