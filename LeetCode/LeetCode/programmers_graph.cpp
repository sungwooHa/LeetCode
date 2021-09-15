#pragma once

#include "ISoultion.h"

#include <vector>
#include <string>


class graph_ranking : public ISolution
{
public:
    int solution(int n, vector<vector<int>> results) 
    {
        //��� ����� ��� ��θ� ã��.
        //�� ��尡 ��� ���� ���� �ִ� ��ΰ� �ִٸ�, (���дϱ� �ݴ뵵 ���) ��ŷ�� �� �� ����
        //�˰��� : �÷��̵� �ͼ� (floyd warshall)

        int answer = 0;
        //���а� �־�����.
        //����� Ȯ���� ������ ã�ƶ�.
        std::vector<std::vector<bool>> gameResult(n+1, std::vector<bool>(n+1, false));

        constexpr int IDX_WINNER = 0;
        constexpr int IDX_LOSER = 1;

        for (const auto& gameInfo : results)
        {
            gameResult[gameInfo[IDX_WINNER]][gameInfo[IDX_LOSER]] = true;
        }

        //i ���İ��� ���
        for (unsigned int i = 1; i <= n; ++i)
        {
            //j = ��� ���
            for (unsigned int j = 1; j <= n; ++j)
            {
                //k = ���� ���
                for (unsigned int k = 1; k <= n; ++k)
                {
                    if (gameResult[j][i] && gameResult[i][k])
                    {
                        gameResult[j][k] = true;
                    }
                }
            }
        }

        for (unsigned int i = 1; i <= n; ++i)
        {
            int knowRankingCount(1);
            for (unsigned int j = 1; j <= n; ++j)
            {
                if (gameResult[i][j] || gameResult[j][i])
                    knowRankingCount++;
                    
            }

            if (knowRankingCount == n)
                answer++;
        }

        return answer;
    }
    virtual void Drive() override
    {

        std::vector<std::vector<int>> results;
        int n(0);

        results = { { 4, 3 }, { 4, 2 }, { 3, 2 }, { 1, 2 }, { 2, 5 } };
        n = 5;

        auto val = solution(n, results);
    }
};
