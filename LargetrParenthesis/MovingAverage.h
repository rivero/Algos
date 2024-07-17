#pragma once
/*
* https://leetcode.com/problems/moving-average-from-data-stream/description/

346. Moving Average From Data Stream

Given a stream of integers and a window size, calculate the moving average of
all integers in the sliding window.

Implement the MovingAverage class:

MovingAverage(int size) Initializes the object with the size of the window size.
double next(int val) Returns the moving average of the last size values of the stream.


Example 1:

Input
["MovingAverage", "next", "next", "next", "next"]
[[3], [1], [10], [3], [5]]
Output
[null, 1.0, 5.5, 4.66667, 6.0]

Explanation
MovingAverage movingAverage = new MovingAverage(3);
movingAverage.next(1); // return 1.0 = 1 / 1
movingAverage.next(10); // return 5.5 = (1 + 10) / 2
movingAverage.next(3); // return 4.66667 = (1 + 10 + 3) / 3
movingAverage.next(5); // return 6.0 = (10 + 3 + 5) / 3


Constraints:

1 <= size <= 1000
-105 <= val <= 105
At most 104 calls will be made to next.

Time Complexity: O(1) (constant time)
Space Complexity: O(W) (linear with respect to the window size)"

*/
struct MovingAverage : public timeit
{
	queue<int> m_numbers;
	size_t m_windowSize{};
	double m_sum{};
	MovingAverage(int size) : m_windowSize(size)
	{
	}

	double next(int val)
	{
		if (m_numbers.size() + 1 > m_windowSize) // If the queue size is greater than or equal to the window size...  
		{
			// ...it removes the oldest element from the queue (constant time operation) then it 
			m_sum -= m_numbers.front(); //updates the sum by subtracting the removed value...
			m_numbers.pop();
		}
		m_numbers.push(val); //...and adding the new value (constant time operation)
		m_sum += val; // Finally, it computes the average by dividing the sum by the queue size (constant time operation).

		return m_sum / m_numbers.size();
	}
};
