#pragma once
/*
636. Exclusive Time of Functions

On a single-threaded CPU, we execute a program containing n functions. Each function has a unique ID between 0 and n-1.
Function calls are stored in a call stack: when a function call starts, its ID is pushed onto the stack, and when a 
function call ends, its ID is popped off the stack. The function whose ID is at the top of the stack is the current 
function being executed. Each time a function starts or ends, we write a log with the ID, whether it started or ended, 
and the timestamp.

You are given a list logs, where logs[i] represents the ith log message formatted as a string 
"{function_id}:{"start" | "end"}:{timestamp}". 
For example, "0:start:3" means a function call with function ID 0 started at the beginning of timestamp 3, and "1:end:2" 
means a function call with function ID 1 ended at the end of timestamp 2. Note that a function can be called multiple times, 
possibly recursively.

A function's exclusive time is the sum of execution times for all function calls in the program. For example, if a 
function is called twice, one call executing for 2 time units and another call executing for 1 time unit, the exclusive 
time is 2 + 1 = 3.

Return the exclusive time of each function in an array, where the value at the ith index represents the exclusive time 
for the function with ID i.



Example 1:


Input: n = 2, logs = ["0:start:0","1:start:2","1:end:5","0:end:6"]
Output: [3,4]
Explanation:
Function 0 starts at the beginning of time 0, then it executes 2 for units of time and reaches the end of time 1.
Function 1 starts at the beginning of time 2, executes for 4 units of time, and ends at the end of time 5.
Function 0 resumes execution at the beginning of time 6 and executes for 1 unit of time.
So function 0 spends 2 + 1 = 3 units of total time executing, and function 1 spends 4 units of total time executing.
Example 2:

Input: n = 1, logs = ["0:start:0","0:start:2","0:end:5","0:start:6","0:end:6","0:end:7"]
Output: [8]
Explanation:
Function 0 starts at the beginning of time 0, executes for 2 units of time, and recursively calls itself.
Function 0 (recursive call) starts at the beginning of time 2 and executes for 4 units of time.
Function 0 (initial call) resumes execution then immediately calls itself again.
Function 0 (2nd recursive call) starts at the beginning of time 6 and executes for 1 unit of time.
Function 0 (initial call) resumes execution at the beginning of time 7 and executes for 1 unit of time.
So function 0 spends 2 + 4 + 1 + 1 = 8 units of total time executing.
Example 3:

Input: n = 2, logs = ["0:start:0","0:start:2","0:end:5","1:start:6","1:end:6","0:end:7"]
Output: [7,1]
Explanation:
Function 0 starts at the beginning of time 0, executes for 2 units of time, and recursively calls itself.
Function 0 (recursive call) starts at the beginning of time 2 and executes for 4 units of time.
Function 0 (initial call) resumes execution then immediately calls function 1.
Function 1 starts at the beginning of time 6, executes 1 unit of time, and ends at the end of time 6.
Function 0 resumes execution at the beginning of time 6 and executes for 2 units of time.
So function 0 spends 2 + 4 + 1 = 7 units of total time executing, and function 1 spends 1 unit of total time executing.


Constraints:

1 <= n <= 100
1 <= logs.length <= 500
0 <= function_id < n
0 <= timestamp <= 10^9

No two start events will happen at the same timestamp.
No two end events will happen at the same timestamp.
Each function has an "end" log for each "start" log.
n =
2
logs =
["0:start:0","1:start:2","1:end:5","0:end:6"]
1
2
["0:start:0","1:start:2","1:end:5","0:end:6"]
1
["0:start:0","0:start:2","0:end:5","0:start:6","0:end:6","0:end:7"]
2
["0:start:0","0:start:2","0:end:5","1:start:6","1:end:6","0:end:7"]


Solution
1. **Function `strToVector`**:
   - This function splits a string into a vector of substrings using a specified separator.
   - The loop processes each character in the input string, so its time complexity is linear, **O(m)**, 
   where **m** is the length of the input string.

2. **Function `exclusiveTime`**:
   - This function calculates the exclusive execution times for a set of functions based on logs.
   - It uses a stack (`call_stack`) to keep track of function calls and a map (`execution_times`) to store execution times.
   - The loop iterates through each log entry, which takes **O(k)** time, where **k** is the number of logs.
   - Inside the loop:
	 - If the log entry is a "start" call, it updates the execution time for the top function on the stack.
	 This operation takes constant time, **O(1)**.
	 - If the log entry is an "end" call, it pops the top function from the stack and updates its execution time.
	 Again, this is a constant-time operation.
   - The final loop that constructs the result vector takes **O(n)** time, where **n** is the number of distinct functions.
   - Overall, the time complexity of `exclusiveTime` is **O(k + n)**.

3. **Summary**:
   - The overall time complexity of the entire `Solution` class depends on the number of logs (**k**) and the number 
   of distinct functions (**n**).
   - In most cases, the number of logs dominates, so we can simplify the time complexity to **O(k)**.

Remember that big O notation describes the worst-case complexity, and it helps us understand how an algorithm's 
performance scales with input size. In this case, the algorithm's performance primarily depends on the number of 
logs processed. 😊¹²³

Let me know if you need further clarification or have any other questions!

Source: Conversation with Copilot, 7/8/2024
(1) Big O Cheat Sheet – Time Complexity Chart - freeCodeCamp.org. https://www.freecodecamp.org/news/big-o-cheat-sheet-time-complexity-chart/.
(2) How can I find the time complexity of an algorithm?. https://stackoverflow.com/questions/11032015/how-can-i-find-the-time-complexity-of-an-algorithm.
(3) Understanding Time Complexity with Simple Examples. https://www.geeksforgeeks.org/understanding-time-complexity-simple-examples/.
(4) en.wikipedia.org. https://en.wikipedia.org/wiki/Time_complexity.
*/
namespace ExclusiveTimeOfFunctions
{
	class Solution 
	{
		vector<string> strToVector(const string& str, char sep = ':')
		{
			vector<string> res;
			/*
			The following split method was taken from https://www.javatpoint.com/how-to-split-strings-in-cpp
			Program3.cpp Please refer this for more details.
			*/
			string T; // temp string to hold split value.
			stringstream x(str);
			while (getline(x, T, sep))
			{
				res.push_back(T);
			}
			return res;
		}

	public:
		vector<int> exclusiveTime(int n, vector<string>& logs)
		{
			map<int, int> execution_times;
			stack<int> call_stack;
			int prev_start_time{};

			for (auto &log: logs)
			{
				auto v = strToVector(log);
				auto func_id = stoi(v[0]);
				auto call_type = v[1];
				auto timestamp = stoi(v[2]);

				if (call_type == "start")
				{
					if (call_stack.size() > 0)
					{
						execution_times[call_stack.top()] += timestamp - prev_start_time;
					}
					call_stack.push(func_id);
					prev_start_time = timestamp;
				}
				else
				{
					auto function_id = call_stack.top(); call_stack.pop();
					execution_times[function_id] += timestamp - prev_start_time + 1;
					prev_start_time = timestamp + 1;
				}
			}
			
			vector<int> res;
			for (auto & [function_id, times] : execution_times)
			{
				res.push_back(times);
			}
			return res;
		}
	};
	void process()
	{
		Solution sol;
		int n = 2;
		vector<string> logs = { "0:start:0", "1:start:2", "1:end:5", "0:end:6" };
		//Output : [3, 4]
		auto res = sol.exclusiveTime(n, logs);
		printv(res);
	}
}