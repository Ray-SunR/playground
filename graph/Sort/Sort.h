//
// Created by SunRenchen on 16-12-14.
//

#ifndef APP_SORT_H
#define APP_SORT_H
#include <vector>

class Sort {
public:
    static void qsort(std::vector<int>& nums);
    static void qsort1(std::vector<int>& nums);
    static void qsort3way(std::vector<int>& nums);
    static void selectsort(std::vector<int>& nums);
    static void insertsort(std::vector<int>& nums);
    static void heapsort(std::vector<int>& nums);
private:
    static void qsorthelper(std::vector<int>& nums, int low, int high);
    static void qsort1helper(std::vector<int>& nums, int low, int high);
    static int partition(std::vector<int>& nums, int low, int high);
    static int partition1(std::vector<int>& nums, int low, int high);
    static void qsort3wayhelper(std::vector<int>& nums, int low, int high);

    static void sink(std::vector<int>& nums, int pos, int n);
};


#endif //APP_SORT_H
