#include<iostream>
#include <stack>
using namespace std;

struct BinaryTreeNode
{
    int					m_nValue;
    BinaryTreeNode*		m_pLeft;
    BinaryTreeNode*		m_pRight;
};

BinaryTreeNode* ContructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder);

BinaryTreeNode* Construct(int* preorder, int* inorder, int length)
{
    // 写函数先判断参数是否合法
    if (preorder == NULL || inorder == NULL || length <= 0)
    {
        return NULL;
    }
    
    return ContructCore(preorder, preorder+length-1, inorder, inorder+length-1);
}

BinaryTreeNode* ContructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder)
{
    int rootValue = startPreorder[0];
    BinaryTreeNode* root = new BinaryTreeNode();
    root->m_nValue = rootValue;
    root->m_pLeft = NULL;
    root->m_pRight = NULL;
    
    if (startPreorder == endPreorder)
    {
        if (startInorder == endInorder && *startPreorder == *endPreorder)
        {
            return root;
        }
        else
            throw exception();
    }
    
    int* rootInorder = startInorder;
    while (rootInorder <= endInorder && *rootInorder != *endInorder)
    {
        rootInorder++;
    }
    
    if (rootInorder == endInorder && *rootInorder != rootValue)
    {
        throw exception();
    }
    
    int leftLength = rootInorder - startInorder;
    int* leftPreorderEnd = startPreorder + leftLength;
    
    // 构建左子树
    if (leftLength > 0)
    {
        root->m_pLeft = ContructCore(startPreorder+1, leftPreorderEnd, startInorder, rootInorder-1);
    }
    
    
    // 构建右子树
    if (leftLength < endPreorder - startPreorder)
    {
        root->m_pRight = ContructCore(leftPreorderEnd+1, endPreorder, rootInorder+1, endInorder);
    }
    
    return root;
    
}
