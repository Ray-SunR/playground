//
// Created by SunRenchen on 16-12-20.
//

#include <exception>
#include <stdexcept>
#include "Stack.h"

Stack::Stack()
	: m_size(0)
	, m_head(nullptr)
	, m_tail(nullptr)
	{ }

bool Stack::empty()
{
	return m_size == 0;
}

int Stack::size() { return m_size; }

void Stack::push(int val)
{
	if (!m_head)
	{
		m_head = new Node(val);
		m_tail = m_head;
	}
	else
	{
		Node* node = new Node(val);
		m_tail->m_next = node;
		node->m_pre = m_tail;
		m_tail = node;
	}
	m_size++;
}

void Stack::pop()
{
	if (!m_head) { throw std::length_error("Invalid operation"); }
	Node* node = m_tail;
	m_tail = m_tail->m_pre;
	m_tail->m_next = nullptr;
	delete node;
	m_size--;
}

int Stack::top()
{
	if (!m_tail) { throw std::length_error("Invalid operation"); }
	return m_tail->m_value;
}