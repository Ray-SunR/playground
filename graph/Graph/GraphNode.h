//
// Created by SunRenchen on 16-12-07.
//

#ifndef GRAPH_GRAPHNODE_H
#define GRAPH_GRAPHNODE_H

#include "GraphEdge.h"
#include <list>

class GraphNode {
public:
    GraphNode(int source);
    void AddEdge(int v);
    void RemoveEdge(int v);
    bool HasEdge(int v) const;
    const std::list<GraphEdge>& Neighbors() const;
    int Data() const;
private:
    int m_source;
    std::list<GraphEdge> m_edges;
};


#endif //GRAPH_GRAPHNODE_H
