class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        size = 0;
        key_index.clear();
        index_key.clear();
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(key_index.find(val) == key_index.end()){
            key_index[val] = size;
            index_key[size] = val;
            size++;
            return true;
        }else{
            return false;
        }
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(key_index.find(val) == key_index.end()){
            return false;
        }else{
            int deleteIndex = key_index[val];
            int lastIndex = --size;
            int lastKey = index_key[lastIndex];

            //½»»»
            key_index[lastKey] = deleteIndex;
            index_key[deleteIndex] = lastKey;

            //É¾³ý
            key_index.erase(val);
            index_key.erase(lastIndex);
            return true;
        }
    }

    /** Get a random element from the set. */
    int getRandom() {
        if(size == 0) return INT_MIN;
        int randIndex = (int)(rand() % size);
        return index_key[randIndex];
    }
private:
    map<int,int> key_index;
    map<int,int> index_key;
    int size;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
