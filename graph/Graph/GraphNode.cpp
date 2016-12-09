//
// Created by SunRenchen on 16-12-07.
//
#include <algorithm>

#include "GraphNode.h"

GraphNode::GraphNode(int source)
    :m_source(source) {}

void GraphNode::AddEdge(int v)
{
    std::list<GraphEdge>::const_iterator it;
    it = m_edges.begin();
    while (it != m_edges.end() && it->Id() != v)
    {
        ++it;
    }

    if (it == m_edges.end())
    {
        m_edges.emplace_back(GraphEdge(v));
    }
}

void GraphNode::RemoveEdge(int v)
{
    m_edges.remove_if([v](const GraphEdge& edge){return edge.Id() == v;});
}

bool GraphNode::HasEdge(int v) const
{
    std::list<GraphEdge>::const_iterator it = std::find_if(m_edges.begin(), m_edges.end(), [v](const GraphEdge& edge){return edge.Id() == v;});
    return it != m_edges.end();
}

const std::list<GraphEdge>& GraphNode::Neighbors() const
{
    return m_edges;
}

int GraphNode::Data() const { return m_source; }