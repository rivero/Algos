#pragma once
/*
146. LRU Cache
Medium
Topics
Companies
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.

int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists.
Otherwise, add the key-value pair to the cache. If the number of keys exceeds the
capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.

Example 1:

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4


Constraints:

1 <= capacity <= 3000
0 <= key <= 104
0 <= value <= 105
At most 2 * 105 calls will be made to get and put.

Solution

1. **Data Structures:**
   - The LRU cache uses two primary data structures:
	 - A **doubly linked list** (`cache`) to maintain the order of elements based on their usage.
	 - An **unordered map** (`mymap`) to store the key-value pairs and their corresponding iterators in the linked list.

2. **Initialization:**
   - The `LRUCache` class is initialized with a specified capacity.
   - The `cache` list is initially empty, and the `mymap` map is also empty.

3. **`moveToFront` Function:**
   - This function takes a `key` and a `value`.
   - It removes the existing entry for the `key` from the `cache`.
   - Then, it pushes a new entry with the same `key` and updated `value` to the front of the `cache`.
   - The corresponding iterator in `mymap` is updated to point to the new position in the `cache`.

4. **`pushFront` Function:**
   - This function adds a new key-value pair to the front of the `cache`.
   - It also updates the corresponding iterator in `mymap`.

5. **`checkCapacity` Function:**
   - This function checks if the current size of the cache (`mymap.size()`) exceeds the specified capacity (`m_capacity`).
   - If so, it removes the least recently used element:
	 - Deletes the entry from `mymap` using the key of the last element in the `cache`.
	 - Removes the last element from the `cache`.

6. **`get` Function:**
   - Given a `key`, it checks if the key exists in `mymap`.
   - If found:
	 - Moves the corresponding element to the front of the `cache` (since it's recently used).
	 - Returns the associated value.
   - If not found, returns `-1`.

7. **`put` Function:**
   - Given a `key` and a `value`:
	 - If the `key` exists in `mymap`, updates its value and moves it to the front.
	 - If the `key` doesn't exist:
	   - Adds a new key-value pair to the front of the `cache`.
	   - Checks the capacity and evicts the least recently used element if needed.

8. **Complexity Analysis:**
   - Time Complexity:
	 - `put()` operation: O(1) (constant time for insertion or update).
	 - `get()` operation: O(1) (constant time to retrieve a value).
   - Auxiliary Space: O(N) (where N is the capacity of the cache).

*/
namespace LRUCache
{

    class LRUCache 
    {
		int m_capacity{};
        list< pair<int, int> > cache;
        unordered_map<int, list< pair<int, int> >::iterator> mymap;

        void moveToFront(int key, int value)
        {
            cache.erase(mymap[key]); // erase from its current position
            pushFront(key, value);
        }

        void pushFront(int key, int value)
        {
            cache.push_front({ key, value }); // push it to the front
            mymap[key] = cache.begin(); // update the map
        }

		void checkCapacity()
		{
			if (mymap.size() > m_capacity)
			{
				// remove the last cache element in the map
				mymap.erase(cache.back().first);
				// ...then remove last element in the cache
				cache.pop_back();
			}
		}

    public:
        LRUCache(int capacity) :m_capacity(capacity)
        {
        }

        int get(int key) 
        {
            if (mymap.find(key) != mymap.end())
            {
                // if the element exists, move it to the front
                moveToFront(key, mymap[key]->second);
                return mymap[key]->second;
            }
            return -1;
        }

        void put(int key, int value) 
        {
            if (mymap.find(key) != mymap.end())
            {
                moveToFront(key, value);
            }
            else
            {
                // element does not exist
				pushFront(key, value);
                checkCapacity();

            }
        }

    };

    /**
     * Your LRUCache object will be instantiated and called as such:
     * LRUCache* obj = new LRUCache(capacity);
     * int param_1 = obj->get(key);
     * obj->put(key,value);
     */

	void process()
	{

	}
}