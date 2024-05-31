// LargetrParenthesis.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <assert.h>
#include <cstdlib>
#include <ctime>
#include <unordered_map>
#include <map>
#include <utility>
#include <chrono>
#include <iomanip>
#include <set>
#include <unordered_set>
#include <stack>
#include <array>
#include <cctype>
using namespace std;

template <typename T>
void printv(const T& v, bool newLine = true, bool printIndex = false)
{
	for (const auto& elem : v)
	{
		cout << elem << "\t";
	}
	if (printIndex)
	{
		cout << "\n";
		size_t c{};
		for (const auto& elem : v)
		{
			cout << "[" << c++ << "]\t";
		}
	}

	if (newLine)
	{
		cout << "\n";
	}
}

template <typename T>
void printm(const map<T, T>& counts)
{
	for (auto elem : counts)
	{
		cout << elem.first << " = " << elem.second << "\n";
	}
	cout << "\n";
}

template <typename T, typename U>
void printm(const map<T, U>& counts)
{
	for (auto elem : counts)
	{
		cout << elem.first << " = " << elem.second << "\n";
	}
	cout << "\n";
}

#include "timeit.h"
#include "BinarySearch.h"
#include "Solution.h"
#include "ReverseLinkedList.h"
#include "LenghtOfLastWord.h"
#include "ValidAnagram.h"
#include "PalindromeNumber.h"
#include "ValidWordAbbreviation.h"
#include "ValidPalindrome.h"
#include "MovingAverage.h"
#include "BinaryTreeDiameter.h"
#include "Toeplitz.h"
#include "MinRemoveValidParenthesis.h"
#include "BinaryTreeVerticalOrderTransversal.h"
#include "NestedListWeightSum.h"
#include "LowestCommon.h"
#include "MinWindowSubstring.h"
#include "QuestionMarks.h"
#include "Auros.h"
#include "TopKElements.h"
#include "FindParenthesis.h"
#include "mergearrays.h"
#include "movezero.h"
#include "sumtreenodes.h"
#include "arrayStringsAreEqual.h"
#include "findinter.h"
#include "SparseVector.h"
#include "RandomPickWithWeight.h"
#include "BasicCalculator.h"
#include "BuildingsWithAnOceanView.h"
#include "KthLargestElement.h"
#include "SimplifyPath.h"
#include "BTreeToDLink.h"
#include "NumberOfIslands.h"
#include "MinimumAddParenthesisValid.h"
#include "LowestCommonAncestorBT.h"
#include "RecursiveRabbitInterview.h"
#include "LongestIncreasingSubsequenceNLogN.h"
#include "IncreasingTripleSequence.h"

struct tests
{
	string m_tests;
	tests(const string& str) : m_tests(str) {}
	bool contains(const string& tst)
	{
		return string::npos != m_tests.find(tst);
	}

};

