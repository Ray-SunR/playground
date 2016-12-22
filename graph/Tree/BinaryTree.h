#pragma once

#include <vector>

namespace src
{
	class BinaryTree
	{
	public:
		struct Node
		{
			Node(int data, Node* left, Node* right);
			int m_data;
			Node* m_left;
			Node* m_right;

			~Node();
		};

		BinaryTree();
		void LevelOrderTraversal(std::vector<int>& data);
		const Node* LCA(const Node* a, const Node* b) const;
		int Height(const Node* root) const;
		bool IsBST() const;
		Node*& Root();
		~BinaryTree();
	private:
		const Node* LCAHelper(const Node* root, const Node* a, const Node* b) const;
		bool IsBSTHelper(const Node* root) const;
		Node* m_root;
	};
}
