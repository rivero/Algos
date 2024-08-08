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

## Algorithm Explanation

This code implements an LRU (Least Recently Used) cache. It uses a combination of a `list` and an `unordered_map` to efficiently 
store and retrieve key-value pairs.

* **`list` (keyValList):** Stores key-value pairs as a doubly linked list. This allows for efficient insertion and removal of 
elements at both ends.
* **`unordered_map` (keyItMap):** Maps keys to their corresponding iterators in the `list`. This enables quick lookup of elements 
in the list.

**Key operations:**

* **`pushFront(k, v)`:** Adds a key-value pair to the front of the list and updates the corresponding iterator in the map.
* **`moveToFront(k, v)`:** Moves an existing key-value pair to the front of the list, updating its iterator in the map.
* **`checkCapacity()`:** Removes the least recently used element (the back of the list) if the cache is full.

**`get(k)`:**
* Checks if the key exists in the `unordered_map`.
* If found, moves the corresponding key-value pair to the front of the list and returns the value.
* If not found, returns -1.

**`put(k, v)`:**
* Checks if the key exists in the `unordered_map`.
* If found, updates the value and moves the key-value pair to the front of the list.
* If not found, adds the key-value pair to the front of the list and checks if the cache capacity is exceeded.

## Time and Space Complexity

* **`get(k)`:** O(1) on average. The `unordered_map` lookup takes constant time, and moving an element in the list is also constant 
time.
* **`put(k, v)`:** O(1) on average. Similar to `get(k)`, operations on the `unordered_map` and list are constant time.
* **Space Complexity:** O(capacity) due to the `unordered_map` and the `list` storing at most `capacity` elements.
* 
* LIST
* 
* Insertion/Deletion at the beginning or end: O(1)
Insertion/Deletion at any position: O(n)
Access to the front or back element: O(1)
Access to an arbitrary element: O(n)
Search for an element: O(n)
Sorting: O(n log n) (using standard sorting algorithms)

*/
namespace LRUCache
{

    class LRUCache
    {
        int cap{};
        list< pair<int, int> > kvList;
        unordered_map<int, list< pair<int, int> >::iterator > kvMap;
        void pushFront(int k, int v)
        {
            kvList.push_front({ k,v });
            kvMap[k] = kvList.begin();
            checkCapacity();
        }
        void moveFront(int k, int v)
        {
            auto it = kvMap[k];
            kvList.erase(it);
            pushFront(k, v);
        }
        void checkCapacity()
        {
            if (kvMap.size() > cap)
            {
                auto [k, v] = kvList.back();
                kvMap.erase(k);
                kvList.pop_back();
            }
        }
    public:
        LRUCache(int capacity) : cap(capacity) {}

        int get(int k)
        {
            if (kvMap.count(k) > 0)
            {
                auto it = kvMap[k];
                auto [k, v] = *it;
                moveFront(k, v);
                return v;
            }
            return -1;
        }

        void put(int k, int v)
        {
            if (kvMap.count(k) > 0)
                moveFront(k, v);
            else
                pushFront(k, v);
        }
    };

    /**
     * Your LRUCache object will be instantiated and called as such:
     * LRUCache* obj = new LRUCache(capacity);
     * int param_1 = obj->get(key);
     * obj->put(key,value);
     */
    /**
     * Your LRUCache object will be instantiated and called as such:
     * LRUCache* obj = new LRUCache(capacity);
     * int param_1 = obj->get(key);
     * obj->put(key,value);
     */
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