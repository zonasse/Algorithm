class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        M[val].insert(nums.size());
        nums.push_back(val);
        return M[val].size() == 1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(M[val].empty()) return false;
        int deletedIndex = *M[val].begin();
        M[val].erase(deletedIndex);
        if(deletedIndex != nums.size()-1){
            int lastNum = nums.back();
            nums[deletedIndex] = lastNum;
            M[lastNum].erase(nums.size()-1);
            M[lastNum].insert(deletedIndex);
        }
        nums.pop_back();
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return nums[rand()%nums.size()];
    }
private:
    vector<int> nums;
    unordered_map<int,unordered_set<int> > M;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
