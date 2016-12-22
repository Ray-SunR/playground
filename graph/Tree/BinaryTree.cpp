#include "BinaryTree.h"
#include <queue>
namespace src
{
	
	BinaryTree::BinaryTree()
		: m_root(NULL)
	{

	}

	void BinaryTree::LevelOrderTraversal(std::vector<int>& data)
	{
		std::queue<Node*> q;
		q.push(m_root);
		while (!q.empty())
		{
			Node* head = q.front();
			q.pop();
			if (!head) { continue; }
			data.push_back(head->m_data);
			q.push(head->m_left);
			q.push(head->m_right);
		}
	}

	const src::BinaryTree::Node* BinaryTree::LCA(const Node* a, const Node* b) const
	{
		return LCAHelper(m_root, a, b);
	}

	int BinaryTree::Height(const Node* root) const
	{
		if (!root) { return 0; }
		int ld = Height(root->m_left);
		int rd = Height(root->m_right);
		return 1 + (ld > rd ? ld : rd);
	}

	bool BinaryTree::IsBST() const
	{
		return IsBSTHelper(m_root);
	}

	const BinaryTree::Node* BinaryTree::LCAHelper(const Node* root, const Node* a, const Node* b) const
	{
		if (!root) { return NULL; }
		if (root == a || root == b) { return root; }
		const Node* l = LCAHelper(root->m_left, a, b);
		const Node* r = LCAHelper(root->m_right, a, b);
		return l && r ? root : (l ? l : r);
	}

	bool BinaryTree::IsBSTHelper(const Node* root) const
	{
		if (!root) { return true; }
		if (!root->m_left && !root->m_right) { return true; }
		if (root->m_left && root->m_left->m_data > root->m_data) { return false; }
		if (root->m_right && root->m_right->m_data < root->m_data) { return false; }
		return IsBSTHelper(root->m_left) && IsBSTHelper(root->m_right);
	}

	BinaryTree::Node*& BinaryTree::Root()
	{
		return m_root;
	}

	BinaryTree::~BinaryTree()
	{
		delete m_root;
	}

	BinaryTree::Node::Node(int data, Node* left, Node* right)
		: m_data(data)
		, m_left(left)
		, m_right(right)
	{

	}

	BinaryTree::Node::~Node()
	{
		delete m_left;
		delete m_right;
	}

}