#pragma once
namespace randompickweight
{
/*
	* 528. Random Pick with Weight
Medium

You are given a 0-indexed array of positive integers w where w[i] describes the weight of the ith index.

You need to implement the function pickIndex(), which randomly picks an index in the range [0, w.length - 1]
(inclusive) and returns it. The probability of picking an index i is w[i] / sum(w).

For example, if w = [1, 3], the probability of picking index 
0 is 
1 / (1 + 3) = 0.25 
(i.e., 25%)

, and the 
probability of picking index 
1 is 
3 / (1 + 3) = 0.75 (i.e., 75%).


Example 1:

Input
["Solution","pickIndex"]
[[[1]],[]]
Output
[null,0]

Explanation
Solution solution = new Solution([1]);
solution.pickIndex(); // return 0. The only option is to return 0 since there is only one element in w.
Example 2:

Input
["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]
[[[1,3]],[],[],[],[],[]]
Output
[null,1,1,1,1,0]

Explanation
Solution solution = new Solution([1, 3]);
solution.pickIndex(); // return 1. It is returning the second element (index = 1) that has a probability of 3/4.
solution.pickIndex(); // return 1
solution.pickIndex(); // return 1
solution.pickIndex(); // return 1
solution.pickIndex(); // return 0. It is returning the first element (index = 0) that has a probability of 1/4.

Since this is a randomization problem, multiple answers are allowed.
All of the following outputs can be considered correct:
[null,1,1,1,1,0]
[null,1,1,1,1,1]
[null,1,1,1,0,0]
[null,1,1,1,0,1]
[null,1,0,1,0,0]
......
and so on.


Constraints:

1 <= w.length <= 104
1 <= w[i] <= 105
pickIndex will be called at most 104 times.


For [1,3,4,6] the probablity of choosing index 0 is 1/14, 1 is 3/14, 2 is 4/14 and 3 is 6/14.
Using Prefix sum I have converted the weight vector into a 

vector v:- [1,1+3, 1+3+4, 1+3+4+6].
= [1, 4, 8 , 14]


In case of random numbers from [0,14), 
if the number is 0 then I return index 0, (1) 
if number lies between [1-4) I return index 1, (4) 
if number lies between [4-8) I return index 2  (8)
and if it lies in [8,14) I return index 3. (14)

So, basically I'm returning the index of the upperbound of the random generated number from vector v.

	*/


	class Solution 
	{
	public:
		vector<int> v;
		Solution(vector<int> w) 
		{
			v.push_back(w[0]);

			for (int i = 1; i < w.size(); i++) 
			{
				v.push_back(v[i - 1] + w[i]);
			}
			printv(v);
		}

		int pickIndex() 
		{
			int n = rand() % v[v.size() - 1];
			auto it = upper_bound(v.begin(), v.end(), n);
			cout << "n " << n << " *it (upper bound) " << *it;
			cout << " distance " << distance(v.begin(), it) << "\n";
			return distance(v.begin(), it);
		}
	};


	void process()
	{
		
		// Your Solution object will be instantiated and called as such:
		// ["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]
		Solution* obj = new Solution({1, 3});

		for (int i = 0; i < 5;i++)
		{
			cout << obj->pickIndex() << "\n";
		}
 
	}
}