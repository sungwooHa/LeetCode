#pragma once
#include "ISoultion.h"

/// <summary>
/// https://leetcode.com/problems/two-sum/
/// </summary>
/// <param name="nums"> �ԷµǴ� ���� �迭 </param>
/// <param name="target">2���� ���ؼ� ����� ���� ���� </param>
/// <returns>target�� ���� �� �ִ� �� �� </returns>
/// 
class LeetCode_1 : public ISolution {
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		std::vector<int> svRes(2);
		for (unsigned int i = 0; i < nums.size() - 1; ++i)
		{
			for (unsigned int j = i + 1; j < nums.size(); ++j)
			{
				if (nums[i] + nums[j] == target)
				{
					svRes[0] = i;
					svRes[1] = j;
					return svRes;

				}
			}
		}
		return svRes;
	}

	// ISolution��(��) ���� ��ӵ�
	virtual void Drive() override
	{
		auto lambda_verify = [&](std::vector<int> nums, int target, std::vector<int>result) -> void
		{
			auto val = twoSum(nums, target);
			assert(val[0] == result[0]);
			assert(val[1] == result[1]);
			return;
		};

		lambda_verify({ 2, 7, 11, 15 }, 9, { 0, 1 });
		lambda_verify({ 3, 2, 4 }, 6, { 1, 2, });
	}
};

