#pragma once
#include "ISoultion.h"

#include <vector>

class programmers_03 : public ISolution
{
public:


	//count == ����� �� return;
	//count == �л� �� return;
	int dfs(std::vector<bool> calendar, int numb, const vector<vector<int>>& T, int count)
	{
		if (count == calendar.size() || count == T.size())
			return count;

		if (numb >= T.size())
			return count;

		auto period = T[numb];
		int maximum(0);

		//�ڱ��ڽ� pass
		//count ����
		maximum = std::max(dfs(calendar, numb + 1, T, count), maximum);

		if (count == calendar.size() || count == T.size())
			return maximum;

		for (int sDate = period[0]; sDate <= period[1]; sDate++)
		{
			if (calendar[sDate -1])
				continue;

			calendar[sDate - 1] = true;
			maximum = std::max(dfs(calendar, numb + 1, T, count + 1), maximum);

			if (count == calendar.size() || count == T.size())
				return maximum;

			calendar[sDate - 1] = false;
		}

		return maximum;
	}

	int solution(int N, int K, vector<vector<int> >T)
	{
		//N��
		//1�Ϻ��� K�ϱ���
		//����� �Ϸ�
		//�л����� ����� ���ϴ� ���� �ٸ�

		//T Size = N
		//t = [start, end]

		//calendar<bool>, K

		std::vector<bool> calendar(K, false);

		return dfs(calendar, 0, T, 0);
	}

	virtual void Drive() override
	{

		int n;
		int k;
		vector<vector<int>> t;
		int result;

		n = 4;
		k = 4;
		t = { { 1, 3 }, { 1, 1 }, { 2, 3 }, { 3, 4 } };
		result = 4;

		assert(result == solution(n, k, t));


		n = 6;
		k = 4;
		t = {{1,3},{3,4},{2,4},{2,4},{2,3},{1,2}  };
		result = 4;

		assert(result == solution(n, k, t));



	}
};