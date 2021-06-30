#pragma once
#include "ISoultion.h"

/// <summary>
/// https://leetcode.com/problems/excel-sheet-column-title/
/// </summary>
/// <param name="columnNumber">int </param>
/// excel column return!
/// A -> 1
/// AA -> 27

class LeetCode_168 : public ISolution {
public:

	string convertToTitle(int columnNumber) 
	{
		//ASCII �ڵ�
		//26���� �����

		string res;
		while (columnNumber > 0)
		{
			columnNumber--; //�� �ڸ��� 1���� �����ϱ⶧��.
			const char ch = 'A' + columnNumber % 26;
			res = ch + res;
			columnNumber /= 26;
		}

		return res;
	}

	// ISolution��(��) ���� ��ӵ�
	virtual void Drive() override
	{
		assert(strcmp(convertToTitle(1).c_str(), "A") == 0);
		assert(strcmp(convertToTitle(28).c_str(), "AB") == 0);
		assert(strcmp(convertToTitle(701).c_str(), "ZY") == 0);
		assert(strcmp(convertToTitle(2147483647).c_str(), "FXSHRXW") == 0);

	}
};

