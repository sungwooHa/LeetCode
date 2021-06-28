#pragma once
#include "ISoultion.h"
#include <stack>

/// <summary>
/// https://leetcode.com/problems/min-stack/
/// </summary>
/// stack �����!
/// min ���� ���Ҽ� �־����.
/// 
class LeetCode_155 : public ISolution 
{
private:
    std::stack<std::pair<int, int>> minStack;
public:
    /** initialize your data structure here. */

    LeetCode_155()
    {
    }
    void push(int val)
    {
        if (minStack.empty())
        {
            minStack.push({ val, val });
        }
        else
        {
            minStack.push({ val, std::min(val, minStack.top().second) });
        }
    }

    void pop() 
    {
        minStack.pop();
    }

    int top()
    {
        return minStack.top().first;
    }

    int getMin()
    {
        return minStack.top().second;
    }

	// ISolution��(��) ���� ��ӵ�
	virtual void Drive() override
	{
	}
};

