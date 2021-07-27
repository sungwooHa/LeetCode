#pragma once
#include "ISoultion.h"

/// <summary>
/// ��ȣ ¦���߱�.
/// stack �̿��� ��� input
/// https://leetcode.com/problems/valid-parentheses/
/// </summary>
/// <param name="s"></param>
/// <returns></returns>
class LeetCode_20 : public ISolution {
public:
	bool isValid(string s)
	{
		stack<char> bracketStack;

		int index(0);
		bracketStack.push(s[index++]);
		while (!bracketStack.empty())
		{
			if (index > (s.size() - 1))
				return false;

			auto curBracket = bracketStack.top();

			if (s[index] == ')' && curBracket == '(')
			{
				bracketStack.pop();
			}
			else if (s[index] == ']' && curBracket == '[')
			{
				bracketStack.pop();
			}
			else if (s[index] == '}' && curBracket == '{')
			{
				bracketStack.pop();
			}
			else
				bracketStack.push(s[index]);

			++index;

			if (bracketStack.empty() && index < s.size())
			{
				bracketStack.push(s[index]);
				++index;
			}
		}
		return true;
	}

	// ISolution��(��) ���� ��ӵ�
	virtual void Drive() override
	{
		assert(isValid("()") == true);
		assert(isValid("()[]{}") == true);
		assert(isValid("(]") == false);
		assert(isValid("([)]") == false);
		assert(isValid("{[]}") == true);
	}
};

