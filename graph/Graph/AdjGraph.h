//
// Created by SunRenchen on 16-12-07.
//

#ifndef GRAPH_ADJGRAPH_H
#define GRAPH_ADJGRAPH_H

#include <map>
#include <vector>
#include <list>
#include <set>

#include "GraphNode.h"
#include "GraphEdge.h"

// directed graph
class AdjGraph {
public:
    AdjGraph(std::vector<int>& nodes);
    AdjGraph();
    void AddEdge(int u, int v);
    GraphNode& AddNode(int v);
    void RemoveEdge(int u, int v);
    bool HasEdge(int u, int v);
    const std::list<GraphEdge>& GetEdges(int v) const;
    std::string Print() const;
    std::string BreadFirstSearch() const;
    std::string DepthFirstSearch() const;
private:
    void DepthFirstSearch(int v, std::string& str, std::set<int>& set) const;
    GraphNode& GetGraphNode(int id);
    std::map<int, GraphNode> m_nodes;
};


#endif //GRAPH_ADJGRAPH_H
