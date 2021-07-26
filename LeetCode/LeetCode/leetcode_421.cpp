#pragma once
#include "ISoultion.h"
#include <array>

/// <summary>
/// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
/// </summary>
/// xor : 2���� �ٸ� ��쿡 �ִ밪
/// 
/// nums array�� �� 2���� �̿��ؼ�, �ִ� xor ������� ���϶�.
/// 
/// 


class Leetcode_421 : public ISolution
{
public:
	int findMaximumXOR(vector<int>& nums) 
	{
		std::sort(nums.begin(), nums.end());

		auto lambda_ToZeroCount = [](int val)
		{
			int cnt(0);
			while (val)
			{
				val >>= 1;
				cnt++;
			}
			return cnt;
		};


		//�ĺ��� ã��
		std::unordered_set<int> hashCandidate; //val
		int prevCnt;

		for (int i = nums.size() - 1; i >= 0; --i)
		{
			auto cnt = lambda_ToZeroCount(nums[i]);

			if (hashCandidate.empty())
			{
				hashCandidate.insert(nums[i]);
				prevCnt = cnt;
				continue;
			}
			if (prevCnt > cnt)
				break;

			hashCandidate.insert(nums[i]);
		}

		int res(0);
		//�ĺ����� ���ؼ� ���� ū�� ã��
		for (int i = 0; i < nums.size(); ++i)
		{
			for (const auto& cntMaxValue : hashCandidate)
			{
				if (cntMaxValue == nums[i])
					continue;

				res = std::max(res, nums[i] ^ cntMaxValue);
			}
		}

		return res;
	}
	virtual void Drive() override
	{
	}
};