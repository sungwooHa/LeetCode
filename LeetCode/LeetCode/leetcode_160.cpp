#pragma once
#include "ISoultion.h"

/// <summary>
/// https://leetcode.com/problems/intersection-of-two-linked-lists/
/// </summary>
/// <param name="HeadA"> Linked list </param>
/// <param name="HeadB"> Linked list </param>
/// 
/// ������ node�� list�� ���� ���ļ� return,.
/// 
class LeetCode_160 : public ISolution {
public:
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
	{
		ListNode* res = nullptr;
		bool find(false);

		ListNode *curA, *curB;

		while (headA)
		{
			curA = headA;
			curB = headB;
			while (curA && curB)
			{
				//curA�� curB�� �־����.
				if (curA == curB)
				{
					//curA, curB ������
					//���������� ���ƾ���.

					if (!find)
					{
						//���� �߰�
						res = curB;
						find = true;
					}
					//�Ѵ� �������� �ѱ�
					curA = curA->next;
					curB = curB->next;
				}
				else
				{
					//curA, curB �ٸ���
					//curB�� �������� �Űܼ� Ȯ��
					//curA�� �ٽ� next;

					find = false;
					res = nullptr;
					curA = headA;
					curB = curB->next;
				}
			}

			if (find)
			{
				//ã������
				break;
			}

			//ã�� ��������
			//HeadA = headA->next;
			headA = headA->next;
		}
		return res;
	}
	ListNode* getIntersectionNode_best(ListNode* headA, ListNode* headB)
	{
		ListNode* curA = headA;
		ListNode* curB = headB;
		while (curA != curB)
		{
			curA = curA ? curA->next : headB;
			curB = curB ? curB->next : headA;
		}
		return curA;
	}



	// ISolution��(��) ���� ��ӵ�
	virtual void Drive() override
	{
	}
};

