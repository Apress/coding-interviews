// Coding Interviews: Questions, Analysis & Solutions
// Harry He

#include <stdio.h>
#include "../utility/BinaryTree.h"
#include <limits>

using namespace std;

bool isBSTCore_Solution1(BinaryTreeNode* pRoot, int min, int max);
bool isBSTCore_Solution2(BinaryTreeNode* pRoot, int& prev);

// ==================== Solution 1 ====================
bool isBST_Solution1(BinaryTreeNode* pRoot)
{
    int min = numeric_limits<int>::min();
    int max = numeric_limits<int>::max();
    return isBSTCore_Solution1(pRoot, min, max);
}

bool isBSTCore_Solution1(BinaryTreeNode* pRoot, int min, int max)
{
    if(pRoot == NULL)
        return true;

    if(pRoot->m_nValue < min || pRoot->m_nValue > max)
        return false;

    return isBSTCore_Solution1(pRoot->m_pLeft, min, pRoot->m_nValue)
        && isBSTCore_Solution1(pRoot->m_pRight, pRoot->m_nValue, max);
}

// ==================== Solution 2 ====================
bool isBST_Solution2(BinaryTreeNode* pRoot)
{
    int prev = numeric_limits<int>::min();
    return isBSTCore_Solution2(pRoot, prev);
}

bool isBSTCore_Solution2(BinaryTreeNode* pRoot, int& prev)
{
    if(pRoot == NULL)
        return true;

    return isBSTCore_Solution2(pRoot->m_pLeft, prev) // previous node
        && (pRoot->m_nValue >= prev) // current node
        && isBSTCore_Solution2(pRoot->m_pRight, prev = pRoot->m_nValue); // next node
}

// ==================== Test Code ====================
void Test(char* testName, BinaryTreeNode* pRoot, bool expected)
{
    if(testName != NULL)
        printf("%s begins: ", testName);

    if(isBST_Solution1(pRoot) == expected)
        printf("Solution 1 Passed; ");
    else
        printf("Solution 1 FAILED; ");

    if(isBST_Solution2(pRoot) == expected)
        printf("Solution 2 Passed.\n");
    else
        printf("Solution 2 FAILED.\n");
}

//            8
//        6      10
//       5 7    9  11
void Test1()
{
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode9 = CreateBinaryTreeNode(9);
    BinaryTreeNode* pNode11 = CreateBinaryTreeNode(11);

    ConnectTreeNodes(pNode8, pNode6, pNode10);
    ConnectTreeNodes(pNode6, pNode5, pNode7);
    ConnectTreeNodes(pNode10, pNode9, pNode11);

    Test("Test1", pNode8, true);

    DestroyTree(pNode8);
}

//            8
//        10      6
//      11   9  7   5
void Test2()
{
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode9 = CreateBinaryTreeNode(9);
    BinaryTreeNode* pNode11 = CreateBinaryTreeNode(11);

    ConnectTreeNodes(pNode8, pNode10, pNode6);
    ConnectTreeNodes(pNode10, pNode11, pNode9);
    ConnectTreeNodes(pNode6, pNode7, pNode5);

    Test("Test2", pNode8, false);

    DestroyTree(pNode8);
}
//            5
//        5      5
//      3  
void Test3()
{
    BinaryTreeNode* pNode51 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode52 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode53 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);

    ConnectTreeNodes(pNode51, pNode52, pNode53);
    ConnectTreeNodes(pNode52, pNode3, NULL);

    Test("Test3", pNode51, true);

    DestroyTree(pNode51);
}

//            5
//        5       5
//              3  
void Test4()
{
    BinaryTreeNode* pNode51 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode52 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode53 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);

    ConnectTreeNodes(pNode51, pNode52, pNode53);
    ConnectTreeNodes(pNode53, pNode3, NULL);

    Test("Test4", pNode51, false);

    DestroyTree(pNode51);
}

//            5
//          4
//        3
//      2
void Test5()
{
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);

    ConnectTreeNodes(pNode5, pNode4, NULL);
    ConnectTreeNodes(pNode4, pNode3, NULL);
    ConnectTreeNodes(pNode3, pNode2, NULL);

    Test("Test5", pNode5, true);

    DestroyTree(pNode5);
}

//        5
//         4
//          3
//           2
void Test6()
{
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);

    ConnectTreeNodes(pNode5, NULL, pNode4);
    ConnectTreeNodes(pNode4, NULL, pNode3);
    ConnectTreeNodes(pNode3, NULL, pNode2);

    Test("Test6", pNode5, false);

    DestroyTree(pNode5);
}

void Test7()
{
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);

    Test("Test7", pNode5, true);

    DestroyTree(pNode5);
}

void Test8()
{
    Test("Test8", NULL, true);
}

//        100
//        /
//       50   
//         \
//         150
void Test9()
{
    BinaryTreeNode* pNode100 = CreateBinaryTreeNode(100);
    BinaryTreeNode* pNode50 = CreateBinaryTreeNode(50);
    BinaryTreeNode* pNode150 = CreateBinaryTreeNode(150);

    ConnectTreeNodes(pNode100, pNode50, NULL);
    ConnectTreeNodes(pNode50, NULL, pNode150);

    Test("Test9", pNode100, false);

    DestroyTree(pNode100);
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

	return 0;
}

