//
// Created by SunRenchen on 16-12-14.
//

#include "Sort.h"
#include <iostream>

void swap(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

int Sort::partition(std::vector<int> &nums, int low, int high)
{
    int target = nums[low];
    int i = low + 1; int j = high;
    while (i <= j)
    {
        while (i <= j && nums[i] < target) { i++; }
        while (i <= j && nums[j] >= target) { j--; }
        if (i > j) break;
        ::swap(nums[i], nums[j]);
    }
    nums[low] = nums[j];
    nums[j] = target;
    return j;
}

void Sort::qsort(std::vector<int> &nums)
{
    qsorthelper(nums, 0, nums.size() - 1);
}

void Sort::qsorthelper(std::vector<int> &nums, int low, int high)
{
    if (low >= high) { return; }
    int pos = partition(nums, low, high);
    qsorthelper(nums, low, pos - 1);
    qsorthelper(nums, pos + 1, high);
}

int Sort::partition1(std::vector<int> &nums, int low, int high)
{
    int pivot = low + (high - low) / 2;
    int target = nums[pivot];
    int i = low; int j = high;
    while (i <= j)
    {
        while (i <= j && nums[i] < target) { i++; }
        if (i <= j)
        {
            ::swap(nums[i], nums[pivot]);
            pivot = i++;
        }
        while (i <= j && nums[j] > target) { j--; }
        if (i <= j)
        {
            ::swap(nums[j], nums[pivot]);
            pivot = j--;
        }
    }
    nums[pivot] = target;
    return pivot;
}

void Sort::qsort1helper(std::vector<int> &nums, int low, int high)
{
    if (low >= high) { return; }
    int pos = partition1(nums, low, high);
    qsort1helper(nums, low, pos - 1);
    qsort1helper(nums, pos + 1, high);
}

void Sort::qsort1(std::vector<int> &nums)
{
    qsort1helper(nums, 0, nums.size() - 1);
}

void Sort::qsort3wayhelper(std::vector<int> &nums, int low, int high)
{
    if (low >= high) { return; }
    int i = low + 1;
    int lt = low; int gt = high;
    while (i <= gt)
    {
        if (nums[i] < nums[lt]) { ::swap(nums[i], nums[lt]); i++; lt++; }
        else if (nums[i] > nums[gt]) { ::swap(nums[i], nums[gt]); gt--; }
        else { i++; }
    }
    qsort3wayhelper(nums, low, lt);
    qsort3wayhelper(nums, gt, high);
}

void Sort::qsort3way(std::vector<int> &nums)
{
    qsort3wayhelper(nums, 0, nums.size() - 1);
}

void Sort::selectsort(std::vector<int> &nums)
{
    for (int i = 0;i < nums.size(); i++)
    {
        int min_pos = i;
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[j] < nums[min_pos])
            {
                min_pos = j;
            }
        }
        ::swap(nums[i], nums[min_pos]);
    }
}