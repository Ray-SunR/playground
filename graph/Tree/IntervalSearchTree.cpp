//
// Created by SunRenchen on 16-12-13.
//

#include "IntervalSearchTree.h"
#include <sstream>

namespace src
{
	IntervalNode::IntervalNode(const tInterval &interval)
	{
		m_min = interval.first;
		m_max = interval.second;
		m_right_max = m_max;
		m_left = nullptr;
		m_right = nullptr;
	}

	IntervalNode::~IntervalNode()
	{
		if (m_left) { delete m_left; }
		if (m_right) { delete m_right; }
	}

	IntervalNode* Insert(IntervalNode* root, const tInterval& interval)
	{
		if (!root) { return new IntervalNode(interval); }
		// found
		if (root->m_min > interval.first)
		{
			root->m_left = Insert(root->m_left, interval);
			if (root->m_left->m_right_max > root->m_right_max)
			{
				root->m_right_max = root->m_left->m_right_max;
			}
		}
		else
		{
			root->m_right = Insert(root->m_right, interval);
			if (root->m_right->m_right_max > root->m_right_max)
			{
				root->m_right_max = root->m_right->m_right_max;
			}
		}
		return root;
	}

	IntervalSearchTree::IntervalSearchTree() :m_root(nullptr) { }

	IntervalSearchTree::IntervalSearchTree(const std::vector<tInterval> &data) : m_root(nullptr)
	{
		for (int i = 0; i < data.size(); i++)
		{
			m_root = Insert(m_root, data[i]);
		}
	}

	void IntervalSearchTree::AddInterval(const tInterval &interval)
	{
		m_root = Insert(m_root, interval);
	}

	const IntervalNode* IntervalSearchTree::Search(const IntervalNode* node, const tInterval &interval) const
	{
		if (!node) { return nullptr; }

		// Found intersects
		if ((node->m_min <= interval.first && node->m_max >= interval.first) ||
			(node->m_min <= interval.second && node->m_max >= interval.second)) {
			return node;
		}
		// can't find any
		else if (node->m_right_max < interval.first) { return nullptr; }
		// left subtree is null
		else if (!node->m_left) { return Search(node->m_right, interval); }
		// left subtree's max is less than the query's low point
		else if (node->m_left->m_right_max < interval.first) { return Search(node->m_right, interval); }
		else { return Search(node->m_left, interval); }
	}

	const IntervalNode* IntervalSearchTree::Search(const tInterval &interval) const
	{
		return Search(m_root, interval);
	}

	void Print(IntervalNode* node, std::stringstream& ss)
	{
		if (!node) { return; }
		Print(node->m_left, ss);
		ss << "(" << node->m_min << " ," << node->m_max << ")" << " ";
		Print(node->m_right, ss);
	}

	std::string IntervalSearchTree::Print() const
	{
		std::stringstream ss;
		src::Print(m_root, ss);
		return ss.str();
	}

	IntervalSearchTree::~IntervalSearchTree()
	{
		delete m_root;
	}
}
