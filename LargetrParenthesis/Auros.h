#pragma once
namespace Auros
{
	int rotateRight(int arrLength, int curIndex, int spaces)
	{
		return (curIndex + spaces) % arrLength;
	}
	int rotateLeft(int arrLength, int curIndex, int spaces)
	{
		auto x = abs(spaces) % arrLength;
		if (curIndex - x < 0)
		{
			auto dif = abs(curIndex - x);
			return arrLength - dif;
		}
		return curIndex - x;
	}
	void testRight(int v[], size_t s)
	{
		auto currIndex = 0;
		auto spaces = 1;
		int index = rotateRight(s, currIndex, spaces);
		cout << " cur value " << v[currIndex] << " after rotating right - spaces: "
			<< spaces << " value at index " << index << ": " << v[index] << "\n";

		auto n{ 12 };
		cout << " Rotating " << n << " times:\n";
		while (n-- > 0)
		{
			currIndex = index;
			index = rotateRight(s, currIndex, spaces);
			cout << "curr index: [" << currIndex << "] value: " << v[currIndex] << "\tnew index ["
				<< index << "] value: " << v[index] << "\n";

		}
		n = 12;
		currIndex = 0;
		cout << "From: " << currIndex << " RIGHT Rotating " << n << " spaces:\n";
		index = rotateRight(s, currIndex, n);
		cout << "curr index: [" << currIndex << "] value: " << v[currIndex] << "\tnew index ["
			<< index << "] value: " << v[index] << "\n";

	}
	void testLeft(int v[], size_t s)
	{
		size_t currIndex = 0;
		auto spaces = 1;
		size_t index{ 0 };
		index = rotateLeft(s, currIndex, spaces);
		cout << " cur value " << v[currIndex] << " after rotating left - spaces: "
			<< spaces << " value at index " << index << ": " << v[index] << "\n";

		int n{ 15 };
		cout << " Rotating " << n << " times:\n";
		while (n-- > 0)
		{
			currIndex = index;
			index = rotateLeft(s, currIndex, spaces);
			cout << "curr index: [" << currIndex << "] value: " << v[currIndex] << "\tnew index ["
				<< index << "] value: " << v[index] << "\n";

		}

		n = 10;
		int max = 3;
		currIndex = s / 2;
		while (max-- > 0)
		{
			cout << "From: " << currIndex << " LEFT Rotating " << n << " spaces:\n";
			index = rotateLeft(s, currIndex, n);
			cout << "curr index: [" << currIndex << "] value: " << v[currIndex] << "\tnew index ["
				<< index << "] value: " << v[index] << "\n";
			n += max;
			currIndex++;
		}
	}

	void test()
	{
		int v[] = { 7, 8, 9, 10, 11 };
		auto sizeV = sizeof(v) / sizeof(v[0]);
		printv(v);
		//testRight(v, sizeV);
		testLeft(v, sizeV);

	}

	/*

Array Challenge

Have the function ArrayChallenge(arr) take the array of numbers stored in arr and
first determine the largest element in the array,
and then determine whether or not you can reach that same element within the
array by moving left or right continuously according
to whatever integer is in the current spot.

If you can reach the same spot within the array, then your program should output
the least amount of jumps it took.

For example: if the input is [2, 3, 5, 6, 1] you'll start at the spot where 6 is
and if you jump 6 spaces to the right
while looping around the array you end up at the last element where the 1 is.
Then from here you jump 1 space to the left and you're back where you started,
so your program should output 2.

If it's impossible to end up back at the largest element in the array your program should output -1.
The largest element in the array will never equal the number of elements in the array.

The largest element will be unique.

Examples
Input: {1,2,3,4,2}
Output: 3

Input: {1,7,1,1,1,1}
Output: 2

[2, 3, 5, 6, 1]

LArgest = 6
move 6 to the right: 1, 2, 3, 5, 6, 1

found 1

Move 1 to the right: found 2
move 2 to the right: 3, 5
found 5

move 5 to thje right
6 1 2 3 4 found 4


*/


	int ArrayChallenge(int arr[], int arrLength)
	{
		int largest = -1;
		int idx{};
		for (int i = 0; i < arrLength; i++)
		{
			if (largest < arr[i])
			{
				largest = arr[i];
				idx = i;
			}
		}

		auto loops = arrLength;
		int c{};
		int val{};
		val = largest;
		cout << "largest: " << val << " index [" << idx << "]\n";
		while (loops-- > 0)
		{
			c++;
			auto indexRight = rotateRight(arrLength, idx, val);
			cout << c << ") From index " << idx << " rotate right " << val << " times: index[" << indexRight << "] value: " << arr[indexRight] << "\n";
			if (arr[indexRight] == largest)
				break;
			val = arr[indexRight];

			auto indexLeft = rotateLeft(arrLength, indexRight, val);
			cout << c << ") From index " << indexRight << " rotate left " << val << " times: index [" << indexLeft << "] value: " << arr[indexLeft] << "\n";
			if (arr[indexLeft] == largest)
				break;
			idx = indexLeft;
			val = arr[indexLeft];

		}
		return c;

	}


}
