//
// Created by SunRenchen on 16-12-13.
//

#ifndef APP_INTERVALSEARCHTREE_H
#define APP_INTERVALSEARCHTREE_H

#include <vector>
#include <utility>
#include <memory>

typedef std::pair<int, int> tInterval;

struct IntervalNode
{
    IntervalNode(const tInterval& interval);
    ~IntervalNode();
    int m_min;
    int m_max;
    int m_right_max;
    IntervalNode* m_left;
    IntervalNode* m_right;

    bool operator==(const IntervalNode& other) const
    {
        return m_min == other.m_min && m_max == other.m_max;
    }
};

class IntervalSearchTree
{
public:
    IntervalSearchTree();
    IntervalSearchTree(const std::vector<tInterval>& data);
    const IntervalNode* Search(const tInterval& interval) const;
    void AddInterval(const tInterval& interval);
    std::string Print() const;
    ~IntervalSearchTree();
private:
    const IntervalNode* Search(const IntervalNode* node, const tInterval& interval) const;
    IntervalNode* m_root;
};


#endif //APP_INTERVALSEARCHTREE_H
