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

1. **What is LRU Cache?**
   - LRU Cache is a caching strategy that efficiently manages limited memory space by keeping track of the usage history of cached elements.
   - When the cache is full, LRU removes the least recently used item to make room for new data.
   - The priority of data in the cache changes based on recent access patterns.

2. **How does LRU Cache work?**
   - The LRU cache maintains a fixed-size data structure (e.g., a queue or linked list) to store key-value pairs.
   - When an element is accessed (either read or written), it is moved to the front of the data structure.
   - If the cache is full, the least recently used element (at the end of the data structure) is evicted.

3. **Implementation Details:**
   - The provided implementation uses a doubly linked list (`cache`) and a hashmap (`mymap`) to achieve constant-time operations.
   - `cache` stores key-value pairs, and `mymap` maps keys to their positions in the `cache`.
   - The `moveElementToFront` function updates the position of an element when accessed.
   - The `put` function adds or updates an element, and if the cache is full, it removes the least recently used element.

4. **Time Complexity:**
   - `get(key)` and `put(key, value)` both operate in O(1) time.
   - The hashmap (`mymap`) allows direct access to elements, and the doubly linked list (`cache`) maintains the order.

5. **Space Complexity:**
   - The space complexity is O(N), where N is the capacity of the cache.
   - The doubly linked list and hashmap both contribute to the space usage.
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