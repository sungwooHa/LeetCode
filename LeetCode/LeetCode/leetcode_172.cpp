#pragma once
#include "ISoultion.h"

/// <summary>
/// https://leetcode.com/problems/factorial-trailing-zeroes/
/// </summary>
/// <param name="n">string <int> </param>
/// 
/// Given an integer n, return the number of trailing zeroes in n!.
/// zero -->  2*5;
/// 
/// 

class LeetCode_172 : public ISolution {
public:
	int trailingZeroes(int n)
	{
		int cnt(0);
		for (long long i = 5; n / i; i *= 5)
			cnt += n / i;

		return cnt;
	}

	// ISolution��(��) ���� ��ӵ�
	virtual void Drive() override
	{
	}
};

