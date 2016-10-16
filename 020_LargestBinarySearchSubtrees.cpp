// Coding Interviews: Questions, Analysis & Solutions
// Harry He

#include <stdlib.h>
#include <stdio.h>
#include "../Utility/BinaryTree.h"

bool LargestBST(BinaryTreeNode* pRoot, int& min, int& max, int& largestSize);

int LargestBST(BinaryTreeNode* pRoot)
{
    int min, max, largestSize;
    LargestBST(pRoot, min, max, largestSize);
    
    return largestSize;
}

bool LargestBST(BinaryTreeNode* pRoot, int& min, int& max, int& largestSize)
{
    if(pRoot == NULL)
    {
        max = 0x80000000;
        min = 0x7FFFFFFF;
        largestSize = 0;
        return true;
    }

    int minLeft, maxLeft, leftSize;
    bool left = LargestBST(pRoot->m_pLeft, minLeft, maxLeft, leftSize);

    int minRight, maxRight, rightSize;
    bool right  = LargestBST(pRoot->m_pRight, minRight, maxRight, rightSize);
    
    bool overall = false;
    if(left && right && pRoot->m_nValue >= maxLeft && pRoot->m_nValue <= minRight)
    {
        largestSize = leftSize + rightSize + 1;
        overall = true;
    
        min = (pRoot->m_nValue < minLeft) ? pRoot->m_nValue : minLeft;
        max = (pRoot->m_nValue > maxRight) ? pRoot->m_nValue : maxRight;
    }
    else
        largestSize = (leftSize > rightSize) ? leftSize : rightSize;
        
    return overall;
}

// ==================== Test Code ====================
void Test(char* testName, BinaryTreeNode* pRoot, int expected)
{
    if(testName != NULL)
        printf("%s begins: ", testName);

    if(LargestBST(pRoot) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
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

    Test("Test1", pNode8, 7);

    DestroyTree(pNode8);
}

//            11
//        6      16
//       5 7       9
void Test2()
{
    BinaryTreeNode* pNode11 = CreateBinaryTreeNode(11);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode16 = CreateBinaryTreeNode(16);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode9 = CreateBinaryTreeNode(9);

    ConnectTreeNodes(pNode11, pNode6, pNode16);
    ConnectTreeNodes(pNode6, pNode5, pNode7);
    ConnectTreeNodes(pNode16, NULL, pNode9);

    Test("Test2", pNode11, 3);

    DestroyTree(pNode11);
}

//            12
//        6      9
//       5     8   10  
void Test3()
{
    BinaryTreeNode* pNode12 = CreateBinaryTreeNode(12);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode9 = CreateBinaryTreeNode(9);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);

    ConnectTreeNodes(pNode12, pNode6, pNode9);
    ConnectTreeNodes(pNode6, pNode5, NULL);
    ConnectTreeNodes(pNode9, pNode8, pNode10);

    Test("Test3", pNode12, 3);

    DestroyTree(pNode12);
}

//               5
//              /
//             3
//            /
//           4
//          /
//         2
//        /
//       1
void Test4()
{
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);

    ConnectTreeNodes(pNode5, pNode3, NULL);
    ConnectTreeNodes(pNode3, pNode4, NULL);
    ConnectTreeNodes(pNode4, pNode2, NULL);
    ConnectTreeNodes(pNode2, pNode1, NULL);

    Test("Test4", pNode5, 3);

    DestroyTree(pNode5);
}

// 2
//  \
//   1
//    \
//     3
//      \
//       4
//        \
//         5
void Test5()
{
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);

    ConnectTreeNodes(pNode2, NULL, pNode1);
    ConnectTreeNodes(pNode1, NULL, pNode3);
    ConnectTreeNodes(pNode3, NULL, pNode4);
    ConnectTreeNodes(pNode4, NULL, pNode5);

    Test("Test5", pNode2, 4);

    DestroyTree(pNode2);
}

//            8
//        10      6
//      11  9   7   5
void Test6()
{
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode11 = CreateBinaryTreeNode(11);
    BinaryTreeNode* pNode9 = CreateBinaryTreeNode(9);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);

    ConnectTreeNodes(pNode8, pNode10, pNode6);
    ConnectTreeNodes(pNode10, pNode11, pNode9);
    ConnectTreeNodes(pNode6, pNode7, pNode5);

    Test("Test6", pNode8, 1);

    DestroyTree(pNode8);
}

void Test7()
{
    Test("Test7", NULL, 0);
}

int main(int agrc, char* argv[])
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