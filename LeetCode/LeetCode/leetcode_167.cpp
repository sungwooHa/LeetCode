#pragma once
#include "ISoultion.h"

/// <summary>
/// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
/// </summary>
/// <param name="numbers">vector<int>  sorted in non-decreasing order(��������) </param>
/// <param name="targer"> int</param>
/// 
/// target ���ڸ� ����� ���� ���ؾ��ϴ� index return
/// 
/// 
class LeetCode_167 : public ISolution {
public:

	bool GetNumberIndex(int index, const int& targetNumber, const std::vector<int>& numbers, std::vector<int>
		res, int sum)
	{
		if (index >= numbers.size())
			return false;
	}

	vector<int> twoSum(vector<int>& numbers, int target)
	{

	}
	// ISolution��(��) ���� ��ӵ�
	virtual void Drive() override
	{
	}
};

