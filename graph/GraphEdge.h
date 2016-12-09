//
// Created by SunRenchen on 16-12-07.
//

#ifndef GRAPH_GRAPHEDGE_H
#define GRAPH_GRAPHEDGE_H

class GraphEdge {
public:
    GraphEdge(int v);
    int Id() const { return m_source_id; }

private:
    int m_source_id;
};


#endif //GRAPH_GRAPHEDGE_H
