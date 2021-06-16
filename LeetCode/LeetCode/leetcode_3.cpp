#pragma once
#include "ISoultion.h"

/// <summary>
/// https://leetcode.com/problems/longest-substring-without-repeating-characters/
/// </summary>
/// <param name="nums"> �ԷµǴ� ���� �迭 </param>
/// <param name="target">2���� ���ؼ� ����� ���� ���� </param>
/// <returns>target�� ���� �� �ִ� �� �� </returns>
/// 
class LeetCode_3 : public ISolution {
public:
	int lengthOfLongestSubstring(string s)
	{
        //�ݺ� ���� ���� ���� �� ���ڿ� ã��.

        //pwwkew push.
        //[0] p -> pw   -> "pw"X
        //[1]     w     -> "w" X  ->  
        //[2]           -> w      ->  wk     ->wke   ->"wke" X
        //[3]                     ->  k      ->ke    -> kew
        //[4]                                ->e     ->  ew
        //[5]                                       ->   w

        if (s.empty())
            return 0;   //���� ������ return 0

        unordered_map<int, int> lastIdx; //map�� ���� �ݺ��Ǵ°� �ƴѰ� ã��.
        int startIdx = 0;
        unsigned int result(0);

        //��ü�� ��ȸ
        //�ѹ� ���鼭, �� ������ �ݺ� ���� �ʴ� word üũ��
        //start idx�� ��� �����ְ�
        //���� idx - start idx(�ݺ������ʴ�) +1 �̶� ������ ����result�� ��

        //pww kew
        for (unsigned int i = 0; i < s.size(); i++)
        {
            if (lastIdx.find(s[i]) == lastIdx.end())
                lastIdx[s[i]] = -1;  //������� -1 ����, start idx   // map {p, -1}---> map {p, 0} {w, -1}
            //map {p, 0} {w, 1}
            startIdx = max(startIdx, lastIdx[s[i]] + 1); //�ݺ��� ���, start�� �ٲ۴�.  //startIdx == 0 // startIdx = 0 // startIdx = 2

            result = max(result, i - startIdx + 1); //max(reuslt, 0 - 0 + 1) --> 1 --> max(1, 1 - 0 + 1) -->2  // (2, 2 - 2 + 1) --> 2

            lastIdx[s[i]] = i; //map {p, 0} {w, 1}
        }

        return result;
	}

	// ISolution��(��) ���� ��ӵ�
	virtual void Drive() override
	{
	}
};