int main()
{
	tests t("IncreasingTripleSequence");
#pragma region Tests
	if (t.contains("FindParenthesis"))
	{
		par::test();
	}
	if (t.contains("move_zeroes"))
	{
		cout << "move_zeroes\n";
		{
			vector<int> vec{ 2, 0, 3, 0, 4, 5, 0 };
			printv(vec);
			cout << movezero::move_zeroes(vec) << "\n";
			printv(vec);
			cout << "\n";
		}
		{
			vector<int> vec{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 };
			printv(vec);
			cout << movezero::move_zeroes(vec) << "\n";
			printv(vec);
			cout << "\n";
		}
		{
			vector<int> vec{ 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 };
			printv(vec);
			cout << movezero::move_zeroes(vec) << "\n";
			printv(vec);
			cout << "\n";
		}
		{
			vector<int> vec{ 0, 1, 0, 1, 0, 1, 0 };
			printv(vec);
			cout << movezero::move_zeroes(vec) << "\n";
			printv(vec);
			cout << "\n";
		}
		{
			vector<int> vec{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
			printv(vec);
			cout << movezero::move_zeroes(vec) << "\n";
			printv(vec);
			cout << "\n";
		}
		{
			vector<int> vec{ 0, 1, 2, 0, 0, 3,4 };
			printv(vec);
			cout << movezero::move_zeroes(vec) << "\n";
			printv(vec);
			cout << "\n";
		}
		{
			vector<int> vec{ 0, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,4 };
			printv(vec);
			cout << movezero::move_zeroes(vec) << "\n";
			printv(vec);
			cout << "\n";
		}
	}
	if (false)
	{
		Solution sol;

		sol.lambda_expression();
	}
	if (false)
	{
		{
			vector<int> vec{ 1,1,1,2,2,3, 7, 7, 7 };
			topk::TopKElements(vec);

		}
		{
			vector<int> vec{ 1,1,2,2,3,3 };
			topk::TopKElements(vec, 3);

		}
	}
	if (false)
	{
		vector<int> nums1{ 1,2,3,0,0,0 };
		vector<int> nums2{ 2,5,6 };

		mergearrays::merge(nums1, 3, nums2, 3);
		printv(nums1);
	}
	if (false)
	{
		cout << sumtreenodes::doRangeSumBST();
	}
	if (false)
	{
		vector<string> v1{ "ab", "c" }, v2{ "a", "bc" };
		cout << (arraystringsequal::arrayStringsAreEqual(v1, v2) ? " True" : "false");
	}
	if (false)
	{
		timeit t;
		vector<int> v1{ 4,3,2,3,1 }, v2{ 2,2,5,2,3,6 };
		auto res = findinter::findIntersectionValues(v1, v2);
		printv(res);
	}
	if (false)
	{
		auto head = new ReverseLinkedList::ListNode(1);
		head->next = new ReverseLinkedList::ListNode(2);
		head->next->next = new ReverseLinkedList::ListNode(3);
		head->next->next->next = new ReverseLinkedList::ListNode(4);
		head->next->next->next->next = new ReverseLinkedList::ListNode(5);
		ReverseLinkedList r;
		r.printList(head);
		cout << "\n";
		auto newHead = r.reverseList(head);
		r.printList(newHead);
		cout << "\n";
	}
	if (false)
	{
		LenghtOfLastWord l;
		auto val = l.lengthOfLastWord("   fly me   to   the moon  ");
		assert(val == 4);
		cout <<  val <<  "\n";
		val = l.lengthOfLastWord("Hello World");
		assert(val == 5);
		cout << val << "\n";
		val = l.lengthOfLastWord("luffy is still joyboy");
		assert(val == 6);
		cout << val << "\n";
	}
	if (false)
	{
		ValidAnagram v;
		auto val = v.isAnagram("anagram","nagaram");
		assert(val);
		val = v.isAnagram("rat", "car");
		assert(!val);
	}
	if (false)
	{
		PalindromeNumber p;
		auto val = p.isPalindrome(121);
		assert(val);
		val = p.isPalindrome(-121);
		assert(!val);
		val = p.isPalindrome(10);
		assert(!val);
		val = p.isPalindrome(1234567899);
		assert(!val);
		
	}
	if (false)
	{
		ValidWordAbbreviation v;
		auto val = v.validWordAbbreviation("substitution", "s10n");
		cout << "substitution : s10n : valid " << val << "\n";
		assert(val);

		val = v.validWordAbbreviation("substitution", "sub4u4");
		cout << "substitution : sub4u4 : valid " << val << "\n";
		assert(val);

		val = v.validWordAbbreviation("substitution", "12");
		cout << "substitution : 12 : valid " << val << "\n";
		assert(val);

		val = v.validWordAbbreviation("substitution", "su3i1u2on");
		cout << "substitution : su3i1u2on : valid " << val << "\n";
		assert(val);

		val = v.validWordAbbreviation("substitution", "s55n");
		cout << "substitution : s55n : valid " << val << "\n";
		assert(!val);

		val = v.validWordAbbreviation("substitution", "s010n");
		cout << "substitution : s010n : valid " << val << "\n";
		assert(!val);

		val = v.validWordAbbreviation("substitution", "s0ubstitution");
		cout << "substitution : s0ubstitution : valid " << val << "\n";
		assert(!val);

		val = v.validWordAbbreviation("word", "3e");
		cout << "word : 3e : valid " << val << "\n";
		assert(!val);
	}
	if (false)
	{
		ValidPalindrome v;
		auto val = v.validPalindrome("aba");
		cout << " Valid palindrome (1 char removed) [aba]: " << val << "\n";
		assert(val);
	
		val = v.validPalindrome("abac");
		cout << " Valid palindrome (1 char removed) [abac]: " << val << "\n";
		assert(val);

		val = v.validPalindrome("medem");
		cout << " Valid palindrome (1 char removed) [medem]: " << val << "\n";
		assert(val);

		val = v.validPalindrome("medecm");
		cout << " Valid palindrome (1 char removed) [medecm]: " << val << "\n";
		assert(val);

		string tst = "mecdecm";
		val = v.validPalindrome(tst);
		cout << " Valid palindrome (1 char removed) [" << tst << "]: " << val << "\n";
		assert(!val);
	
		tst = "mecdcem";
		val = v.validPalindrome(tst);
		cout << " Valid palindrome (1 char removed) [" << tst << "]: " << val << "\n";
		assert(val);

		tst = "mecdcfm";
		val = v.validPalindrome(tst);
		cout << " Valid palindrome (1 char removed) [" << tst << "]: " << val << "\n";
		assert(!val);

		tst = "abc";
		val = v.validPalindrome(tst);
		cout << " Valid palindrome (1 char removed) [" << tst << "]: " << val << "\n";
		assert(!val);
	}
	if (false)
	{
		MovingAverage movingAverage(3);
		cout << fixed << setprecision(12) <<movingAverage.next(1) << "\n"; // return 1.0 = 1 / 1
		cout << fixed << setprecision(12) <<movingAverage.next(10)<< "\n"; // return 5.5 = (1 + 10) / 2
		cout << fixed << setprecision(12) <<movingAverage.next(3) << "\n"; // return 4.66667 = (1 + 10 + 3) / 3
		cout << fixed << setprecision(12) <<movingAverage.next(5) << "\n"; // return 6.0 = (10 + 3 + 5) / 3
	}
	if (false)
	{
		{
			BinayTreeDiameter b;
			auto root = new BinayTreeDiameter::TreeNode(1);
			root->left = new BinayTreeDiameter::TreeNode(2);
			root->right = new BinayTreeDiameter::TreeNode(3);
			root->left->left = new BinayTreeDiameter::TreeNode(4);
			root->left->right = new BinayTreeDiameter::TreeNode(5);
			int val = b.diameterOfBinaryTree(root);
			assert(val == 3);
			cout << "result: " <<val << "\n";

		}
		{
			BinayTreeDiameter b;
			auto root = new BinayTreeDiameter::TreeNode(1);
			root->left = new BinayTreeDiameter::TreeNode(2);
			int val = b.diameterOfBinaryTree(root);
			assert(val == 1);
			cout << "result: " << val << "\n";

		}
	}
	if (false)
	{
		{
			Toeplitz t;
			vector<vector<int>> matrix
			{
				{1, 2, 3, 4},
				{5, 1, 2, 3},
				{9, 5, 1, 2}
			};
			for (auto elem: matrix)
			{
				printv(elem);
			}
			bool val = t.isToeplitzMatrix(matrix);
			cout << " this matrix  " << (val ? "is" : "is not") << " a Toeplitz matrix\n";
		}
		{
			Toeplitz t;
			vector<vector<int>> matrix
			{
				{1, 2, 3},
				{5, 1, 2},
				{9, 5, 1}
			};
			for (auto elem : matrix)
			{
				printv(elem);
			}
			bool val = t.isToeplitzMatrix(matrix);
			cout << " this matrix  " << (val ? "is" : "is not") << " a Toeplitz matrix\n";
		}
		{
			Toeplitz t;
			vector<vector<int>> matrix
			{
				{1, 2},
				{5, 1},
				{9, 5}
			};
			for (auto elem : matrix)
			{
				printv(elem);
			}
			bool val = t.isToeplitzMatrix(matrix);
			cout << " this matrix  " << (val ? "is" : "is not") << " a Toeplitz matrix\n";
		}
		{
			Toeplitz t;
			vector<vector<int>> matrix
			{
				{1, 2},
				{5, 1}
			};
			for (auto elem : matrix)
			{
				printv(elem);
			}
			bool val = t.isToeplitzMatrix(matrix);
			cout << " this matrix  " << (val ? "is" : "is not") << " a Toeplitz matrix\n";
		}
		{
			Toeplitz t;
			vector<vector<int>> matrix
			{
				{1, 2},
				{2, 2}
			};
			for (auto elem : matrix)
			{
				printv(elem);
			}
			bool val = t.isToeplitzMatrix(matrix);
			cout << " this matrix  " << (val ? "is" : "is not") << " a Toeplitz matrix\n";
		}
	}
	if (false)
	{
		{
			MinRemoveValidParenthesis v;
			cout << v.minRemoveToMakeValid("lee(t(c)o)de)") << "\n";

		}
		{
			MinRemoveValidParenthesis v;
			cout << v.minRemoveToMakeValid("a)b(c)d") << "\n";

		}
		{
			MinRemoveValidParenthesis v;
			cout << v.minRemoveToMakeValid("))((") << "\n";

		}
	}
	if (false)
	{
		if(false)
		{
			auto root = new BinaryTreeVerticalOrderTransversal::TreeNode(3);

			root->left = new BinaryTreeVerticalOrderTransversal::TreeNode(9);
			root->right = new BinaryTreeVerticalOrderTransversal::TreeNode(20);

			root->right->left = new BinaryTreeVerticalOrderTransversal::TreeNode(15);
			root->right->right = new BinaryTreeVerticalOrderTransversal::TreeNode(7);

			BinaryTreeVerticalOrderTransversal b;
			auto res = b.verticalOrder(root);

			for (auto elem : res)
			{
				cout << "[";
				printv(elem, false);
				cout << "],";
			}
			cout << "\n";

		}
		if (false)
		{
			auto root = new BinaryTreeVerticalOrderTransversal::TreeNode(3);

			root->left = new BinaryTreeVerticalOrderTransversal::TreeNode(9);
			root->right = new BinaryTreeVerticalOrderTransversal::TreeNode(8);

			root->left->left = new BinaryTreeVerticalOrderTransversal::TreeNode(4);
			root->left->right = new BinaryTreeVerticalOrderTransversal::TreeNode(0);

			root->right->left = new BinaryTreeVerticalOrderTransversal::TreeNode(1);
			root->right->right = new BinaryTreeVerticalOrderTransversal::TreeNode(7);

			BinaryTreeVerticalOrderTransversal b;
			auto res = b.verticalOrder(root);

			for (auto elem : res)
			{
				cout << "[";
				printv(elem, false);
				cout << "],";
			}
			cout << "\n";

		}
		if (false)
		{
			auto root = new BinaryTreeVerticalOrderTransversal::TreeNode(3);

			root->left = new BinaryTreeVerticalOrderTransversal::TreeNode(9);
			root->right = new BinaryTreeVerticalOrderTransversal::TreeNode(8);

			root->left->left = new BinaryTreeVerticalOrderTransversal::TreeNode(4);
			root->left->right = new BinaryTreeVerticalOrderTransversal::TreeNode(0);

			root->right->left = new BinaryTreeVerticalOrderTransversal::TreeNode(1);
			root->right->right = new BinaryTreeVerticalOrderTransversal::TreeNode(7);

			root->left->right->left = new BinaryTreeVerticalOrderTransversal::TreeNode(5);
			root->left->right->right = new BinaryTreeVerticalOrderTransversal::TreeNode(2);

			BinaryTreeVerticalOrderTransversal b;
			auto res = b.verticalOrder(root);

			for (auto elem : res)
			{
				cout << "[";
				printv(elem, false);
				cout << "],";
			}
			cout << "\n";

		}
		if (true)
		{
			auto root = new BinaryTreeVerticalOrderTransversal::TreeNode(3);

			root->left = new BinaryTreeVerticalOrderTransversal::TreeNode(9);
			root->right = new BinaryTreeVerticalOrderTransversal::TreeNode(8);

			root->left->left = new BinaryTreeVerticalOrderTransversal::TreeNode(4);
			root->left->right = new BinaryTreeVerticalOrderTransversal::TreeNode(0);

			root->right->left = new BinaryTreeVerticalOrderTransversal::TreeNode(1);
			root->right->right = new BinaryTreeVerticalOrderTransversal::TreeNode(7);

			root->left->right->right = new BinaryTreeVerticalOrderTransversal::TreeNode(2);
			root->right->left->left = new BinaryTreeVerticalOrderTransversal::TreeNode(5);

			BinaryTreeVerticalOrderTransversal b;
			auto res = b.verticalOrder(root);

			for (auto elem : res)
			{
				cout << "[";
				printv(elem, false);
				cout << "],";
			}
			cout << "\n";

			//res = b.verticalOrder2(root);

			//for (auto elem : res)
			//{
			//	cout << "[";
			//	printv(elem, false);
			//	cout << "],";
			//}
			//cout << "\n";
		}
	}

	if (false)
	{
		NestedInteger n1(1);

		NestedListWeightSum n;
		 
	}
	if (false)
	{
		minWindowSubstring::process();
	}
	if (false)
		Auros::test();
	if (false)
	{
		vector<int> vec{ 1, 2, 3, 4, 2 };
		cout << "\n\nChallenge:\n";
		printv(vec);
		//Output: 3
		cout << Auros::ArrayChallenge(&vec[0], vec.size());

		//		Input : {1, 7, 1, 1, 1, 1}
		//Output: 2

		//	[2, 3, 5, 6, 1]

		//LArgest = 6
		//	move 6 to the right : 1, 2, 3, 5, 6, 1

		//	found 1
	}

	if (false)
	{
		cout << "\nConstructing\t";
		auto root = createInts();

		DeptFirst<int> d;
		// Function call
		cout << "\nPreorder traversal of binary tree is\t";
		d.printPreOrder(root);

		cout << "\nInorder traversal of binary tree is\t";
		d.printInorder(root);

		cout << "\nPostorder traversal of binary tree is\t";
		d.printPostOrder(root);

		cout << "\nDestructing\t";
		Node<int>::DeleteTree(root);
		delete root;
	}
	if (false)
	{
		cout << "\nConstructing char\t";
		auto root = createChars();

		DeptFirst<char> d;
		// Function call
		cout << "\nPreorder traversal of binary tree is\t";
		d.printPreOrder(root);

		cout << "\nInorder traversal of binary tree is\t";
		d.printInorder(root);

		cout << "\nPostorder traversal of binary tree is\t";
		d.printPostOrder(root);

		cout << "\nDestructing\t";
		Node<char>::DeleteTree(root);
		delete root;
		cout << endl;
	}
	if (false)
	{
		cout << "\nConstructing char\t";
		auto root = createChars();

		BreadthFirst<char> b;
		cout << "\nPrinting\t";
		b.printLevel(root);

		cout << "\nDestructing\t";
		Node<char>::DeleteTree(root);
		delete root;
		cout << endl;
	}

	if (false)
	{
		cout << "\nConstructing BTVOT\t";
		auto root = createCharsBTVOT();

		BreadthFirst<int> b;
		cout << "\nPrinting\t";
		b.printLevel(root);

		cout << "\nDestructing\t";
		Node<int>::DeleteTree(root);
		delete root;
		cout << endl;
	}
	if (false)
	{
		Nooby n;
		n.know_algos();
		n.struct_bindings();
	}
	if (t.contains("LowestCommon"))
	{
		LowestCommon::process();
	}
	if (t.contains("SparseVector"))
	{
		sparsevec::process();
	}
	if (t.contains("randompickweight"))
	{
		randompickweight::process();
	}
	if (t.contains("BasicCalculator"))
	{
		basiccalc::process();
	}
	if (t.contains("buildingsoceanview"))
	{
		buildingsoceanview::process();
	}
	if (t.contains("KthLargestElement"))
	{
		KthLargestElement::process();
	}
	if (t.contains("SimplifyPath"))
	{
		SimplifyPath::process();
	}
	if (t.contains("BTreeToDLink"))
	{
		BTreeToDLink::process();
	}
	if (t.contains("NumberOfIslands"))
	{
		NumberOfIslands::process();
	}
	if (t.contains("MinimumAddParenthesisValid"))
	{
		MinimumAddParenthesisValid::process();
	}
	if (t.contains("LowestCommonAncestorBT"))
	{
		LowestCommonAncestorBT::process();
	}
	if (t.contains("RecursiveRabbitInterview"))
	{
		RecursiveRabbitInterview::process();
	}
	if (t.contains("LongestIncreasingSubsequenceNLogN"))
	{
		LongestIncreasingSubsequenceNLogN::process();
	}
#pragma endregion
	if (t.contains("IncreasingTripleSequence"))
	{
		IncreasingTripleSequence::process();
	}
}


//"the color re(d))()(()"
//
//"the color re)("
//
//"the color re(d))()(()" should be 0 no matching
//
//"(c(oder)) b(yte)" = 1
//
//"(coder)(byte))" = 0