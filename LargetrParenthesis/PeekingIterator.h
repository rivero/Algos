#pragma once
namespace PeekingIterator
{
	//Implement an iterator that supports the peek operation on an existing iterator in
		//addition to the hasNext and the next operations.


		//Below is the interface for Iterator, which is already defined for you.
		//** DO NOT** modify the interface for Iterator.

	class Iterator
	{
		struct Data;
		Data* data;
	public:
		Iterator(const vector<int>& nums);
		Iterator(const Iterator& iter);

		// Returns the next element in the iteration.
		int next();

		// Returns true if the iteration has more elements.
		bool hasNext() const;
	};

	Iterator::Iterator(const vector<int>& nums)
	{

	}

	class PeekingIterator {
	private:
		Iterator* iter;
		bool hasPeeked;
		int peekedValue;

	public:
		PeekingIterator(Iterator* iter) {
			this->iter = iter;
			hasPeeked = false;
			peekedValue = 0;
		}

		// Returns the next element in the iteration without advancing the iterator.
		int peek() {
			if (!hasPeeked) {
				peekedValue = iter->next();
				hasPeeked = true;
			}
			return peekedValue;
		}

		// Returns the next element in the iteration.
		int next() {
			if (hasPeeked) {
				hasPeeked = false;
				return peekedValue;
			}
			return iter->next();
		}

		// Returns true if the iteration has more elements.
		bool hasNext() const {
			return hasPeeked || iter->hasNext();
		}
	};

}