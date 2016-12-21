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
    static void shellsort(std::vector<int>& nums);
private:
    static void qsorthelper(std::vector<int>& nums, int low, int high);
    static void qsort1helper(std::vector<int>& nums, int low, int high);
    static int partition(std::vector<int>& nums, int low, int high);
    static int partition1(std::vector<int>& nums, int low, int high);
    static void qsort3wayhelper(std::vector<int>& nums, int low, int high);
    static void sink(std::vector<int>& nums, int pos, int n);
    static void shellsorthelper(std::vector<int>& nums, std::vector<int>& axill, int low, int high);
    static void merge(std::vector<int>& data, std::vector<int>& axill,int low, int mid, int high);
};


#endif //APP_SORT_H
