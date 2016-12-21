#include <iostream>
#include "Graph/AdjGraph.h"
#include "Tree/IntervalSearchTree.h"
#include "Sort/Sort.h"
#include "Stack/Stack.h"

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

    IntervalSearchTree tree;

    tree.AddInterval(tInterval(17, 19));
    tree.AddInterval(tInterval(5, 8));
    tree.AddInterval(tInterval(4, 8));
    tree.AddInterval(tInterval(15, 18));
    tree.AddInterval(tInterval(7, 10));
    tree.AddInterval(tInterval(21, 24));
    tree.AddInterval(tInterval(16, 22));

    if (const IntervalNode* ret = tree.Search(tInterval(21, 23)))
    {
        cout << "(" << ret->m_min << ", " << ret->m_max << ")" << endl;
    }
    cout << tree.Print() << endl;

    int a[] = {3, 2, 1, 2, 2, 9999, 1, 1, 3, 5, 9, 1, 2, 3, 4 ,5, 4, 3, 2, 1 ,0};
    vector<int> nums(a, a + sizeof(a) / sizeof(a[0]));
    Sort::shellsort(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    Stack stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);
    cout << "top: " << stk.top() << endl;
    stk.pop();
    cout << "top: " << stk.top() << endl;
    stk.push(5);
    stk.push(6);
    stk.push(7);
    stk.pop();
    cout << "top: " << stk.top() << endl;
    stk.pop();
    stk.pop();
    stk.pop();
    stk.pop();
    cout << "size: " << stk.size() << endl;
    return 0;
}
