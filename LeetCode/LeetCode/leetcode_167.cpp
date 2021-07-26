#pragma once
#include "ISoultion.h"
#include <array>

/// <summary>
/// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
/// </summary>
/// <param name="numbers">vector<int>  sorted in non-decreasing order(��������) </param>
/// <param name="targer"> int</param>
/// 
/// target ���ڸ� ����� ���� ���ؾ��ϴ� index 2�� return
/// 
/// 
class LeetCode_167 : public ISolution {
public:

	vector<int> twoSum(vector<int>& numbers, int target)
	{
		int left = 0;
		int right = numbers.size() - 1;


		while (left < right)
		{
			if (numbers[left] + numbers[right] == target)
			{
				return { left + 1, right + 1 };
			}
			else if (numbers[left] + numbers[right] > target)
			{
				right--;
			}
			else
				left++;
		}

		return {};

	}

	// ISolution��(��) ���� ��ӵ�
	virtual void Drive() override
	{
		std::vector<int> number;
		int target;


		number = {2,7,11,15};
		target = 9;

		twoSum(number, target);
	}
};

