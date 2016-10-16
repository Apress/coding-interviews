// Coding Interviews: Questions, Analysis & Solutions
// Harry He

#include <stdio.h>
#include "../Utility/list.h"

void ReverseGroup(ListNode* pNode1, ListNode* pNode2);

ListNode* Reverse(ListNode* pHead, unsigned int k)
{
    if(pHead == NULL || k <= 1)
        return pHead;

    ListNode* pReversedHead = NULL;
    ListNode* pNode1 = pHead;
    ListNode* pPrev = NULL;
    while(pNode1 != NULL)
    {
        // find k nodes within a group
        ListNode* pNode2 = pNode1;
        ListNode* pNext = NULL;
        for(unsigned int i = 1; pNode2->m_pNext != NULL && i < k; ++i)
            pNode2 = pNode2->m_pNext;

        pNext = pNode2->m_pNext;

        // reverse nodes within a group
        ReverseGroup(pNode1, pNode2);

        // connect groups together
        if(pReversedHead == NULL)
            pReversedHead = pNode2;

        if(pPrev != NULL)
            pPrev->m_pNext = pNode2;
        pPrev = pNode1;
        pNode1 = pNext;
    }

    return pReversedHead;
}

void ReverseGroup(ListNode* pNode1, ListNode* pNode2)
{
    ListNode* pNode = pNode1;
    ListNode* pPrev = NULL;
    while(pNode != pNode2)
    {
        ListNode* pNext = pNode->m_pNext;
        pNode->m_pNext = pPrev;

        pPrev = pNode;
        pNode = pNext;
    }
    
    pNode->m_pNext = pPrev;
}

// ==================== Test Code ====================
ListNode* Test(char* testName, ListNode* pHead, unsigned int k)
{
    if(testName != NULL)
        printf("====%s begins: ====\n", testName);

    printf("The original list is: ");
    PrintList(pHead);
    
    printf("The reversed list is: ");
    ListNode* pReversedHead = Reverse(pHead, k);
    PrintList(pReversedHead);

    printf("\n\n");

    return pReversedHead;
}

ListNode* BuildList()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);
    ListNode* pNode6 = CreateListNode(6);
    ListNode* pNode7 = CreateListNode(7);
    ListNode* pNode8 = CreateListNode(8);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);
    ConnectListNodes(pNode7, pNode8);

    return pNode1;
}

void Test1()
{
    ListNode* pHead = BuildList();
    ListNode* pReversedHead = Test("Test1", pHead, 1);

    DestroyList(pReversedHead);
}

void Test2()
{
    ListNode* pHead = BuildList();
    ListNode* pReversedHead = Test("Test2", pHead, 2);

    DestroyList(pReversedHead);
}

void Test3()
{
    ListNode* pHead = BuildList();
    ListNode* pReversedHead = Test("Test3", pHead, 3);

    DestroyList(pReversedHead);
}

void Test4()
{
    ListNode* pHead = BuildList();
    ListNode* pReversedHead = Test("Test4", pHead, 4);

    DestroyList(pReversedHead);
}

void Test5()
{
    ListNode* pHead = BuildList();
    ListNode* pReversedHead = Test("Test5", pHead, 5);

    DestroyList(pReversedHead);
}

void Test6()
{
    ListNode* pHead = BuildList();
    ListNode* pReversedHead = Test("Test6", pHead, 6);

    DestroyList(pReversedHead);
}

void Test7()
{
    ListNode* pHead = BuildList();
    ListNode* pReversedHead = Test("Test7", pHead, 7);

    DestroyList(pReversedHead);
}

void Test8()
{
    ListNode* pHead = BuildList();
    ListNode* pReversedHead = Test("Test8", pHead, 8);

    DestroyList(pReversedHead);
}

void Test9()
{
    ListNode* pHead = BuildList();
    ListNode* pReversedHead = Test("Test9", pHead, 9);

    DestroyList(pReversedHead);
}

void Test10()
{
    ListNode* pHead = NULL;
    ListNode* pReversedHead = Test("Test10", pHead, 0);

    DestroyList(pReversedHead);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
    Test9();
    Test10();

	return 0;
}

