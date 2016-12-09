#include <iostream>
#include "AdjGraph.h"
using namespace std;
int main()
{
    AdjGraph graph;
    graph.AddNode(1);
    graph.AddNode(2);
    graph.AddNode(3);
    graph.AddNode(4);

    graph.AddEdge(1, 2);
    graph.AddEdge(1, 3);
    graph.AddEdge(2, 5);
    graph.AddEdge(3, 4);
    graph.AddEdge(4, 5);
    graph.AddEdge(4, 7);
    graph.AddEdge(5, 6);
    graph.AddEdge(4, 1);

    graph.AddEdge(1, 5);

    cout << graph.Print() << endl;
    cout << graph.BreadFirstSearch() << endl;
    cout << graph.DepthFirstSearch() << endl;
    return 0;
}
