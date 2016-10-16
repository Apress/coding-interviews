// Coding Interviews: Questions, Analysis & Solutions
// Harry He

#include <stdio.h>
#include <list>
#include <vector>

using namespace std;

struct TreeNode 
{
    int                       m_nValue;    
    std::vector<TreeNode*>    m_vChildren;    
};

bool GetNodePath(TreeNode* pRoot, TreeNode* pNode, list<TreeNode*>& path)
{
    if(pRoot == pNode)
        return true;
 
    path.push_back(pRoot);
 
    bool found = false;

    vector<TreeNode*>::iterator i = pRoot->m_vChildren.begin();
    while(!found && i < pRoot->m_vChildren.end())
    {
        found = GetNodePath(*i, pNode, path);
        ++i;
    }
 
    if(!found)
        path.pop_back();
 
    return found;
}

TreeNode* GetLastCommonNode
(
    const list<TreeNode*>& path1, 
    const list<TreeNode*>& path2
)
{
    list<TreeNode*>::const_iterator iterator1 = path1.begin();
    list<TreeNode*>::const_iterator iterator2 = path2.begin();
    
    TreeNode* pLast = NULL;
 
    while(iterator1 != path1.end() && iterator2 != path2.end())
    {
        if(*iterator1 == *iterator2)
            pLast = *iterator1;
 
        iterator1++;
        iterator2++;
    }
 
    return pLast;
}

TreeNode* GetLastCommonParent(TreeNode* pRoot, TreeNode* pNode1, TreeNode* pNode2)
{
    if(pRoot == NULL || pNode1 == NULL || pNode2 == NULL)
        return NULL;
 
    list<TreeNode*> path1;
    GetNodePath(pRoot, pNode1, path1);
 
    list<TreeNode*> path2;
    GetNodePath(pRoot, pNode2, path2);
 
    return GetLastCommonNode(path1, path2);
}

// ==================== Code for Trees ====================
TreeNode* CreateTreeNode(int value)
{
    TreeNode* pNode = new TreeNode();
    pNode->m_nValue = value;

    return pNode;
}

void ConnectTreeNodes(TreeNode* pParent, TreeNode* pChild)
{
    if(pParent != NULL)
    {
        pParent->m_vChildren.push_back(pChild);
    }
}

void PrintTreeNode(TreeNode* pNode)
{
    if(pNode != NULL)
    {
        printf("value of this node is: %d.\n", pNode->m_nValue);

        printf("its children is as the following:\n");
        std::vector<TreeNode*>::iterator i = pNode->m_vChildren.begin();
        while(i < pNode->m_vChildren.end())
        {
            if(*i != NULL)
                printf("%d\t", (*i)->m_nValue);
        }

        printf("\n");
    }
    else
    {
        printf("this node is null.\n");
    }

    printf("\n");
}

void PrintTree(TreeNode* pRoot)
{
    PrintTreeNode(pRoot);

    if(pRoot != NULL)
    {
        std::vector<TreeNode*>::iterator i = pRoot->m_vChildren.begin();
        while(i < pRoot->m_vChildren.end())
        {
            PrintTree(*i);
            ++i;
        }
    }
}

void DestroyTree(TreeNode* pRoot)
{
    if(pRoot != NULL)
    {
        std::vector<TreeNode*>::iterator i = pRoot->m_vChildren.begin();
        while(i < pRoot->m_vChildren.end())
        {
            DestroyTree(*i);
            ++i;
        }

        delete pRoot;
    }
}

// ==================== Test Code ====================

