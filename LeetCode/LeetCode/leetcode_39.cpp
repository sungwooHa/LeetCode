#pragma once
#include "ISoultion.h"


/// <summary>
/// https://leetcode.com/problems/combination-sum/
/// </summary>
/// <returns></returns>
class LeetCode_39 : public ISolution {
public:

	void combi(vector<int>& candidates, const int diff, vector<vector<int>>& res, vector<int>& curCombi, int curIdx)
	{
		if (diff == 0)
		{
			res.push_back(curCombi);
			return;
		}

		for (auto idx = curIdx; idx < candidates.size() && candidates[idx] <= diff; ++idx)
		{
			curCombi.push_back(candidates[idx]);
			combi(candidates, diff - candidates[idx], res, curCombi, idx);
			curCombi.pop_back();
		}
	}
	vector<vector<int>> combinationSum(vector<int>& candidates, int target)
	{
		//���� ������� ������ �������� target�� ������
		//���� ���� ��� ���� �������.
		//�ߺ����� ����

		vector<vector<int>> res;
		vector<int> curCombi;
		sort(candidates.begin(), candidates.end());
		combi(candidates, target, res, curCombi, 0);
		return res;
	}
	// ISolution��(��) ���� ��ӵ�
	virtual void Drive() override
	{
		vector<int> candidates; 
		int target (0);
		candidates = { 2, 3, 6, 7 };
		target = 7;

		combinationSum(candidates, target);
	}
};

