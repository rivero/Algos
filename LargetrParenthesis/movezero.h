#pragma once
namespace movezero
{
	// Solution 1
	// using pointer move left pointer forward . 
	// if a zero is detected at the left swap it with the right element.
	// the number of zeroes whould be returned
	template <typename T>
	size_t move_zeroes(T& c) // Collection
	{
		size_t l{};
		auto r{ c.size() - 1 };
		size_t counter{};

		while (l < r)
		{
			if (c[l] == 0)
			{
				if (c[r] != 0)
				{
					swap(c[l++], c[r--]);
					counter++;
				}
			}
			else
				l++;

			if (l < r && c[r] != 0)
			{
				if (c[l] == 0)
				{
					swap(c[l++], c[r--]);
					counter++;
				}
			}
			else
				r--;
		}
		return counter;
	}

}
