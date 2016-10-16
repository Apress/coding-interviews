// Coding Interviews: Questions, Analysis & Solutions
// Harry He

#include <stdlib.h>
#include <stdio.h>
#include "../Utility/list.h"

void Sort(ListNode** pHead)
{
    if(pHead == NULL || *pHead == NULL)
        return;
    
    ListNode* pLastSorted = *pHead;
    ListNode* pToBeSorted = pLastSorted->m_pNext;
    while(pToBeSorted != NULL)
    {
        if(pToBeSorted->m_nValue < (*pHead)->m_nValue)
        {
            pLastSorted->m_pNext = pToBeSorted->m_pNext;
            pToBeSorted->m_pNext = *pHead;
            *pHead = pToBeSorted;
        }
        else
        {
            ListNode* pNode = *pHead;
            while(pNode != pLastSorted 
                && pNode->m_pNext->m_nValue < pToBeSorted->m_nValue)
            {
                pNode = pNode->m_pNext;
            }
                
            if(pNode != pLastSorted)
            {
                pLastSorted->m_pNext = pToBeSorted->m_pNext;
                pToBeSorted->m_pNext = pNode->m_pNext;
                pNode->m_pNext = pToBeSorted;
            }
            else
                pLastSorted = pLastSorted->m_pNext;
        }

        pToBeSorted = pLastSorted->m_pNext;
    }
}

// ==================== Test Code ====================

void Test(char* testName, ListNode** pHead)
{
    if(testName != NULL)
        printf("%s begins: \n", testName);
    
    if(pHead != NULL)
        PrintList(*pHead);
    Sort(pHead);
    if(pHead != NULL)
        PrintList(*pHead);
}

void Test1()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(3);
    ListNode* pNode3 = CreateListNode(5);
    ListNode* pNode4 = CreateListNode(7);
    ListNode* pNode5 = CreateListNode(2);
    ListNode* pNode6 = CreateListNode(4);
    ListNode* pNode7 = CreateListNode(6);
    ListNode* pNode8 = CreateListNode(8);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);
    ConnectListNodes(pNode7, pNode8);

    ListNode* pHead = pNode1;
    Test("Test1", &pHead);
    
    DestroyList(pHead);
}

// nodes in a list are already sorted
void Test2()
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

    ListNode* pHead = pNode1;
    Test("Test2", &pHead);
    
    DestroyList(pHead);
}

// nodes in a list are decreasingly sorted
void Test3()
{
    ListNode* pNode1 = CreateListNode(8);
    ListNode* pNode2 = CreateListNode(7);
    ListNode* pNode3 = CreateListNode(6);
    ListNode* pNode4 = CreateListNode(5);
    ListNode* pNode5 = CreateListNode(4);
    ListNode* pNode6 = CreateListNode(3);
    ListNode* pNode7 = CreateListNode(2);
    ListNode* pNode8 = CreateListNode(1);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);
    ConnectListNodes(pNode7, pNode8);

    ListNode* pHead = pNode1;
    Test("Test3", &pHead);
    
    DestroyList(pHead);
}

// A list has only one node
void Test4()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pHead = pNode1;
    Test("Test4", &pHead);
    
    DestroyList(pHead);
}

// A list has duplicated nodes
void Test5()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(2);
    ListNode* pNode4 = CreateListNode(1);
    ListNode* pNode5 = CreateListNode(4);
    ListNode* pNode6 = CreateListNode(3);
    ListNode* pNode7 = CreateListNode(4);
    ListNode* pNode8 = CreateListNode(2);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);
    ConnectListNodes(pNode7, pNode8);

    ListNode* pHead = pNode1;
    Test("Test5", &pHead);
    
    DestroyList(pHead);
}

// Empty List
void Test6()
{
    Test("Test6", NULL);
}

// Empty List
void Test7()
{
    ListNode* pHead = NULL;
    Test("Test7", &pHead);
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
        
    return 0;
}