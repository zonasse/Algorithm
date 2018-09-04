// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    _flag = false;
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if(!_flag){
            _value = Iterator::next();
            _flag = true;
        }
        return _value;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    if(!_flag) return Iterator::next();
        _flag = false;
        return _value;
	}

	bool hasNext() const {
	    if(_flag) return true;
        if(Iterator::hasNext()) return true;
        return false;
	}
private:
    int _value;
    bool _flag;//是否保存了下一个值
};
