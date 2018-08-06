class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.empty()){
            return false;
        }
        return judge(sequence,0,sequence.size()-1);
    }
    bool judge(vector<int> &sequence,int start,int end){
        if(start > end){
            return false;
        }
        if(start == end){
            return true;
        }
        int root = sequence[end];
        int mid = start;
        while(mid < end){
            if(sequence[mid] > root){
                break;
            }
            mid++;
        }
        for(int i=mid+1; i<end; ++i){
            if(sequence[i] < root){
                return false;
            }
        }
        bool leftJudge = true;
        if(mid > 0){
            leftJudge = judge(sequence,start,mid-1);
        }
        bool rightJudge = true;
        if(mid < end){
            rightJudge = judge(sequence,mid,end-1);
        }
        return leftJudge && rightJudge;
    }
};
