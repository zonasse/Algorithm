class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> ret;
        if(num.empty() || size <= 0 || num.size() < size){
            return ret;
        }
        deque<int> window;
        for(int i=0; i<num.size(); ++i){
            while(window.empty() == false && num[window.back()] <= num[i]){
                window.pop_back();
            }
            window.push_back(i);
            if(i-size == window.front()){
                window.pop_front();
            }
            if(i >= size - 1){
                ret.push_back(num[window.front()]);
            }
        }
        return ret;
    }
};
