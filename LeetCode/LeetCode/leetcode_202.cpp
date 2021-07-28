#pragma once
#include "ISoultion.h"
#include <cmath>
/// <summary>
/// https://leetcode.com/problems/happy-number/
/// </summary>
/// 
/// �� �ڸ����� ������ ����
/// ��� �ݺ�
/// ���� 1�� ������ true
/// ���� 1�� ������ ���ϸ� false.
/// check infinite loop
/// 

class LeetCode_202 : public ISolution {
public:
    bool isHappy(int n)
    {
        //check infinite loop
        std::unordered_map<int, int> hashMap;

        const int HAPPY_NUMBER = 1;

        while (n != HAPPY_NUMBER)
        {
            if (!hashMap[n])
                hashMap[n]++;
            else
                return false;

            int sum = 0;
            while (n)
            {
                sum += pow(n % 10, 2);
                n /= 10;
            }
            
            n = sum;
        }

        return true;
    }

    // ISolution��(��) ���� ��ӵ�
    virtual void Drive() override
    {
    }
};

