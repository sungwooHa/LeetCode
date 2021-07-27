#pragma once
#include "ISoultion.h"

/// <summary>
///https://leetcode.com/problems/binary-search/
/// </summary>
/// 
/// 
/// 

class LeetCode_704 : public ISolution {
public:
    int search(vector<int>& nums, int target)
    {
        unsigned int min = 0;
        unsigned int max = nums.size() - 1;
        int mid(0);

        while (min <= max)
        {
            mid = (max + min) / 2; //������ ���.

            if (mid >= nums.size())
                return -1;

            //Result return;
            if (target == nums[mid])
                return mid;

            if (target > nums[mid])
            {
                //�ּ� range ����
                min = mid + 1;
            }
            else
            {
                //�ִ� range ����
                max = mid - 1;
            }

        }

        return -1;
    }
	// ISolution��(��) ���� ��ӵ�
	virtual void Drive() override
	{
	}
};

