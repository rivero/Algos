#pragma once
struct Solution
{

	struct Something
	{
		void operator()(int x)
		{
			cout << x << "\n";
		}
	};
	void lambda_expression()
	{
		// [cc](p){fd}
		// cc = capture clause
		// p = parameters
		// fd = function definition
		int d = 3;
		vector<int> v{ 2, 3, 7, 14, 23 };
		Something something;
		for_each(v.begin(), v.end(), something);
		for_each(v.begin(), v.end(), [&](int x) { cout << "lambda " << x * d << "\n"; d += 1; });
	}

};
