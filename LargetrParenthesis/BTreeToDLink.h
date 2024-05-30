#pragma once
namespace BTreeToDLink
{
    /*
    * 
	* 
    426. Convert Binary Search Tree to Sorted Doubly Linked List
	
    Convert a Binary Search Tree to a sorted Circular Doubly-Linked List in place.

    You can think of the left and right pointers as synonymous to the predecessor 
    and successor pointers in a doubly-linked list. 
    
    For a circular doubly linked list, the predecessor of the first element is the last element, 
    and the successor of the last element is the first element.

    We want to do the transformation in place. 
    
    After the transformation, 
    the left pointer of the tree node should point to its predecessor, 
    and the right pointer should point to its successor. 
    
    You should return the pointer to the smallest element of the linked list.

    Example 1:

                4
               / \
              2   5
             / \
            1   3

    Input: root = [4,2,5,1,3]
    Output: [1,2,3,4,5]
    Explanation: The figure below shows the transformed BST. 
    The solid line indicates the successor relationship, 
    while the dashed line means the predecessor relationship.

        ->1<->2<->3<->4<->5<-
        |-------------------|

    Example 2:

    Input: root = [2,1,3]
    Output: [1,2,3]


    Constraints:

    The number of nodes in the tree is in the range [0, 2000].
    -1000 <= Node.val <= 1000
    All the values of the tree are unique.

    */

	struct Node 
    {
	public:
        int val{};
        Node* left{ nullptr };
        Node* right{ nullptr };

		Node() {}

		Node(int _val) : val(_val)
        {
		}

		Node(int _val, Node* _left, Node* _right) 
        {
			val = _val;
			left = _left;
			right = _right;
		}
	};
    class Solution 
    {
		using valnod = pair<int, Node*>;
		set<valnod> m_set;
        void process(Node* node)
        {
            if (!node)
            {
                return;
            }
            m_set.insert({node->val, node});
            process(node->left);
            process(node->right);
        }
    public:
		void print_preorder(Node* node)
		{
			if (!node)
			{
				return;
			}
			static int counter{};
			if (++counter > m_set.size())
			{
				return;
			}
			cout << "val [" << node->val << "]\n";
			print_preorder(node->right);
		}
        Node* treeToDoublyList(Node* root)
        {
            // Create set of pairs (value, Node* ) 
            // the set will be sorted based on pair 
            // We recursively iterate and insert values to set.
            // at the end we iterate the set and point the Nodes accordingly
            m_set.clear();
            process(root);

            if (m_set.size() == 0)
            {
                return {};
            }
			
            //print();
			
            auto curIt = m_set.begin();
			auto nextit = m_set.begin();
            nextit++;
            while (nextit != m_set.end())
            {
                curIt->second->right = nextit->second;
                nextit->second->left = curIt->second;
                curIt++;
                nextit++;
            }
            curIt = m_set.begin();
            nextit = --m_set.end();
            curIt->second->left = nextit->second;
            nextit->second->right = curIt->second;
            root = curIt->second;
            return root;

        }

        void print()
        {
            for (auto [val, node] : m_set)
            {
                cout << "val: " << val << " node " << node << "\n";

            }
        }

    };
	void process()
	{
        auto root = new Node(4);
        root->left = new Node(2);
        root->right = new Node(5);
		root->left->left = new Node(1);
		root->left->right = new Node(3);
        Solution sol;
        root = sol.treeToDoublyList(root);
        sol.print_preorder(root);

        root = sol.treeToDoublyList(nullptr);
	}
}