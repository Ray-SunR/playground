//
// Created by SunRenchen on 16-12-07.
//

#include "AdjGraph.h"
#include <string>
#include <sstream>
#include <queue>

AdjGraph::AdjGraph(std::vector<int>& nodes)
{
    for (int i = 0;i < nodes.size(); i++)
    {
        m_nodes.emplace(std::make_pair(nodes[i],nodes[i]));
    }
}

AdjGraph::AdjGraph() { }

GraphNode& AdjGraph::AddNode(int v)
{
    return GetGraphNode(v);
}

GraphNode& AdjGraph::GetGraphNode(int id)
{
    std::map<int, GraphNode>::iterator it = m_nodes.find(id);
    if (it == m_nodes.end()) {
        return m_nodes.emplace(id, GraphNode(id)).first->second;
    }
    else
    {
        return it->second;
    }
}

void AdjGraph::AddEdge(int u, int v)
{
    GraphNode& un = GetGraphNode(u);
    GraphNode& vn = GetGraphNode(v);
    un.AddEdge(v);
}

void AdjGraph::RemoveEdge(int u, int v)
{
    GraphNode& un = GetGraphNode(u);
    GraphNode& vn = GetGraphNode(v);
    un.RemoveEdge(v);
}

bool AdjGraph::HasEdge(int u, int v)
{
    return GetGraphNode(u).HasEdge(v);
}

std::string AdjGraph::Print() const
{
    std::stringstream ss;
    auto iter = m_nodes.cbegin();
    while (iter != m_nodes.end())
    {
        ss << "[" << iter->first << "]" << " " << "->" << " " << "[ ";
        auto neighbors = iter->second.Neighbors();
        auto jt = neighbors.cbegin();
        while (jt != neighbors.end())
        {
            ss << jt->Id() << " ";
            ++jt;
        }
        ss << "]" << std::endl;
        ++iter;
    }
    return ss.str();
}

std::string AdjGraph::BreadFirstSearch() const
{
    if (m_nodes.empty()) { return ""; }
    std::stringstream ss;
    std::queue<int> queue;
    std::set<int> set;
    auto iter = m_nodes.cbegin();
    queue.push(iter->first);
    while (!queue.empty())
    {
        int source = queue.front();
        queue.pop();
        if (set.find(source) == set.end())
        {
            iter = m_nodes.find(source);
            ss << iter->second.Data() << " ";
            // mark it as visited
            set.insert(source);
            auto neighbors = iter->second.Neighbors();
            for (auto iter = neighbors.cbegin(); iter != neighbors.cend(); ++iter)
            {
                queue.push(iter->Id());
            }
        }
    }
    return ss.str();
}

std::string AdjGraph::DepthFirstSearch() const
{
    if (m_nodes.empty()) { return ""; }
    std::string ret;
    std::set<int> set;
    DepthFirstSearch(m_nodes.begin()->first, ret, set);
    return ret;
}

void AdjGraph::DepthFirstSearch(int v, std::string& str, std::set<int>& set) const
{
    if (set.find(v) != set.end()) { return; }
    set.insert(v);
    const GraphNode& node = m_nodes.find(v)->second;
    str += std::to_string(node.Data()) + " ";
    auto neighbors = node.Neighbors();
    for (auto iter = neighbors.cbegin(); iter != neighbors.cend(); ++iter)
    {
        DepthFirstSearch(iter->Id(), str, set);
    }
}