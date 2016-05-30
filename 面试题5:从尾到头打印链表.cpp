#include<iostream>
#include <stack>
using namespace std;

struct ListNode
{
    int m_nKey;
    ListNode* m_pNext;
};

void PrintListReversingly_Iteratively(ListNode* pHead)
{
    std::stack<ListNode*> nodes;
    
    ListNode* pNode = pHead;
    while (pNode != NULL)
    {
        nodes.push(pNode);
        
        pNode = pNode->m_pNext;
    }
    
    while (!nodes.empty())
    {
        pNode = nodes.top();
        printf("%d\t", pNode->m_nKey);
        nodes.pop();
    }
    
}