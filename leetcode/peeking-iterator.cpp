// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/peeking-iterator/description/
// Date: 23rd February, 2023
// Tags: design, iterator


/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
public:
	int nextValue;
	bool hasNextValue = false;
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
		if(Iterator::hasNext()) {
			hasNextValue = true;
		}
		if(hasNextValue) {
			nextValue = Iterator::next();
		}
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return nextValue;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    int returnValue = nextValue;

		if(Iterator::hasNext()) {
			hasNextValue = true;
		}
		else {
			hasNextValue = false;
		}
		if(hasNextValue) {
			nextValue = Iterator::next();
		}
		return returnValue;
	}
	
	bool hasNext() const {
	    return hasNextValue;
	}
};
