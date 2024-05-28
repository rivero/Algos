#pragma once
namespace topk
{
	/*
	Given a non-empty array of integers, return the k most frequent elements

	Example 1:
	k = 2
	Input = [1,1,1,2,2,3]
	output [1, 2]

	Example 2
	k = 1
	Input = [1]
	output [1]

	if nums = [1,1,2,2,3,3] k cannot be 2 because there are not k unique numbers
	in this example, the only valid k is 3

	*/
	template <typename T>
	void TopKElements(T& c, size_t k = 2) //c = collection
	{
		cout << "\n\ninput vector (k [most frequent elements]= " << k << ")" << "\n";
		printv(c);

		cout << "\nCreating map to count occurrences: <elements, occurrences>" << "\n";
		map<int, int> counts;
		// O(n)
		for (auto const& elem : c)
		{
			counts[elem]++;
		}
		printm(counts);

		cout << "\nAdding the generated pairs to priority_queue< pair<int, int> >, "
			"note that the pairs are sorted by the priority_queue by <first>"
			", then <second>" << "\n";
		priority_queue < pair<int, int> > minHeap;
		// O(m)
		for (auto elem : counts)
		{
			auto key = elem.second;
			auto val = elem.first;
			auto curPair = std::make_pair(key, val);
			minHeap.push(curPair);
		}

		cout << "...priority queue looks like this: (note the sorted pairs) " << "\n";

		vector<int> res;
		for (; !minHeap.empty(); minHeap.pop())
		{
			auto p = minHeap.top();
			cout << p.first << " = " << p.second << "\n";
			if (res.size() < k)
			{
				cout << "adding to res vector: " << p.second << "\n";
				res.push_back(p.second);
			}
		}
		cout << "\nresult (Display the first k (" << k << ") elements" << "\n";
		printv(res);
	}

}