void Test(char* testName, TreeNode* pRoot, TreeNode* pNode1, TreeNode* pNode2, TreeNode* pExpected)
{
    if(testName != NULL)
        printf("%s begins: \n", testName);

    TreeNode* pResult = GetLastCommonParent(pRoot, pNode1, pNode2);

    if((pExpected == NULL && pResult == NULL) || 
        (pExpected != NULL && pResult != NULL && pResult->m_nValue == pExpected->m_nValue))
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

//              1
//            /   \
//           2     3
//       /       \
//      4         5
//     / \      / |  \
//    6   7    8  9  10
void Test1()
{
    TreeNode* pNode1 = CreateTreeNode(1);
    TreeNode* pNode2 = CreateTreeNode(2);
    TreeNode* pNode3 = CreateTreeNode(3);
    TreeNode* pNode4 = CreateTreeNode(4);
    TreeNode* pNode5 = CreateTreeNode(5);
    TreeNode* pNode6 = CreateTreeNode(6);
    TreeNode* pNode7 = CreateTreeNode(7);
    TreeNode* pNode8 = CreateTreeNode(8);
    TreeNode* pNode9 = CreateTreeNode(9);
    TreeNode* pNode10 = CreateTreeNode(10);

    ConnectTreeNodes(pNode1, pNode2);
    ConnectTreeNodes(pNode1, pNode3);

    ConnectTreeNodes(pNode2, pNode4);
    ConnectTreeNodes(pNode2, pNode5);

    ConnectTreeNodes(pNode4, pNode6);
    ConnectTreeNodes(pNode4, pNode7);

    ConnectTreeNodes(pNode5, pNode8);
    ConnectTreeNodes(pNode5, pNode9);
    ConnectTreeNodes(pNode5, pNode10);

    Test("Test1", pNode1, pNode6, pNode8, pNode2);
    
    DestroyTree(pNode1);
}

//              1
//            /   \
//           2     3
//       /       \
//      4         5
//     / \      / |  \
//    6   7    8  9  10
void Test2()
{
    TreeNode* pNode1 = CreateTreeNode(1);
    TreeNode* pNode2 = CreateTreeNode(2);
    TreeNode* pNode3 = CreateTreeNode(3);
    TreeNode* pNode4 = CreateTreeNode(4);
    TreeNode* pNode5 = CreateTreeNode(5);
    TreeNode* pNode6 = CreateTreeNode(6);
    TreeNode* pNode7 = CreateTreeNode(7);
    TreeNode* pNode8 = CreateTreeNode(8);
    TreeNode* pNode9 = CreateTreeNode(9);
    TreeNode* pNode10 = CreateTreeNode(10);

    ConnectTreeNodes(pNode1, pNode2);
    ConnectTreeNodes(pNode1, pNode3);

    ConnectTreeNodes(pNode2, pNode4);
    ConnectTreeNodes(pNode2, pNode5);

    ConnectTreeNodes(pNode4, pNode6);
    ConnectTreeNodes(pNode4, pNode7);

    ConnectTreeNodes(pNode5, pNode8);
    ConnectTreeNodes(pNode5, pNode9);
    ConnectTreeNodes(pNode5, pNode10);

    Test("Test2", pNode1, pNode7, pNode3, pNode1);
    
    DestroyTree(pNode1);
}

//               1
//              /
//             2
//            /
//           3
//          /
//         4
//        /
//       5
void Test3()
{
    TreeNode* pNode1 = CreateTreeNode(1);
    TreeNode* pNode2 = CreateTreeNode(2);
    TreeNode* pNode3 = CreateTreeNode(3);
    TreeNode* pNode4 = CreateTreeNode(4);
    TreeNode* pNode5 = CreateTreeNode(5);

    ConnectTreeNodes(pNode1, pNode2);
    ConnectTreeNodes(pNode2, pNode3);
    ConnectTreeNodes(pNode3, pNode4);
    ConnectTreeNodes(pNode4, pNode5);

    Test("Test3", pNode1, pNode5, pNode4, pNode3);
    DestroyTree(pNode1);
}

//               1
//              /
//             2
//            /
//           3
//          /
//         4
//        /
//       5
void Test4()
{
    TreeNode* pNode1 = CreateTreeNode(1);
    TreeNode* pNode2 = CreateTreeNode(2);
    TreeNode* pNode3 = CreateTreeNode(3);
    TreeNode* pNode4 = CreateTreeNode(4);
    TreeNode* pNode5 = CreateTreeNode(5);

    ConnectTreeNodes(pNode1, pNode2);
    ConnectTreeNodes(pNode2, pNode3);
    ConnectTreeNodes(pNode3, pNode4);
    ConnectTreeNodes(pNode4, pNode5);

    // pNode6 is not in the tree
    TreeNode* pNode6 = CreateTreeNode(6);

    Test("Test4", pNode1, pNode5, pNode6, NULL);
    DestroyTree(pNode1);
    DestroyTree(pNode6);
}

// Empty Tree
void Test5()
{
    Test("Test5", NULL, NULL, NULL, NULL);
}

//               1
//              /
//             2
//            /
//           3
//          /
//         4
//        /
//       5
void Test6()
{
    TreeNode* pNode1 = CreateTreeNode(1);
    TreeNode* pNode2 = CreateTreeNode(2);
    TreeNode* pNode3 = CreateTreeNode(3);
    TreeNode* pNode4 = CreateTreeNode(4);
    TreeNode* pNode5 = CreateTreeNode(5);

    ConnectTreeNodes(pNode1, pNode2);
    ConnectTreeNodes(pNode2, pNode3);
    ConnectTreeNodes(pNode3, pNode4);
    ConnectTreeNodes(pNode4, pNode5);

    Test("Test6", pNode1, pNode5, pNode1, NULL);
    DestroyTree(pNode1);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();

    return 0;
}

